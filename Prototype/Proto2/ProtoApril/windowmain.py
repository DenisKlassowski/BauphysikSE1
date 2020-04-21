# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, uic, QtCore, QtGui
from PyQt5.QtWidgets import QApplication, QMainWindow
from master import Ui_MainWindow
from Widgets.LayerWidget import Ui_LayerWidget
import sys


class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow,self).__init__()
        self.ui=Ui_MainWindow()
        self.ui.setupUi(self)

        self.show() # show the GUI
        self.ui.AddLayerButton.clicked.connect(self.addLayer)

    def addLayer(self):
        self.ui.AddLayerButton.setText('clicked')
        self.LayerWidget= Ui_LayerWidget()
        self.LayerWidget.setupUi(self.ui.scrollAreaWidgetContents_2)

        print('bla')


def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.setWindowTitle("Prototype April")
    sys.exit(app.exec_())

if __name__ == "__main__":
   main()


#self.WidgetLayer1 = Ui_LayerWidget()
#self.WidgetLayer1.setupUi(self.scrollAreaWidgetContents_2)
