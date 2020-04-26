# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets


class LayerWidget(QtWidgets.QWidget):
    def __init__(self,position,modus):
        QtWidgets.QWidget.__init__(self)

        self.modus=modus

        self.position=position

        self.layerLayout = QtWidgets.QGridLayout()
        self.layerLayout.setContentsMargins(0,0,0,0)
        self.layerLayout.setSpacing(10)


        self.layerTitleLabel = QtWidgets.QLabel()
        self.layerWidthLabel = QtWidgets.QLabel()
        self.layerResLabel = QtWidgets.QLabel()
        self.layerResUnitLabel = QtWidgets.QLabel()

        self.layerWidthDoubleSpinBox = QtWidgets.QDoubleSpinBox()
        self.layerResDoubleSpinBox = QtWidgets.QDoubleSpinBox()

        self.layerDeleteButton = QtWidgets.QPushButton()
        self.layerAddAfterButton = QtWidgets.QPushButton()

        self.layerDeleteButton.clicked.connect(self.deleteButtonPressed)
        self.layerAddAfterButton.clicked.connect(self.addAfterButtonPressed)

        self.layerWidthComboBox = QtWidgets.QComboBox()
        self.layerWidthComboBox.addItems({"mm","cm","m"})


        #temperature
        self.layerTempOutLabel = QtWidgets.QLabel()
        self.layerTempInLabel = QtWidgets.QLabel()

        self.layerTempOutDoubleSpinBox = QtWidgets.QDoubleSpinBox()
        self.layerTempInDoubleSpinBox = QtWidgets.QDoubleSpinBox()

        self.layerTempUnitLabel1 = QtWidgets.QLabel()
        self.layerTempUnitLabel2 = QtWidgets.QLabel()



        self.layerLayout.addWidget(self.layerTitleLabel,0,0)
        self.layerLayout.addWidget(self.layerAddAfterButton, 0,10)
        self.layerLayout.addWidget(self.layerDeleteButton, 0, 11)

        self.layerLayout.addWidget(self.layerWidthLabel,1,0)
        self.layerLayout.addWidget(self.layerWidthDoubleSpinBox,1,1)
        self.layerLayout.addWidget(self.layerWidthComboBox,1,2)
        self.layerLayout.addWidget(self.layerResLabel,1,3)
        self.layerLayout.addWidget(self.layerResDoubleSpinBox,1,4)
        self.layerLayout.addWidget(self.layerResUnitLabel,1,5)

        if (self.modus==1):
            self.addTemp()

        self.setLayout(self.layerLayout)
        self.retranslateUi()
        self.layerTitleLabel.setText(self.layerTitleLabel.text() + str(self.position+1))


    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.layerTitleLabel.setText(_translate("LayerWidget", "Schicht "))
        self.layerWidthLabel.setText(_translate("LayerWidget", "Breite:"))
        self.layerResLabel.setText(_translate("LayerWidget", "R_i:"))
        self.layerResUnitLabel.setText(_translate("LayerWidget", "Einheit"))
        self.layerAddAfterButton.setText(_translate("LayerWidget", "+"))
        self.layerDeleteButton.setText(_translate("LayerWidget", "-"))

        self.layerTempInLabel.setText(_translate("LayerWidget", "Temp innen:"))
        self.layerTempOutLabel.setText(_translate("LayerWidget", "Temp außen"))
        self.layerTempUnitLabel1.setText(_translate("LayerWidget", "°C"))
        self.layerTempUnitLabel2.setText(_translate("LayerWidget", "°C"))

    def deleteButtonPressed(self):
        self.parent().parent().parent().parent().deleteLayer(self.position)

    def addAfterButtonPressed(self):
        self.parent().parent().parent().parent().addLayer(self.position+1,self.modus)

    def updatePos(self, pos):
        self.position=pos
        self.layerTitleLabel.setText(QtCore.QCoreApplication.translate("LayerWidget", "Schicht ")+ str(pos+1))

    def setRemovable(self, flag):
        if flag == True:
            self.layerDeleteButton.setEnabled(True)
        else:
            self.layerDeleteButton.setEnabled(False)

    def addTemp(self):
        row = self.layerLayout.rowCount()
        self.layerLayout.addWidget(self.layerTempOutLabel, row,0)
        self.layerLayout.addWidget(self.layerTempOutDoubleSpinBox , row,1)
        self.layerLayout.addWidget(self.layerTempUnitLabel1 , row,2)
        self.layerLayout.addWidget(self.layerTempInLabel, row,3)
        self.layerLayout.addWidget(self.layerTempInDoubleSpinBox, row,4)
        self.layerLayout.addWidget(self.layerTempUnitLabel2 , row,5)

    def removeTemp(self):
        self.layerLayout.removeWidget(self.layerTempOutLabel)
        self.layerLayout.removeWidget(self.layerTempInLabel)
        self.layerLayout.removeWidget(self.layerTempOutDoubleSpinBox)
        self.layerLayout.removeWidget(self.layerTempInDoubleSpinBox)
        self.layerLayout.removeWidget(self.layerTempUnitLabel1)
        self.layerLayout.removeWidget(self.layerTempUnitLabel2)



