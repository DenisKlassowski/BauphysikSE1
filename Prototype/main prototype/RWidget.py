# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets
from CustomMiniWidgets import MyDoubleSpinBox


class RWidget(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)

        #layout of widget
        rLayout = QtWidgets.QGridLayout()
        rLayout.setContentsMargins(0,0,0,0)
        rLayout.setSpacing(20)

        self.rTitleLabel = QtWidgets.QLabel()
        self.rInsideLabel = QtWidgets.QLabel()
        self.rOutsideLabel = QtWidgets.QLabel()
        self.rTOverallLabel = QtWidgets.QLabel()
        self.rOverallLabel = QtWidgets.QLabel()
        self.rInvertedLabel = QtWidgets.QLabel()

        self.rOutsideDoubleSpinBox = MyDoubleSpinBox()
        self.rOutsideDoubleSpinBox.setDecimals(4)
        self.rInsideDoubleSpinBox = MyDoubleSpinBox()
        self.rInsideDoubleSpinBox.setDecimals(4)
        self.rOverallDoubleSpinBox = MyDoubleSpinBox()
        self.rOverallDoubleSpinBox.setDecimals(4)
        self.rOverallDoubleSpinBox.setEditable(0)
        self.rTOverallDoubleSpinBox = MyDoubleSpinBox()
        self.rTOverallDoubleSpinBox.setDecimals(4)
        self.rTOverallDoubleSpinBox.setEditable(0)
        self.rInvertedDoubleSpinBox = MyDoubleSpinBox()
        self.rInvertedDoubleSpinBox.setDecimals(4)
        self.rInvertedDoubleSpinBox.setEditable(0)

        self.rUnitLabel1 = QtWidgets.QLabel()
        self.rUnitLabel2 = QtWidgets.QLabel()
        self.rUnitLabel3 = QtWidgets.QLabel()
        self.rUnitLabel4 = QtWidgets.QLabel()
        self.rUnitLabel5 = QtWidgets.QLabel()

        #assemble layout
        rLayout.addWidget(self.rTitleLabel,0,0)
        rLayout.addWidget(self.rInsideLabel,0,1)
        rLayout.addWidget(self.rOutsideLabel,1,1)
        rLayout.addWidget(self.rOverallLabel, 2,1)
        rLayout.addWidget(self.rTOverallLabel, 3,1)
        rLayout.addWidget(self.rInvertedLabel, 4,1)

        rLayout.addWidget(self.rInsideDoubleSpinBox, 0,2)
        rLayout.addWidget(self.rOutsideDoubleSpinBox, 1,2)
        rLayout.addWidget(self.rOverallDoubleSpinBox, 2,2)
        rLayout.addWidget(self.rTOverallDoubleSpinBox, 3,2)
        rLayout.addWidget(self.rInvertedDoubleSpinBox, 4,2)

        rLayout.addWidget(self.rUnitLabel1,0,3)
        rLayout.addWidget(self.rUnitLabel2,1,3)
        rLayout.addWidget(self.rUnitLabel3,2,3)
        rLayout.addWidget(self.rUnitLabel4,3,3)
        rLayout.addWidget(self.rUnitLabel5,4,3)

        self.setLayout(rLayout)
        self.retranslateUi()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.rTitleLabel.setText(_translate("RWidget", "R"))
        self.rInsideLabel.setText(_translate("RWidget", "R<sub>si</sub>:"))
        self.rOutsideLabel.setText(_translate("RWidget", "R<sub>se</sub>:"))
        self.rOverallLabel.setText(_translate("RWidget", "R<sub>ges</sub>:"))
        self.rTOverallLabel.setText(_translate("RWidget", "R<sub>T</sub>:"))
        self.rInvertedLabel.setText(_translate("RWidget", "U:"))
        self.rUnitLabel1.setText(_translate("RWidget", "m<sup>2</sup>KW<sup>-1</sub>"))
        self.rUnitLabel2.setText(_translate("RWidget", "m<sup>2</sup>KW<sup>-1</sub>"))
        self.rUnitLabel3.setText(_translate("RWidget", "m<sup>2</sup>KW<sup>-1</sub>"))
        self.rUnitLabel4.setText(_translate("RWidget", "m<sup>2</sup>KW<sup>-1</sub>"))
        self.rUnitLabel5.setText(_translate("RWidget", "Wm<sup>-2</sup>K<sup>-1</sub>"))

    def setData(self, rleft, rright, roverall, rt, rinverted):
        self.rInsideDoubleSpinBox.setValue(rleft)
        self.rOutsideDoubleSpinBox.setValue(rright)
        self.rOverallDoubleSpinBox.setValue(roverall)
        self.rTOverallDoubleSpinBox.setValue(rt)
        self.rInvertedDoubleSpinBox.setValue(rinverted)
