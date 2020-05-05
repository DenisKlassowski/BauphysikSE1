# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, QtCore, QtGui
from TempWidget import TempWidget
from VisualizeWidget import VisualizeWidget
from LayerWidget import LayerWidget
from RWidget import RWidget


class Tab(QtWidgets.QWidget):
    def __init__(self,modus):
        QtWidgets.QWidget.__init__(self)

        self.modus=modus

        # overall layout of tab
        tabLayout = QtWidgets.QVBoxLayout()
        tabLayout.setContentsMargins(0,0,0,0)
        tabLayout.setSpacing(0)

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

        self.addLayer(0,self.modus)

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
        if self.modus == 0:
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


    def addLayer(self, position,modus):
        if(self.layerLayout.count()==1):
            self.layerLayout.itemAt(0,2).widget().setRemovable(True)
        self.layerLayout.insertRow(position, LayerWidget(position,modus))
        self.updatePositionLayers(position+1)
        if(self.layerLayout.count()==1):
            self.layerLayout.itemAt(0,2).widget().setRemovable(False)



    def deleteLayer(self, position):
        self.layerLayout.removeRow(position)
        self.updatePositionLayers(position)
        if(self.layerLayout.count()==1):
            self.layerLayout.itemAt(0,2).widget().setRemovable(False)

    def updatePositionLayers(self, startPos):
        for pos in range(startPos, self.layerLayout.count()):
            self.layerLayout.itemAt(pos,2).widget().updatePos(pos)


    def switchToTemp(self):
        self.modus=1
        self.setEnvironment()
        for i in range(self.layerLayout.count()):
            self.layerLayout.itemAt(i,2).widget().modus=1
            self.layerLayout.itemAt(i,2).widget().addTemp()

    def switchToU(self):
        self.modus=0
        self.setEnvironment()
        for i in range(self.layerLayout.count()):
            self.layerLayout.itemAt(i,2).widget().modus=0
            self.layerLayout.itemAt(i,2).widget().removeTemp()
