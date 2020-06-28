from PyQt5 import QtWidgets, QtCore, QtPrintSupport, QtGui

class Window(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        self.setWindowTitle(self.tr('ProtoDrucken'))
        self.table = QtWidgets.QTableWidget(5, 10, self)

        for row in range(self.table.rowCount()):
            for col in range(self.table.columnCount()):
                item = QtWidgets.QTableWidgetItem('(%d, %d)' % (row, col))
                item.setTextAlignment(QtCore.Qt.AlignCenter)
                self.table.setItem(row, col, item)
        self.table.setHorizontalHeaderLabels(
            'Spalte1|Spalte2|Spalte3|Spalte4|Spalte5'.split('|'))
        self.buttonPrint = QtWidgets.QPushButton('Drucken', self)
        self.buttonPrint.clicked.connect(self.handlePrint)
        self.buttonPreview = QtWidgets.QPushButton('Druckvorschau', self)
        self.buttonPreview.clicked.connect(self.handlePreview)
        layout = QtWidgets.QGridLayout(self)
        layout.addWidget(self.table, 0, 0, 1, 2)
        layout.addWidget(self.buttonPrint, 1, 0)
        layout.addWidget(self.buttonPreview, 1, 1)

    def handlePrint(self):
        dialog = QtPrintSupport.QPrintDialog()
        if dialog.exec_() == QtWidgets.QDialog.Accepted:
            self.handlePaintRequest(dialog.printer())

    def handlePreview(self):
        dialog = QtPrintSupport.QPrintPreviewDialog()
        dialog.paintRequested.connect(self.handlePaintRequest)
        dialog.exec_()

    def handlePaintRequest(self, printer):
        table_format = QtGui.QTextTableFormat()
        table_format.setWidth(450)
        document = QtGui.QTextDocument()
        cursor = QtGui.QTextCursor(document)
        cursor.MoveOperation(1)
        cursor.insertHtml("<h1>Bezeichnung der Konstruktion</h1><br><br>")
        cursor.insertHtml("<h2>Eingangsdaten</h2><br>")
        table = cursor.insertTable(
            self.table.rowCount(), self.table.columnCount(), table_format)
        for row in range(table.rows()):
            for col in range(table.columns()):
                cursor.insertText(self.table.item(row, col).text())
                cursor.movePosition(QtGui.QTextCursor.NextCell)
        cursor.movePosition(16)
        cursor.insertHtml("<br><h2>Materialdaten</h2><br>")
        table2 = cursor.insertTable(
            self.table.rowCount(), self.table.columnCount(), table_format)
        for row in range(table2.rows()):
            for col in range(table2.columns()):
                cursor.insertText(self.table.item(row, col).text())
                cursor.movePosition(QtGui.QTextCursor.NextCell)
        document.print_(printer)

if __name__ == '__main__':

    import sys
    app = QtWidgets.QApplication(sys.argv)
    window = Window()
    window.resize(640, 480)
    window.show()
    sys.exit(app.exec_())