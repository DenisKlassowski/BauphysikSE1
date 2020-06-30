# This Python file uses the following encoding: utf-8
import sys
from PyQt5 import QtGui
from PyQt5.QtWidgets import  QApplication, QMainWindow, QDesktopWidget
from master import MainWindow


def main():
    app=QApplication(sys.argv)
    f = app.font()
    f.setPointSize(12)
    app.setFont(f)
    path = pathlib.Path(__file__).parent.absolute()
    window = MainWindow()
    window.setWindowIcon(QtGui.QIcon(str(path)+"/BauphysikLogo02.png"))
    window.setWindowTitle("Bauphysik")
    window.resize(1000,600)

    sys.exit(app.exec_())


if __name__ == "__main__":
    main()

