# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, QtCore, QtGui
from TempWidget import TempWidget
from VisualizeWidget import VisualizeWidget
from LayerWidget import LayerWidget
from LayerDivider import LayerDivider
from RWidget import RWidget
from TabData import TabData


class Tab(QtWidgets.QWidget):
    def __init__(self,mode):
        QtWidgets.QWidget.__init__(self)
        self.mode=mode
        self.layerCount = 0

        # overall layout of tab
        tabLayout = QtWidgets.QVBoxLayout()
        tabLayout.setContentsMargins(0,0,0,0)
        tabLayout.setSpacing(10)

        #upper layout of tab
        upperTab = QtWidgets.QWidget()
        tabUpperLayout = QtWidgets.QHBoxLayout()
        tabUpperLayout.setContentsMargins(0,0,0,0)
        tabUpperLayout.setSpacing(10)
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

        self.setEnvironment()


        #visualization area (WIP)
        self.visualizeWidget = VisualizeWidget()
        tabUpperLayout.addWidget(self.visualizeWidget)

        #calculate button (to be discontinued)
        self.buttonCalculate = QtWidgets.QPushButton()

        #lower layout of tab
        self.scrollAreaLayers = QtWidgets.QScrollArea()
        layersWidget = QtWidgets.QWidget()
        self.layerLayout = QtWidgets.QFormLayout()
        self.layerLayout.setSpacing(20)

        self.addEnvLayerDividers()
        self.addLayer(0)

        layersWidget.setLayout(self.layerLayout)

        self.scrollAreaLayers.setWidget(layersWidget)
        self.scrollAreaLayers.setWidgetResizable(True)


        #merge into general tab
        tabLayout.addWidget(upperTab)
        tabLayout.addWidget(self.buttonCalculate)

        tabLayout.addWidget(self.scrollAreaLayers)

        self.setLayout(tabLayout)
        self.retranslateUi()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.buttonCalculate.setText(_translate("TabWidget", "Berechnen (Dummy)"))

    def setEnvironment(self):
        if self.mode == 0:
            self.addRWidget()
            self.removeTempWidget()
        else:
            self.addRWidget()
            self.addTempWidget()

    def addRWidget(self):
        if hasattr(self, 'rWidget'):
            pass
        else:
            self.rWidget=RWidget()
            self.environmentLayout.addRow(self.rWidget)

    def removeRWidget(self):
        try:
            self.environmentLayout.removeRow(self.rWidget)
        except AttributeError:
            pass
        except RuntimeError:
            if hasattr(self, 'rWidget'):
                print('RuntimeError: rWidget was removed from layout, but not from object.')

    def addTempWidget(self):
        if hasattr(self, 'tempWidget'):
            pass
        else:
            self.tempWidget = TempWidget()
            self.environmentLayout.addRow(self.tempWidget)

    def removeTempWidget(self):
        try:
            self.environmentLayout.removeRow(self.tempWidget)
            del self.tempWidget
        except AttributeError:
            pass
        except RuntimeError:
            if hasattr(self, 'tempWidget'):
                print('RuntimeError: tempWidget was removed from layout, but not from object.')

    def addEnvLayerDividers(self):
        self.layerLayout.insertRow(0,LayerDivider(self.mode))
        self.layerLayout.insertRow(1,LayerDivider(self.mode))

    def addLayer(self, position):
        #enable delete button on the former solitary layer
        if(self.layerCount==1):
            self.layerLayout.itemAt(1,2).widget().setRemovable(True)

        if(self.layerCount==0):
            #if first layer
            self.layerLayout.insertRow(1,LayerWidget(position,self.mode))
            self.layerLayout.itemAt(1,2).widget().setRemovable(False)
        else:
            #add seperator
            self.layerLayout.insertRow(position*2, LayerDivider(self.mode))
            #add layer
            self.layerLayout.insertRow((position*2)+1, LayerWidget(position,self.mode))

        self.layerCount+=1

        self.updatePositionLayers(position)

    def deleteLayer(self, position):
        if (position==0):
            self.layerLayout.removeRow(1)
            self.layerLayout.removeRow(1)
        else:
            self.layerLayout.removeRow((position*2))
            self.layerLayout.removeRow((position*2))
        self.layerCount-=1
        self.updatePositionLayers(position)
        if(self.layerCount==1):
            self.layerLayout.itemAt(1,2).widget().setRemovable(False)

        #unless this is done, a separator and an empty space will remain until minimizing and reopening the window. self.update() DOES NOT WORK
        self.scrollAreaLayers.hide()
        self.scrollAreaLayers.show()


    def updatePositionLayers(self, startPos):
        for pos in range(startPos, self.layerCount):
            self.layerLayout.itemAt((2*pos)+1,2).widget().updatePos(pos)


    def switchToTemp(self):
        self.mode=1
        self.setEnvironment()
        for i in range(self.layerLayout.count()):
            self.layerLayout.itemAt(i,2).widget().switchMode(self.mode)

        #unless this is done, a separator and an empty space will remain or will be added until minimizing and reopening the window. self.update() DOES NOT WORK
        self.scrollAreaLayers.hide()
        self.scrollAreaLayers.show()


    def switchToU(self):
        self.mode=0
        self.setEnvironment()
        for i in range(self.layerLayout.count()):
            self.layerLayout.itemAt(i,2).widget().switchMode(self.mode)
        #unless this is done, a separator and an empty space will remain or will be added until minimizing and reopening the window. self.update() DOES NOT WORK
        self.scrollAreaLayers.hide()
        self.scrollAreaLayers.show()


