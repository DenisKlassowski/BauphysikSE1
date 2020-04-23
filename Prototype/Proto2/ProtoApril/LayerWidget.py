# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets


class LayerWidget(QtWidgets.QWidget):
    def __init__(self,position):
        QtWidgets.QWidget.__init__(self)

        self.position=position

        layerLayout = QtWidgets.QGridLayout()
        layerLayout.setContentsMargins(0,0,0,0)
        layerLayout.setSpacing(10)


        self.layerTitleLabel = QtWidgets.QLabel()
        self.layerWidthLabel = QtWidgets.QLabel()
        self.layerResLabel = QtWidgets.QLabel()

        self.layerWidthDoubleSpinBox = QtWidgets.QDoubleSpinBox()
        self.layerResDoubleSpinBox = QtWidgets.QDoubleSpinBox()

        self.layerDeleteButton = QtWidgets.QPushButton()
        self.layerAddAfterButton = QtWidgets.QPushButton()

        self.layerDeleteButton.clicked.connect(self.deleteButtonPressed)
        self.layerAddAfterButton.clicked.connect(self.addAfterButtonPressed)

        self.layerWidthComboBox = QtWidgets.QComboBox()
        self.layerWidthComboBox.addItems({"mm","cm","m"})


        #test
        self.testLabel = QtWidgets.QLabel()
        self.testLabel.setText(str(self.position))
        layerLayout.addWidget(self.testLabel,0,1)


        layerLayout.addWidget(self.layerTitleLabel,0,0)
        layerLayout.addWidget(self.layerAddAfterButton, 0,10)
        layerLayout.addWidget(self.layerDeleteButton, 0, 11)

        layerLayout.addWidget(self.layerWidthLabel,1,0)
        layerLayout.addWidget(self.layerWidthDoubleSpinBox,1,1)
        layerLayout.addWidget(self.layerWidthComboBox,1,2)
        layerLayout.addWidget(self.layerResLabel,1,3)
        layerLayout.addWidget(self.layerResDoubleSpinBox,1,4)

        self.setLayout(layerLayout)
        self.retranslateUi()
        self.layerTitleLabel.setText(self.layerTitleLabel.text() + str(self.position+1))
        self.show()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.layerTitleLabel.setText(_translate("LayerWidget", "Schicht "))
        self.layerWidthLabel.setText(_translate("LayerWidget", "Breite:"))
        self.layerResLabel.setText(_translate("LayerWidget", "R_i:"))
        self.layerAddAfterButton.setText(_translate("LayerWidget", "+"))
        self.layerDeleteButton.setText(_translate("LayerWidget", "-"))

    def deleteButtonPressed(self):
        self.parent().parent().parent().parent().deleteLayer(self.position)

    def addAfterButtonPressed(self):
        self.parent().parent().parent().parent().addLayer(self.position+1)

    def updatePos(self, pos):
        self.testLabel.setText(str(pos))
        self.position=pos
        self.layerTitleLabel.setText(QtCore.QCoreApplication.translate("LayerWidget", "Schicht ")+ str(pos+1))

