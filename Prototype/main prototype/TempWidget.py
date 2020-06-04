# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets
from CustomMiniWidgets import MyDoubleSpinBox


class TempWidget(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)

        #layout
        tempLayout = QtWidgets.QGridLayout()
        tempLayout.setContentsMargins(0,0,0,0)
        tempLayout.setSpacing(20)

        self.tempTitleLabel = QtWidgets.QLabel()
        self.tempInsideLabel = QtWidgets.QLabel()
        self.tempOutsideLabel = QtWidgets.QLabel()

        #hard coded solution for spinbox size, could be done better?
        self.tempOutsideDoubleSpinBox = MyDoubleSpinBox()
        self.tempOutsideDoubleSpinBox.setMaximum(1000)
        self.tempOutsideDoubleSpinBox.setMinimum(-273.15)
        self.tempOutsideDoubleSpinBox.setDecimals(2)
        self.tempOutsideDoubleSpinBox.setMaximumWidth(92)
        self.tempOutsideDoubleSpinBox.setMinimumWidth(92)

        #hard coded solution for spinbox size, could be done better?
        self.tempInsideDoubleSpinBox = MyDoubleSpinBox()
        self.tempInsideDoubleSpinBox.setMaximum(1000)
        self.tempInsideDoubleSpinBox.setMinimum(-273.15)
        self.tempInsideDoubleSpinBox.setDecimals(2)
        self.tempInsideDoubleSpinBox.setMaximumWidth(92)
        self.tempInsideDoubleSpinBox.setMinimumWidth(92)

        self.tempCelsiusLabel1 = QtWidgets.QLabel()
        self.tempCelsiusLabel2 = QtWidgets.QLabel()

        #assemble layout
        tempLayout.addWidget(self.tempTitleLabel,0,0)
        tempLayout.addWidget(self.tempOutsideLabel,0,1)
        tempLayout.addWidget(self.tempInsideLabel,1,1)

        tempLayout.addWidget(self.tempCelsiusLabel1,0,3)
        tempLayout.addWidget(self.tempCelsiusLabel2,1,3)

        tempLayout.addWidget(self.tempOutsideDoubleSpinBox, 0,2)
        tempLayout.addWidget(self.tempInsideDoubleSpinBox, 1,2)

        self.setLayout(tempLayout)

        self.retranslateUi()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.tempTitleLabel.setText(_translate("TempWidget", "Temp"))
        self.tempInsideLabel.setText(_translate("TempWidget", "innen:"))
        self.tempOutsideLabel.setText(_translate("TempWidget", "außen:"))
        self.tempCelsiusLabel1.setText(_translate("TempWidget", "°C"))
        self.tempCelsiusLabel2.setText(_translate("TempWidget", "°C"))

    def setData(self, tin, tout):
        self.tempInsideDoubleSpinBox.setValue(tin)
        self.tempOutsideDoubleSpinBox.setValue(tout)

