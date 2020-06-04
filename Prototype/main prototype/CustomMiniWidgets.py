# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, QtCore, QtGui


class QHLine(QtWidgets.QFrame):
    def __init__(self):
        QtWidgets.QFrame.__init__(self)
        self.setFrameShape(QtWidgets.QFrame.HLine)
        self.setFrameShadow(QtWidgets.QFrame.Sunken)

class MyDoubleSpinBox(QtWidgets.QDoubleSpinBox):
    def __init__(self):
        QtWidgets.QDoubleSpinBox.__init__(self)
        self.setAccelerated(1)
        self.setFocusPolicy(QtCore.Qt.StrongFocus)
        self.setDecimals(3)
        self.setMaximumWidth(100)

    #overriding scroll events to disable value changes when simply scrolling through e.g. scrollAreas
    def wheelEvent(self, e):
        if(self.hasFocus()):
            QtWidgets.QDoubleSpinBox.wheelEvent(self,e)
        else:
            pass

    def setEditable(self, bool):
        if bool == 0:
            self.setReadOnly(True)
            pal = self.lineEdit().palette()
            pal.setColor(self.lineEdit().backgroundRole(), QtGui.QColor(240,240,240))
            self.setAutoFillBackground(1)
            self.setButtonSymbols(self.NoButtons)
            self.lineEdit().setPalette(pal)
        else:
            self.setReadOnly(False)
            pal = self.lineEdit().palette()
            pal.setColor(self.lineEdit().backgroundRole(), QtGui.QColor(255,255,255))
            self.setAutoFillBackground(1)
            self.setButtonSymbols(self.UpDownArrows)
            self.lineEdit().setPalette(pal)
