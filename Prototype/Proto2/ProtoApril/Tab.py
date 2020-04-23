# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, QtCore, QtGui
from TempWidget import TempWidget
from VisualizeWidget import VisualizeWidget
from LayerWidget import LayerWidget


class Tab(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)

        # overall layout of tab
        tabLayout = QtWidgets.QVBoxLayout()
        tabLayout.setContentsMargins(0,0,0,0)
        tabLayout.setSpacing(10)

        #upper layout of tab
        upperTab = QtWidgets.QWidget()
        tabUpperLayout = QtWidgets.QHBoxLayout()
        upperTab.setLayout(tabUpperLayout)

        #environment area
        self.scrollAreaEnvironment = QtWidgets.QScrollArea()
        environmentWidget = QtWidgets.QWidget()
        self.environmentLayout = QtWidgets.QFormLayout()
        self.environmentLayout.setSpacing(20)
        environmentWidget.setLayout(self.environmentLayout)

        self.scrollAreaEnvironment.setWidget(environmentWidget)
        self.scrollAreaEnvironment.setWidgetResizable(True)
        self.scrollAreaEnvironment.setMaximumWidth(500)

        tabUpperLayout.addWidget(self.scrollAreaEnvironment)

        #visualization area (WIP)
        self.visualizeWidget = VisualizeWidget()
        tabUpperLayout.addWidget(self.visualizeWidget)



        self.button1 = QtWidgets.QPushButton()
        self.button1.setText("Temp Widget hinzufügen (nur zum Test)")
        self.button1.clicked.connect(self.addTempWidget)

        #calculate button (to be discontinued)
        self.buttonCalculate = QtWidgets.QPushButton()

        #lower layout of tab
        self.scrollAreaLayers = QtWidgets.QScrollArea()
        layersWidget = QtWidgets.QWidget()
        self.layerLayout = QtWidgets.QFormLayout()
        self.layerLayout.setSpacing(20)

        self.appendLayer()

        layersWidget.setLayout(self.layerLayout)

        self.scrollAreaLayers.setWidget(layersWidget)
        self.scrollAreaLayers.setWidgetResizable(True)


        #merge into general tab
        tabLayout.addWidget(upperTab)
        tabLayout.addWidget(self.buttonCalculate)

        tabLayout.addWidget(self.button1)

        tabLayout.addWidget(self.scrollAreaLayers)

        self.setLayout(tabLayout)
        self.retranslateUi()
        self.show()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.buttonCalculate.setText(_translate("TabWidget", "Berechnen"))


    def addTempWidget(self):
        self.environmentLayout.insertRow(1,TempWidget())

    def appendLayer(self):
        self.layerLayout.addRow(LayerWidget(self.layerLayout.count()))

    def addLayer(self, position):
        self.layerLayout.insertRow(position, LayerWidget(position))
        self.updatePositionLayers(position+1)

    def deleteLayer(self, position):
        self.layerLayout.removeRow(position)
        self.updatePositionLayers(position)

    def updatePositionLayers(self, startPos):
        for pos in range(startPos, self.layerLayout.count()):
            self.layerLayout.itemAt(pos,2).widget().updatePos(pos)


