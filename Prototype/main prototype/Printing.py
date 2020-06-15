from PyQt5 import QtWidgets, QtCore, QtPrintSupport, QtGui
from PyQt5.QtGui import QPainter
 

def printing(tab):
    rows = len(tab.layers)
    tableinput = QtWidgets.QTableWidget(rows+1,5)
    tableoutput = QtWidgets.QTableWidget(rows+2,3)
    printer = QtPrintSupport.QPrinter(QtPrintSupport.QPrinter.HighResolution)
    printer.setPageMargins(12,16,12,20, QtPrintSupport.QPrinter.Millimeter)
    printer.setFullPage(False)
    painter = QPainter(printer)
    dialog = QtPrintSupport.QPrintDialog()
    i=0
    for layer in tab.layers:
        item = []
        item.append(QtWidgets.QTableWidgetItem("%d" % i))
        item.append(QtWidgets.QTableWidgetItem("%s" % layer.mat))
        item.append(QtWidgets.QTableWidgetItem("%f" % layer.width))
        item.append(QtWidgets.QTableWidgetItem("%f" % layer.lambda_))
        item.append(QtWidgets.QTableWidgetItem("%f" % layer.rho))
        for x in range(5):
            item[x].setTextAlignment(QtCore.Qt.AlignCenter)
            tableinput.setItem(i,x,item[x])
        i+=1
    tableinput.setHorizontalHeaderLabels(
            'Nr. der Schicht|Bezeichnung|Dicke in M|Wärmeleitfähigkeit in Wm<sup>-1</sup>K<sup>-1</sup>|Wärmedurchlasswiderstand in m<sup>2</sup>KW<sup>-1</sup>'.split('|'))

    for row in range(tableoutput.rowCount()):
            for col in range(tableoutput.columnCount()):
                item = QtWidgets.QTableWidgetItem('(%d, %d)' % (row, col))
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                tableoutput.setItem(row, col, item)
    tableinput.setHorizontalHeaderLabels(
        'k/I|Grenzfläche|T<sub>k/I</sub> in °C'.split('|'))

    if dialog.exec_() == QtWidgets.QDialog.Accepted:
        table_format = QtGui.QTextTableFormat()
        table_format.setWidth(450)
        document = QtGui.QTextDocument()
        cursor = QtGui.QTextCursor(document)
        cursor.MoveOperation(1)
        cursor.insertHtml("<h1>Bezeichnung der Konstruktion: %s</h1><br><br>" % (str(tab.name)))
        cursor.insertHtml("<h2>Material- und Konstruktionsdaten:</h2><br>")
        table = cursor.insertTable(
            tableinput.rowCount(), tableinput.columnCount(), table_format)
        for row in range(table.rows()):
            for col in range(table.columns()):
                cursor.insertText(tableinput.item(row, col).text())
                cursor.movePosition(QtGui.QTextCursor.NextCell)
        cursor.movePosition(16)
        cursor.insertHtml("<br><div> Innenlufttemperatur: T<sub>i</sub> = %s<br>" %str(tab.tleft))
        cursor.insertHtml("<br><div> Außentemperatur: T<sub>e</sub> = %s <br>" %str(tab.tright))
        cursor.insertHtml("<br><div> Wärmeübergangswiderstand auf der Innenseite: R<sub>si</sub> = %s<br>" %str(tab.rleft))
        cursor.insertHtml("<br><div> Wärmeübergangswiderstand auf der Außenseite: R<sub>se</sub> = %s<br>" %str(tab.rright))
        cursor.insertHtml("<br><div> Wärmedurchlasswiderstand : R<sub>ges</sub> = %s<br>" %str(tab.rsum))
        cursor.insertHtml("<br><div> Wärmedurchgangswiderstand : R<sub>T</sub> = %s<br>" %str(tab.rt))
        cursor.insertHtml("<br><div> Wärmedurchgangskoeffizient : U = %s<br>" %str(tab.u))
        cursor.insertHtml("<br><h2>Temperaturen an den Grenzflächen</h2><br>")
        table2 = cursor.insertTable(
            tableoutput.rowCount(), tableoutput.columnCount(), table_format)
        for row in range(table2.rows()):
            for col in range(table2.columns()):
                cursor.insertText(tableoutput.item(row, col).text())
                cursor.movePosition(QtGui.QTextCursor.NextCell)
        document.print_(printer)
    """
    if tab.mode == 0:
        #RWIDGET
    else:
        #TEMPWIDGET
        pass
        data = ""
        data += "name: " + self.tab.name + "\n"
        data += "rright: " + self.tab.rright + "\n"
        data += "rleft: " + self.tab.rleft + "\n"
        data += "rsum: " + self.tab.rsum + "\n"
        data += "tright: " + self.tab.tright + "\n"
        data += "tleft: " + self.tab.tleft + "\n"
        data += "mode: " + self.tab.mode + "\n"
        data += "u: " + self.tab.u + "\n"
        data += "rt: " + self.tab.rt + "\n"

        layers = "layers:\n"

        for layer in self.tab.layers:
            layers += "\tlayer: "
            layers += layer.width + ", "
            layers += layer.widthUnit + ", "
            layers += layer.lambda_ + ", "
            layers += layer.r + ", "
            layers += layer.t_left + ", "
            layers += layer.t_right + ", "
            layers += layer.rho + ", "
            layers += layer.mat + "\n"
"""

        