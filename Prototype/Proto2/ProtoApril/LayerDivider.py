# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets
from CustomMiniWidgets import QHLine


class LayerDivider(QtWidgets.QWidget):
    def __init__(self,mode):
        QtWidgets.QWidget.__init__(self)
        self.mode=mode

        #layout
        self.divLayout = QtWidgets.QGridLayout()
        self.divLayout.setContentsMargins(0,0,0,0)
        self.divLayout.setSpacing(0)

        #those beatiful horizontal lines
        self.leftLine = QHLine()
        self.rightLine = QHLine()

        #temperature, can be replaced by a widget where further information could be added
        self.tempLabel = QtWidgets.QLabel("°C")
        self.tempLabel.setAlignment(QtCore.Qt.AlignCenter)
        self.tempLabel.setFixedWidth(100)

        #assemble layout
        self.divLayout.addWidget(self.leftLine,0,0)
        self.divLayout.addWidget(self.tempLabel,0,1)
        self.divLayout.addWidget(self.rightLine,0,2)

        self.setLayout(self.divLayout)

        #modify display to correct mode
        self.switchMode(self.mode)

    def switchMode(self,mode):
        self.mode = mode
        if (mode==0):
            self.tempLabel.hide()
        else:
            self.tempLabel.show()


