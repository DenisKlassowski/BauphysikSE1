# This Python file uses the following encoding: utf-8
from PyQt5 import QtWidgets, QtCore, QtGui
from TempWidget import TempWidget
from VisualizeWidget import VisualizeWidget
from LayerWidget import LayerWidget
from LayerDivider import LayerDivider
from RWidget import RWidget
from TabData import TabData


class Tab(QtWidgets.QWidget):
    def __init__(self,mode,name,data=None):
        QtWidgets.QWidget.__init__(self)
        self.mode=mode
        """mode (integer) in which the tab currently operates in"""
        self.layerCount = 0
        """count of layers currently in tab"""
        self.tabWidget=self.parent()
        """link to parent"""
        self.rWidget=RWidget()
        """RWidget which is part of tab"""
        self.tempWidget=TempWidget()
        """TempWidget which is part of tab"""
        self.data = None
        """data associated with tab"""

        #event handling rWidget
        self.rWidget.rInsideDoubleSpinBox.valueChanged.connect(self.rsiValueChanged)
        self.rWidget.rOutsideDoubleSpinBox.valueChanged.connect(self.rseValueChanged)
        self.rWidget.rOverallDoubleSpinBox.valueChanged.connect(self.roverallValueChanged)
        self.rWidget.rInvertedDoubleSpinBox.valueChanged.connect(self.uValueChanged)

        #event handling tempWidget
        self.tempWidget.tempInsideDoubleSpinBox.valueChanged.connect(self.tinValueChanged)
        self.tempWidget.tempOutsideDoubleSpinBox.valueChanged.connect(self.toutValueChanged)

        #flag to check whether calculations should happen or not. used for loading/startup process
        self.calculateFlag = 1
        """flag to help circumvent calculation loop when doing live calculation"""

        # overall layout of tab
        tabLayout = QtWidgets.QHBoxLayout()
        tabLayout.setContentsMargins(0,0,0,0)
        tabLayout.setSpacing(10)

        #left side of tab
        lTab=QtWidgets.QWidget()
        lTabLayout = QtWidgets.QVBoxLayout()
        lTabLayout.setContentsMargins(0,0,0,0)
        lTabLayout.setSpacing(10)
        lTab.setLayout(lTabLayout)

        #upper layout of tab
        upperTab = QtWidgets.QWidget()
        upperTab.setMaximumHeight(350)
        tabUpperLayout = QtWidgets.QHBoxLayout()
        tabUpperLayout.setContentsMargins(0,0,0,0)
        tabUpperLayout.setSpacing(0)
        upperTab.setLayout(tabUpperLayout)



        #environment area
        self.scrollAreaEnvironment = QtWidgets.QScrollArea()
        """environmental area"""
        environmentWidget = QtWidgets.QWidget()
        self.environmentLayout = QtWidgets.QFormLayout()
        """layout of environmental area"""
        self.environmentLayout.setSpacing(20)
        environmentWidget.setLayout(self.environmentLayout)

        """
        environmentWidget.setStyleSheet("QWidget{"
        "background-color: #FFFFFF;"
        "border: 0px solid #000000;"
        "color: rgb(0,0,0);"
        "}"
        "QLabel{"
        "padding: 0px"
        "}"
        "QDoubleSpinBox{"
        "border: 1px solid #000000;"
        "};")
        """

        self.environmentLayout.addRow(self.rWidget)
        self.environmentLayout.addRow(self.tempWidget)

        self.scrollAreaEnvironment.setWidget(environmentWidget)
        self.scrollAreaEnvironment.setWidgetResizable(True)
        self.scrollAreaEnvironment.setMinimumWidth(400)
        self.scrollAreaEnvironment.setMaximumWidth(400)

        tabUpperLayout.addWidget(self.scrollAreaEnvironment)

        #visualization area (WIP)
        self.visualizeWidget = VisualizeWidget()
        """visualization widget"""
        tabUpperLayout.addWidget(self.visualizeWidget)

        #lower layout of tab
        self.scrollAreaLayers = QtWidgets.QScrollArea()
        """scrollArea where all layers reside in"""
        layersWidget = QtWidgets.QWidget()
        self.layerLayout = QtWidgets.QFormLayout()
        """layout of scrollArea where all layers reside in"""
        self.layerLayout.setSpacing(20)

        #data handling
        if data is None:
            self.data=TabData(self.mode,name)
        else:
            self.data=data
        self.fillEnv()

        self.addEnvLayerDividers()
        if self.data==None or self.data.layers == []:
            self.addLayer(0)
        else:
            self.fillLayers()
            self.fillLayerDividers()
            self.calculate()
            self.visualizeWidget.updateGraph(self.data)

        layersWidget.setLayout(self.layerLayout)

        self.scrollAreaLayers.setWidget(layersWidget)
        self.scrollAreaLayers.setWidgetResizable(True)

        #layers style
        """
        layersWidget.setStyleSheet("QWidget{"
        "background-color: #f0f0f0"
        "};")
        """


        #merge into general tab
        lTabLayout.addWidget(upperTab)
        lTabLayout.addWidget(self.scrollAreaLayers)

        tabLayout.addWidget(lTab)

        self.setLayout(tabLayout)
        self.retranslateUi()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate

    def setEnvironment(self):
        """sets environmental area according to current mode"""
        if self.mode == 0:
            self.addRWidget()
            self.removeTempWidget()
        else:
            self.addRWidget()
            self.addTempWidget()
        self.visualizeWidget.switchMode(self.mode)

    def addRWidget(self):
        self.rWidget.show()

    def removeRWidget(self):
        self.rWidget.hide()

    def addTempWidget(self):
        self.tempWidget.show()

    def removeTempWidget(self):
        self.tempWidget.hide()

    def addEnvLayerDividers(self):
        """adds dividers around first layer"""
        self.layerLayout.insertRow(0,LayerDivider(self.mode))
        self.layerLayout.insertRow(1,LayerDivider(self.mode))

    def addLayer(self, position):
        """adds new layer at given position"""
        #enable delete button on the former solitary layer
        if(self.layerCount==1):
            self.layerLayout.itemAt(1,2).widget().setRemovable(True)

        l=LayerWidget(position,self.mode)
        if(self.layerCount==0):
            #if first layer
            self.layerLayout.insertRow(1,l)
            self.layerLayout.itemAt(1,2).widget().setRemovable(False)
        else:
            #add seperator
            self.layerLayout.insertRow(position*2, LayerDivider(self.mode))
            #add layer
            self.layerLayout.insertRow((position*2)+1, l)

        self.layerCount+=1

        self.updatePositionLayers(position)
        self.data.insert_layer(l.data,position)

    def loadLayer(self,position, layerData):
        """loads a layer from data and inserts it at given position"""
        #enable delete button on the former solitary layer
        if(self.layerCount==1):
            self.layerLayout.itemAt(1,2).widget().setRemovable(True)

        l=LayerWidget(position,self.mode,layerData)
        if(self.layerCount==0):
            #if first layer
            self.layerLayout.insertRow(1,l)
            self.layerLayout.itemAt(1,2).widget().setRemovable(False)
        else:
            #add seperator
            self.layerLayout.insertRow(position*2, LayerDivider(self.mode))
            #add layer
            self.layerLayout.insertRow((position*2)+1, l)


        self.layerCount+=1

        self.updatePositionLayers(position)

    def deleteLayer(self, position):
        """removes layer at given position"""
        self.data.remove_layer(position)
        if (position==0):
            self.layerLayout.removeRow(1)
            self.layerLayout.removeRow(1)
        else:
            self.layerLayout.removeRow((position*2))
            self.layerLayout.removeRow((position*2))
        self.layerCount-=1
        self.updatePositionLayers(position)

        #disable delete buttton for solitary layer
        if(self.layerCount==1):
            self.layerLayout.itemAt(1,2).widget().setRemovable(False)

        #unless this is done, a separator and an empty space will remain until minimizing and reopening the window. self.update() DOES NOT WORK
        self.scrollAreaLayers.hide()
        self.scrollAreaLayers.show()


    def updatePositionLayers(self, startPos):
        """updates the position of layers"""
        for pos in range(startPos, self.layerCount):
            self.layerLayout.itemAt((2*pos)+1,2).widget().updatePos(pos)


    def switchToTemp(self):
        """switches to Temp mode"""
        self.mode=1
        self.data.mode=1
        self.setEnvironment()
        for i in range(self.layerLayout.count()):
            self.layerLayout.itemAt(i,2).widget().switchMode(self.mode)

        #unless this is done, a separator and an empty space will remain or will be added until minimizing and reopening the window. self.update() DOES NOT WORK
        self.scrollAreaLayers.hide()
        self.scrollAreaLayers.show()


    def switchToU(self):
        """switches to U mode"""
        self.mode=0
        self.data.mode=0
        self.setEnvironment()
        for i in range(self.layerLayout.count()):
            self.layerLayout.itemAt(i,2).widget().switchMode(self.mode)
        #unless this is done, a separator and an empty space will remain or will be added until minimizing and reopening the window. self.update() DOES NOT WORK
        self.scrollAreaLayers.hide()
        self.scrollAreaLayers.show()

    def getRWidgetData(self):
        """writes current RWidget values into data"""
        self.data.rsi=self.rWidget.rInsideDoubleSpinBox.value()
        self.data.rse=self.rWidget.rOutsideDoubleSpinBox.value()
        self.data.rges=self.rWidget.rOverallDoubleSpinBox.value()
        self.data.u=self.rWidget.rInvertedDoubleSpinBox.value()

    def getTempData(self):
        """writes current TempWidget values into data"""
        self.data.tin=self.tempWidget.tempInsideDoubleSpinBox.value()
        self.data.tout=self.tempWidget.tempOutsideDoubleSpinBox.value()

    def generateData(self,name):
        """generates new TabData"""
        self.data=TabData(self.mode,name)
        #self.getRWidgetData()
        #self.getTempData()

    def fillEnv(self):
        """sets up and fills environmental area then loading from data"""
        self.mode=self.data.mode
        self.setEnvironment()
        self.fillEnvData()

    def fillEnvData(self):
        """fills environmental area then loading from data"""
        self.calculateFlag=0
        self.rWidget.setData(self.data.rleft,self.data.rright,self.data.rsum,self.data.rt,self.data.u)
        self.tempWidget.setData(self.data.tleft,self.data.tright)
        self.calculateFlag=1

    def fillEnvDataLite(self):
        """fills environmental area when loading from data after calculation"""
        self.calculateFlag=0
        self.rWidget.setDataLite(self.data.rsum,self.data.rt,self.data.u)
        self.calculateFlag=1

    def fillLayers(self):
        """fills layers when loading from data"""
        for x in range(len(self.data.layers)):
            self.loadLayer(x,self.data.layers[x])

    def fillLayerDividers(self):
        """fills layer dividers when loading from data"""
        if self.mode == 1:
            #some localization for different decimalPoints
            cLocale = QtCore.QLocale()
            for i in range(self.layerCount):
                if i != self.layerCount-1:
                    ss = cLocale.toString(round(self.layerLayout.itemAt(i*2+1,2).widget().data.t_left,2),'f',2) + " °C"
                    self.layerLayout.itemAt(i*2,2).widget().tempLabel.setText(ss)
                else:
                    ss = cLocale.toString(round(self.layerLayout.itemAt(i*2+1,2).widget().data.t_left,2),'f',2)+ " °C"
                    self.layerLayout.itemAt(i*2,2).widget().tempLabel.setText(ss)
                    ss2 = cLocale.toString(round(self.layerLayout.itemAt(i*2+1,2).widget().data.t_right,2),'f',2)+ " °C"
                    self.layerLayout.itemAt(i*2+2,2).widget().tempLabel.setText(ss2)

    def calculate(self):
        """calculates the current tab"""
        if self.calculateFlag==1:
            self.calculateFlag=0
            try:
                self.data.calculate()
                self.fillEnvDataLite()
                self.fillLayerDividers()
                self.visualizeWidget.updateGraph(self.data)
            except ZeroDivisionError:
                #think of something else here...
                print("ZeroDivision ph")
            self.calculateFlag=1

    #value changes
    def rsiValueChanged(self):
        self.data.rleft=self.rWidget.rInsideDoubleSpinBox.value()
        self.calculate()

    def rseValueChanged(self):
        self.data.rright=self.rWidget.rOutsideDoubleSpinBox.value()
        self.calculate()

    def roverallValueChanged(self):
        self.data.rsum=self.rWidget.rOverallDoubleSpinBox.value()

    def uValueChanged(self):
        self.data.u=self.rWidget.rInvertedDoubleSpinBox.value()

    def tinValueChanged(self):
        self.data.tleft=self.tempWidget.tempInsideDoubleSpinBox.value()
        self.calculate()

    def toutValueChanged(self):
        self.data.tright=self.tempWidget.tempOutsideDoubleSpinBox.value()
        self.calculate()

    def removeSelf(self):
        """stub"""
        del self

    def updateNameData(self,name):
        self.data.name = name
