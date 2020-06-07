# This Python file uses the following encoding: utf-8
import sys
from PyQt5 import QtGui
from PyQt5.QtWidgets import  QApplication, QMainWindow
from master import MainWindow


def main():
    app=QApplication(sys.argv)
    f = app.font()
    f.setPointSize(12)
    app.setFont(f)
    window = MainWindow()
    window.setWindowIcon(QtGui.QIcon(":/BauphysikLogo02.png"))
    window.setWindowTitle("Bauphysik")

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()

