# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets


class RWidget(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)

        rLayout = QtWidgets.QGridLayout()
        rLayout.setContentsMargins(0,0,0,0)
        rLayout.setSpacing(20)

        self.rTitleLabel = QtWidgets.QLabel()
        self.rInsideLabel = QtWidgets.QLabel()
        self.rOutsideLabel = QtWidgets.QLabel()
        self.rOverallLabel = QtWidgets.QLabel()

        self.rOutsideDoubleSpinBox = QtWidgets.QDoubleSpinBox()
        self.rInsideDoubleSpinBox = QtWidgets.QDoubleSpinBox()
        self.rOverallDoubleSpinBox = QtWidgets.QDoubleSpinBox()

        self.rUnitLabel1 = QtWidgets.QLabel()
        self.rUnitLabel2 = QtWidgets.QLabel()
        self.rUnitLabel3 = QtWidgets.QLabel()

        rLayout.addWidget(self.rTitleLabel,0,0)
        rLayout.addWidget(self.rOutsideLabel,0,1)
        rLayout.addWidget(self.rInsideLabel,1,1)
        rLayout.addWidget(self.rOverallLabel, 2,1)

        rLayout.addWidget(self.rOutsideDoubleSpinBox, 0,2)
        rLayout.addWidget(self.rInsideDoubleSpinBox, 1,2)
        rLayout.addWidget(self.rOverallDoubleSpinBox, 2,2)

        rLayout.addWidget(self.rUnitLabel1,0,3)
        rLayout.addWidget(self.rUnitLabel2,1,3)
        rLayout.addWidget(self.rUnitLabel3,2,3)


        self.setLayout(rLayout)
        self.retranslateUi()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.rTitleLabel.setText(_translate("RWidget", "R"))
        self.rInsideLabel.setText(_translate("RWidget", "R_si:"))
        self.rOutsideLabel.setText(_translate("RWidget", "R_se:"))
        self.rOverallLabel.setText(_translate("RWidget", "R_ges:"))
        self.rUnitLabel1.setText(_translate("RWidget", "Einheit"))
        self.rUnitLabel2.setText(_translate("RWidget", "Einheit"))
        self.rUnitLabel3.setText(_translate("RWidget", "Einheit"))