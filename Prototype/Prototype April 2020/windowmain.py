# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, uic
import sys
from master import Ui_MainWindow

class windowmain(QtWidgets.QMainWindow):
    def __init__(self):
        super(windowmain,self).__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)
        #uic.loadUi('master.ui', self) # Load the .ui file
        self.show() # show the GUI


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = windowmain()
    app.exec_()
