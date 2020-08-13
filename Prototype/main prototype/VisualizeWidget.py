# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets
import pyqtgraph as pg
from pyqtgraph import exporters


class VisualizeWidget(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        layout = QtWidgets.QVBoxLayout()

        self.placeholderLabel = QtWidgets.QLabel()
        self.placeholderLabel.setText("this is a placeholder")
        
        self.graphWidget = pg.PlotWidget()
        """PlotWidget used for graphical representation"""
        self.graphWidget.setBackground('w')
        pen=pg.mkPen(color=(255,0,0))

        self.width = []
        self.temperature = []

        self.graphWidget.setLabel('left', QtCore.QCoreApplication.translate("VisualizeWidget:","Temperatur in °C"))
        self.graphWidget.setLabel('bottom', QtCore.QCoreApplication.translate("VisualizeWidget:","Distanz in m"))
        self.graphWidget.setTitle(QtCore.QCoreApplication.translate("VisualizeWidget:","Temperaturverlauf"),color='k')

        self.data_line = self.graphWidget.plot(self.width,self.temperature,pen=pen)

        #layout.addWidget(self.placeholderLabel)
        layout.addWidget(self.graphWidget)
        self.setMaximumHeight(600)
        #self.setMaximumWidth(400)

        self.setLayout(layout)


    def updateGraph(self, data):
        """updates Graph with given data object"""
        self.width=[0]
        self.temperature=[]
        l = len(data.layers)
        for i in range(l):
            self.width.append(data.layers[i].width+self.width[i])
            self.temperature.append(data.layers[i].t_left)
            if i == l-1:
                self.temperature.append(data.layers[i].t_right)

        self.data_line.setData(self.width,self.temperature)

    def switchMode(self,mode):
        """shows/hides widget according to given mode"""
        if mode == 0:
            self.graphWidget.hide()
        else:
            self.graphWidget.show()

    def getImage(self):
        """get image of graph, used for export"""
        try:
            exporter = exporters.ImageExporter(self.graphWidget.plotItem)
            exporter.parameters()['width'] = 600
            img = exporter.export(None,True,False)
            return img
        except:
            img = None
            return img

