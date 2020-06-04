# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets
from CustomMiniWidgets import MyDoubleSpinBox
from LayerData import LayerData

class LayerWidget(QtWidgets.QWidget):
    def __init__(self,position,mode):
        QtWidgets.QWidget.__init__(self)

        #information from upper levels
        self.mode=mode
        self.position=position

        #data
        self.data=LayerData()
        self.widthFactor = 1

        #flag to check whether calculations should happen or not. used for loading/startup process
        self.calculateFlag = 1

        #layouts
        #main layout
        self.mainLayout = QtWidgets.QVBoxLayout()
        self.mainLayout.setContentsMargins(0,0,0,0)
        self.mainLayout.setSpacing(10)

        #head layout
        self.head = QtWidgets.QWidget()
        self.headButtons = QtWidgets.QWidget()

        self.headLayout = QtWidgets.QHBoxLayout()
        self.headLayout.setContentsMargins(0,0,0,0)
        self.headLayout.setSpacing(10)

        self.headButtonLayout = QtWidgets.QHBoxLayout()
        self.headButtonLayout.setContentsMargins(0,0,0,0)
        self.headButtonLayout.setSpacing(0)

        self.layerTitleLabel = QtWidgets.QLabel()

        self.layerDeleteButton = QtWidgets.QPushButton()
        self.layerDeleteButton.clicked.connect(self.deleteButtonPressed)
        self.layerAddAfterButton = QtWidgets.QPushButton()
        self.layerAddAfterButton.clicked.connect(self.addAfterButtonPressed)

        self.headButtonLayout.addWidget(self.layerAddAfterButton)
        self.headButtonLayout.addWidget(self.layerDeleteButton)
        self.headButtonLayout.setAlignment(QtCore.Qt.AlignRight)
        self.headButtons.setLayout(self.headButtonLayout)

        self.headLayout.addWidget(self.layerTitleLabel)
        self.headLayout.addWidget(self.headButtons)


        self.head.setLayout(self.headLayout)


        #body layout
        self.body = QtWidgets.QWidget()

        self.bodyLayout = QtWidgets.QGridLayout()
        self.bodyLayout.setContentsMargins(0,0,0,0)
        self.bodyLayout.setSpacing(10)

        self.layerWidthLabel = QtWidgets.QLabel()
        self.layerWidthDoubleSpinBox = MyDoubleSpinBox()
        self.layerWidthDoubleSpinBox.setSingleStep(0.001)
        self.layerWidthDoubleSpinBox.setMaximum(9.999)
        self.layerWidthDoubleSpinBox.setMaximumWidth(100)
        self.layerWidthDoubleSpinBox.valueChanged.connect(self.widthChanged)

        self.layerWidthComboBox = QtWidgets.QComboBox()
        self.layerWidthComboBox.addItems({"m"})
        self.layerWidthComboBox.addItems({"cm"})
        self.layerWidthComboBox.addItems({"mm"})

        self.layerWidthComboBox.currentIndexChanged.connect(self.widthFactorChanged)

        self.layerLambdaLabel = QtWidgets.QLabel()
        self.layerLambdaDoubleSpinBox = MyDoubleSpinBox()
        self.layerLambdaDoubleSpinBox.setMinimum(0.001)
        self.layerLambdaDoubleSpinBox.setValue(0.01)
        self.layerLambdaDoubleSpinBox.setSingleStep(0.01)
        self.layerLambdaDoubleSpinBox.setMaximumWidth(100)
        self.layerLambdaDoubleSpinBox.valueChanged.connect(self.lambdaChanged)
        self.layerLambdaUnitLabel = QtWidgets.QLabel()

        self.layerResLabel = QtWidgets.QLabel()
        self.layerResDoubleSpinBox = MyDoubleSpinBox()
        self.layerResDoubleSpinBox.setDecimals(4)
        self.layerResDoubleSpinBox.setSingleStep(0.0001)
        self.layerResDoubleSpinBox.setMaximum(999.9999)
        self.layerResDoubleSpinBox.setEditable(0)
        self.layerResDoubleSpinBox.setMaximumWidth(100)
        self.layerResDoubleSpinBox.valueChanged.connect(self.rChanged)
        self.layerResUnitLabel = QtWidgets.QLabel()

        self.layerResGivenCheckBox = QtWidgets.QCheckBox(QtCore.QCoreApplication.translate("LayerWidget", "R gegeben "))
        self.layerResGivenCheckBox.stateChanged.connect(self.resGivenCheckboxChanged)

        #set data in data object
        self.initData()

        #temperature soon to be depricated
        #self.layerTempOutLabel = QtWidgets.QLabel()
        #self.layerTempInLabel = QtWidgets.QLabel()

        #self.layerTempOutDoubleSpinBox = MyDoubleSpinBox()
        #self.layerTempInDoubleSpinBox = MyDoubleSpinBox()

        #self.layerTempUnitLabel1 = QtWidgets.QLabel()
        #self.layerTempUnitLabel2 = QtWidgets.QLabel()

        #assemble body layou
        self.bodyLayout.addWidget(self.layerWidthLabel,0,0)
        self.bodyLayout.addWidget(self.layerWidthDoubleSpinBox,0,1)
        self.bodyLayout.addWidget(self.layerWidthComboBox,0,2)
        self.bodyLayout.addWidget(self.layerLambdaLabel,0,3)
        self.bodyLayout.addWidget(self.layerLambdaDoubleSpinBox,0,4)
        self.bodyLayout.addWidget(self.layerLambdaUnitLabel,0,5)
        self.bodyLayout.addWidget(self.layerResLabel,0,6)
        self.bodyLayout.addWidget(self.layerResDoubleSpinBox,0,7)
        self.bodyLayout.addWidget(self.layerResUnitLabel,0,8)
        self.bodyLayout.addWidget(self.layerResGivenCheckBox,0,9)

        self.body.setLayout(self.bodyLayout)

        #bottom layout could be placed here if neccessary


        #check for mode, right now not really neccessary
        self.switchMode(self.mode)

        self.mainLayout.addWidget(self.head)
        self.mainLayout.addWidget(self.body)
        self.setLayout(self.mainLayout)

        self.retranslateUi()

        #set position and text
        self.updatePos(self.position)


    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.layerTitleLabel.setText(_translate("LayerWidget", "Schicht "))

        self.layerWidthLabel.setText(_translate("LayerWidget", "Dicke:"))

        self.layerLambdaLabel.setText(_translate("LayerWidget", "λ:"))
        self.layerLambdaUnitLabel.setText(_translate("LayerWidget", "Wm<sup>-1</sup>K<sup>-1</sub>"))

        self.layerResLabel.setText(_translate("LayerWidget", "R_i:"))
        self.layerResUnitLabel.setText(_translate("LayerWidget", "m<sup>2</sup>KW<sup>-1</sub>"))

        self.layerAddAfterButton.setText(_translate("LayerWidget", "+"))
        self.layerDeleteButton.setText(_translate("LayerWidget", "-"))

        #self.layerTempInLabel.setText(_translate("LayerWidget", "Temp_in:"))
        #self.layerTempOutLabel.setText(_translate("LayerWidget", "Temp_out"))
        #self.layerTempUnitLabel1.setText(_translate("LayerWidget", "°C"))
        #self.layerTempUnitLabel2.setText(_translate("LayerWidget", "°C"))

    #delete this layer
    def deleteButtonPressed(self):
        self.parent().parent().parent().parent().parent().deleteLayer(self.position)

    #add layer beneath
    def addAfterButtonPressed(self):
        self.parent().parent().parent().parent().parent().addLayer(self.position+1)

    #update own position and modify text
    def updatePos(self, pos):
        self.position=pos
        self.layerTitleLabel.setText(QtCore.QCoreApplication.translate("LayerWidget", "Schicht ")+str(pos+1))
        self.layerResLabel.setText(QtCore.QCoreApplication.translate("LayerWidget", "R")+"<sub>"+str(pos+1)+"</sub>"+":")

    #enable/disable delete button
    def setRemovable(self, flag):
        if flag == True:
            self.layerDeleteButton.setEnabled(1)
        else:
            self.layerDeleteButton.setEnabled(0)

    #enable/disable lamba box
    def resGivenCheckboxChanged(self):
        if self.layerResGivenCheckBox.checkState():
            self.layerLambdaDoubleSpinBox.setEditable(0)
            self.layerResDoubleSpinBox.setEditable(1)
        else:
            self.layerLambdaDoubleSpinBox.setEditable(1)
            self.layerResDoubleSpinBox.setEditable(0)

    #modify mode of layer
    def switchMode(self,mode):
        self.mode = mode

    #value changes
    def initData(self):
        self.data.width=self.layerWidthDoubleSpinBox.value()*self.widthFactor
        self.data.lambda_=self.layerLambdaDoubleSpinBox.value()

    def widthChanged(self):
        self.data.width=self.layerWidthDoubleSpinBox.value()*self.widthFactor
        self.calculate_r()

    def lambdaChanged(self):
        self.data.lambda_=self.layerLambdaDoubleSpinBox.value()
        self.calculate_r()

    def rChanged(self):
        self.data.r=self.layerResDoubleSpinBox.value()

    def widthFactorChanged(self):
        index = self.layerWidthComboBox.currentIndex()
        self.data.widthUnit=index
        if index == 0:
            self.widthFactor = 1
            self.layerWidthDoubleSpinBox.setMaximum(9.999)
        elif index == 1:
            self.widthFactor = 0.01
            self.layerWidthDoubleSpinBox.setMaximum(999.999)
        elif index == 2:
            self.widthFactor = 0.001
            self.layerWidthDoubleSpinBox.setMaximum(9999.999)
        self.widthChanged()
        self.calculate_r()

    def calculate_r(self):
        if(self.calculateFlag):
            self.data.calculate()
            self.layerResDoubleSpinBox.setValue(self.data.r)

    def updateValues(self):
        self.layerWidthDoubleSpinBox.setValue(self.data.width)
        self.layerComboBox.setIndex(self.data.widthUnit)
        self.layerLambdaDoubleSpinBox.setValue(self.data.lamba_)
        self.layerResDoubleSpinBox.setValue(self.data.r)
