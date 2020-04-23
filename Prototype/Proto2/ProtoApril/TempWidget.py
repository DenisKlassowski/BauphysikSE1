# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets


class TempWidget(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)

        tempLayout = QtWidgets.QGridLayout()
        tempLayout.setContentsMargins(0,0,0,0)
        tempLayout.setSpacing(20)

        self.tempTitleLabel = QtWidgets.QLabel()
        self.tempInsideLabel = QtWidgets.QLabel()
        self.tempOutsideLabel = QtWidgets.QLabel()

        self.tempOutsideDoubleSpinBox = QtWidgets.QDoubleSpinBox()
        self.tempInsideDoubleSpinBox = QtWidgets.QDoubleSpinBox()

        self.tempCelsiusLabel1 = QtWidgets.QLabel()
        self.tempCelsiusLabel2 = QtWidgets.QLabel()

        tempLayout.addWidget(self.tempTitleLabel,0,0)
        tempLayout.addWidget(self.tempOutsideLabel,0,1)
        tempLayout.addWidget(self.tempInsideLabel,1,1)

        tempLayout.addWidget(self.tempOutsideDoubleSpinBox, 0,2)
        tempLayout.addWidget(self.tempInsideDoubleSpinBox, 1,2)

        tempLayout.addWidget(self.tempCelsiusLabel1,0,3)
        tempLayout.addWidget(self.tempCelsiusLabel2,1,3)


        self.setLayout(tempLayout)
        self.retranslateUi()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.tempTitleLabel.setText(_translate("TempWidget", "Temperatur"))
        self.tempInsideLabel.setText(_translate("TempWidget", "innen:"))
        self.tempOutsideLabel.setText(_translate("TempWidget", "außen:"))
        self.tempCelsiusLabel1.setText(_translate("TempWidget", "°C"))
        self.tempCelsiusLabel2.setText(_translate("TempWidget", "°C"))
