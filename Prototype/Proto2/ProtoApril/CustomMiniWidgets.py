# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets


class QHLine(QtWidgets.QFrame):
    def __init__(self):
        QtWidgets.QFrame.__init__(self)
        self.setFrameShape(QtWidgets.QFrame.HLine)
        self.setFrameShadow(QtWidgets.QFrame.Sunken)

