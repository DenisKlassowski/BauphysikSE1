# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, QtCore


class QHLine(QtWidgets.QFrame):
    def __init__(self):
        QtWidgets.QFrame.__init__(self)
        self.setFrameShape(QtWidgets.QFrame.HLine)
        self.setFrameShadow(QtWidgets.QFrame.Sunken)

class MyDoubleSpinBox(QtWidgets.QDoubleSpinBox):
    def __init__(self):
        QtWidgets.QDoubleSpinBox.__init__(self)
        self.setFocusPolicy(QtCore.Qt.StrongFocus)

    #overriding scroll events to disable value changes when simply scrolling through e.g. scrollAreas
    def wheelEvent(self, e):
        if(self.hasFocus()):
            QtWidgets.QDoubleSpinBox.wheelEvent(self,e)
        else:
            pass
