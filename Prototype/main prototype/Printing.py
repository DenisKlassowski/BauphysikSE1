from PyQt5 import QtWidgets, QtCore, QtPrintSupport, QtGui
from PyQt5.QtGui import QPainter
from PyQt5.QtWidgets import QApplication
import sys
from Tab import Tab

class Print(QtWidgets.QWidget):
    """
    Printing class 
    """
    def __init__(self,tab):
        """
        Print class init:
        create tables based on Contents QTableWidgetItem.text() 
        """
        QtWidgets.QWidget.__init__(self)
        self.setWindowTitle(self.tr('Drucken von Berechnungen'))
        rows = len(tab.data.layers)
        #get data from calling tab
        self.tab = tab
        #create the input/output tables
        self.tableinput = QtWidgets.QTableWidget(rows,5,self)
        self.tableoutput = QtWidgets.QTableWidget(rows,3,self)
        #set printer setting dynamically
        self.printer = QtPrintSupport.QPrinter(QtPrintSupport.QPrinter.PrinterResolution)
        self.printer.setPageMargins(12,16,12,20, QtPrintSupport.QPrinter.Millimeter)
        self.printer.setFullPage(True)
        self.printer.setPageSize(QtPrintSupport.QPrinter.A4)
        #needed for rounding numbers
        self.cLocale = QtCore.QLocale()
        i=0
        for layer in tab.data.layers:
            #temo array = 1 row in table
            item = []
            item.append(QtWidgets.QTableWidgetItem("{}".format(i+1)))
            item.append(QtWidgets.QTableWidgetItem("{}".format(layer.mat)))
            item.append(QtWidgets.QTableWidgetItem("{}".format(layer.width)))
            item.append(QtWidgets.QTableWidgetItem(self.cLocale.toString(round(layer.lambda_,2),'f',2)))
            item.append(QtWidgets.QTableWidgetItem(self.cLocale.toString(round(layer.rho,2),'f',2)))
            for x in range(5):
                #set data to PyQt table object defined above
                item[x].setTextAlignment(QtCore.Qt.AlignCenter)
                self.tableinput.setItem(i,x,item[x])
            i+=1
        self.tableinputHorizontalHeaderLabels ='Nr. der Schicht|Bezeichnung|Dicke in M|Wärmeleitfähigkeit in Wm<sup>-1</sup>K<sup>-1</sup>|Wärmedurchlasswiderstand in m<sup>2</sup>KW<sup>-1</sup>'.split('|')
        i=0
        for layer in range (len(self.tab.data.layers)):
            #same as above but for output table
            item=[]
            if layer == 0:
                item.append(QtWidgets.QTableWidgetItem("i/%d" % (layer+1)))
            else:
                try:
                    item.append(QtWidgets.QTableWidgetItem("%d/%d" % (layer,layer+1)))
                except:
                    item.append(QtWidgets.QTableWidgetItem("0/0"))
            try:
                print("printing mat")
                print(self.tab.data.layers[layer].mat)
                item.append(QtWidgets.QTableWidgetItem("{}/{}".format((self.tab.data.layers[layer].mat,tab.data.layers[layer+1].mat))))
            except:
                item.append(QtWidgets.QTableWidgetItem("..."))
            try:
                item.append(QtWidgets.QTableWidgetItem(self.cLocale.toString(round(self.tab.data.layers[layer].t_left,2),'f',2)))
                #item.append(QtWidgets.QTableWidgetItem("{}".format(self.tab.data.layers[layer].t_left)))
            except:
                item.append(QtWidgets.QTableWidgetItem("Keine Temperatur vorhanden"))
            for x in range(3):
                self.tableoutput.setItem(i,x,item[x])
            i+=1
        self.tableoutputHorizontalHeaderLabels='k/I|Grenzfläche|T<sub>k/I</sub> in °C'.split('|')
        #Now we have 2 new tables based on data

    def handlePrint(self):
        """
        Print method
        """
        #is unused as of now but could be connected if its needed (direct printing)
        dialog = QtPrintSupport.QPrintDialog()
        if dialog.exec_() == QtWidgets.QDialog.Accepted:
            #if accepted do printing 
            self.handlePaintRequest(dialog.printer())

    def handlePreview(self):
        """
        Print preview window method
        """
        dialog = QtPrintSupport.QPrintPreviewDialog()
        rec = QApplication.desktop().screenGeometry()
        #resize dialog dynamically
        dialog.resize(0.8*(rec.width()),0.8*(rec.height()))
        #if user wants to print, call handlePaintRequest
        dialog.paintRequested.connect(self.handlePaintRequest)
        dialog.exec_()

    def handlePaintRequest(self,printer):
        """
        Paint print document method
        """
        #set table format based on page size
        table_format = QtGui.QTextTableFormat()
        table_format.setWidth(int(printer.pageRect().width())-int(0.2*(printer.pageRect().width())))
        #init document that will be filled with data
        document = QtGui.QTextDocument()
        #document.setDocumentMargin(100)
        #document.setPageSize(QtCore.QSizeF(printer.pageRect().width))
        #print preview
        dialog = QtPrintSupport.QPrintPreviewDialog()
        #cursor is used to insert into document
        cursor = QtGui.QTextCursor(document)
        #move to start
        cursor.MoveOperation(1)
        #insert data as HTML
        cursor.insertHtml("<h1>Bezeichnung der Konstruktion: %s</h1>" % (str(self.tab.data.name)))
        cursor.insertHtml("<br><h2>Material- und Konstruktionsdaten:</h2>")
        #insert table (empty)
        table = cursor.insertTable(
            (self.tableinput.rowCount()+1), self.tableinput.columnCount(), table_format)
        #fill table
        for row in range(table.rows()):
            for col in range(table.columns()):
                if row == 0:
                    cursor.insertHtml("<b>"+str(self.tableinputHorizontalHeaderLabels[col])+"</b>")
                else:
                    if self.tableinput.item(row-1, col) is None:
                        cursor.insertText("0")
                    else:
                        try:
                            self.tableinput.item(row-1,col).setTextAlignment(QtCore.Qt.AlignCenter)
                            cursor.insertText(self.tableinput.item(row-1, col).text())
                        except:
                            cursor.insertText("NONETYPE")
                cursor.movePosition(QtGui.QTextCursor.NextCell)
        #move to next pos and fill document with data in HTML
        cursor.movePosition(16)
        cursor.insertHtml("<br><div> Innenlufttemperatur: T<sub>i</sub> = %s °C" %str(self.tab.data.tleft))
        cursor.insertHtml("<br><div> Außentemperatur: T<sub>e</sub> = %s °C" %str(self.tab.data.tright))
        cursor.insertHtml("<br><div> Wärmeübergangswiderstand auf der Innenseite: R<sub>si</sub> = {} m<sup>2</sup>KW<sup>-1</sup>".format(self.cLocale.toString(round(self.tab.data.rleft,2),'f',2)))
        cursor.insertHtml("<br><div> Wärmeübergangswiderstand auf der Außenseite: R<sub>se</sub> = {} m<sup>2</sup>KW<sup>-1</sup>".format(self.cLocale.toString(round(self.tab.data.rright,2),'f',2)))
        cursor.insertHtml("<br><div> Wärmedurchlasswiderstand : R<sub>ges</sub> = {} m<sup>2</sup>KW<sup>-1</sup>".format(self.cLocale.toString(round(self.tab.data.rsum,2),'f',2)))
        cursor.insertHtml("<br><div> Wärmedurchgangswiderstand : R<sub>T</sub> = {} m<sup>2</sup>KW<sup>-1</sup>".format(self.cLocale.toString(round(self.tab.data.rt,2),'f',2)))
        cursor.insertHtml("<br><div> Wärmedurchgangskoeffizient : U = {} Wm<sup>-2</sup>K<sup>-1</sup><br>".format(self.cLocale.toString(round(self.tab.data.u,2),'f',2)))
        cursor.insertHtml("<h2>Temperaturen an den Grenzflächen:</h2>")
        table2 = cursor.insertTable(
            self.tableoutput.rowCount()+1, self.tableoutput.columnCount(), table_format)
        #insert second table
        for row in range(table2.rows()):
            for col in range(table2.columns()):
                if row == 0:
                    cursor.insertHtml("<b>"+str(self.tableoutputHorizontalHeaderLabels[col])+"</b>")
                else:
                    try:
                        cursor.insertText(self.tableoutput.item(row-1, col).text())
                    except:
                        pass
                cursor.movePosition(QtGui.QTextCursor.NextCell)
        cursor.setPosition((cursor.position()+1))
        #insert image from visualizewidget.getimage() (Bytestream jpg)
        img = self.tab.visualizeWidget.getImage()
        if img is not None:
            cursor.insertImage(img)
        else:
            print("is none")
        #connect to printer
        document.print_(printer)


