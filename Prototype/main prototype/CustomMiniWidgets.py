# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, QtCore, QtGui


class QHLine(QtWidgets.QFrame):
    """horizontal line used for dividers"""
    def __init__(self):
        QtWidgets.QFrame.__init__(self)
        self.setFrameShape(QtWidgets.QFrame.HLine)
        self.setFrameShadow(QtWidgets.QFrame.Sunken)

        """
        self.setStyleSheet("QFrame{"
        "background-color: #12499A;"
        "};")
        """

class MyDoubleSpinBox(QtWidgets.QDoubleSpinBox):
    """overriden DoubleSpinBox"""
    def __init__(self):
        QtWidgets.QDoubleSpinBox.__init__(self)
        self.setAccelerated(1)
        self.setFocusPolicy(QtCore.Qt.StrongFocus)
        self.setDecimals(3)
        self.setMaximumWidth(100)
        """
        self.setStyleSheet("QDoubleSpinBox{"
        "border: 1px solid #000000"
        "};")
        """

    #overriding scroll events to disable value changes when simply scrolling through e.g. scrollAreas
    def wheelEvent(self, e):
        """overriden wheelEvent to disable value changes when simply scrolling through e.g. scrollAreas"""
        if(self.hasFocus()):
            QtWidgets.QDoubleSpinBox.wheelEvent(self,e)
        else:
            pass

    def setEditable(self, bool):
        """makes boxes ineditable by user but still editable by software"""
        if bool == 0:

            self.setReadOnly(True)
            self.setButtonSymbols(self.NoButtons)
            self.setBackGroundColor(QtGui.QColor(240,240,240))
        else:
            self.setReadOnly(False)
            self.setButtonSymbols(self.UpDownArrows)
            self.setBackGroundColor(QtGui.QColor(255,255,255))

    def setBackGroundColor(self, color):
        self.setAutoFillBackground(1)
        pal = self.lineEdit().palette()
        pal.setColor(self.lineEdit().backgroundRole(), color)
        self.lineEdit().setPalette(pal)



class MyComboBox(QtWidgets.QComboBox):
    def __init__(self):
        QtWidgets.QComboBox.__init__(self)
        self.setFocusPolicy(QtCore.Qt.StrongFocus)

    def wheelEvent(self, e):
        """overriden wheelEvent to disable value changes when simply scrolling through e.g. scrollAreas"""
        if(self.hasFocus()):
            QtWidgets.QComboBox.wheelEvent(self,e)
        else:
            pass
