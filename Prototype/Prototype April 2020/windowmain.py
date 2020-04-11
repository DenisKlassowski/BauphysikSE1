# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, uic
import sys


class windowmain(QtWidgets.QMainWindow):
    def __init__(self):
        super(windowmain,self).__init__()
        uic.loadUi('master.ui', self) # Load the .ui file
        self.show() # show the GUI


if __name__ == "__main__":
    app = QtWidgets.QApplication(sys.argv)
    window = windowmain()
    app.exec_()
