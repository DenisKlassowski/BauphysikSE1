# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore, QtWidgets, QtGui, Qt


class NewTab(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)

        # overall layout of tab
        tabLayout = QtWidgets.QHBoxLayout()
        tabLayout.setContentsMargins(0,0,0,0)
        tabLayout.setSpacing(0)
        tabLayout.setAlignment(QtCore.Qt.AlignCenter)
        buttonWidget = QtWidgets.QWidget()
        buttonLayout = QtWidgets.QVBoxLayout()
        buttonLayout.setContentsMargins(60,10,0,10)
        buttonLayout.setSpacing(0)
        buttonLayout.setAlignment(QtCore.Qt.AlignCenter)
        self.imageWidget = QtWidgets.QLabel()
        #self.image = QtGui.QPixmap()
        #self.image.load("UI_Design/thermopgrafie.jpg")
        #buttons
        self.buttonOpen = QtWidgets.QPushButton()
        self.buttonOpen.setIcon(QtGui.QIcon("UI_Design/folder_open-blue18dp.svg"))
        self.buttonOpen.setIconSize(QtCore.QSize(180,180))
        self.buttonOpenLabel = QtWidgets.QLabel("<b>Öffnen</b>")
        self.buttonOpenLabel.setAlignment(QtCore.Qt.AlignCenter)
        self.buttonOpenLabel.setFixedWidth(200)
        self.buttonOpenLabel.setTextFormat(QtCore.Qt.TextFormat(1))
        self.buttonNewU = QtWidgets.QPushButton()
        self.buttonNewU.setIcon(QtGui.QIcon("UI_Design/U-blue-18dp.svg"))
        self.buttonNewU.setIconSize(QtCore.QSize(180,180))
        self.buttonNewULabel = QtWidgets.QLabel("<b>U-Berechnung</b>")
        self.buttonNewULabel.setFixedWidth(200)
        self.buttonNewULabel.setAlignment(QtCore.Qt.AlignCenter)
        self.buttonNewULabel.setTextFormat(QtCore.Qt.TextFormat(1))
        self.buttonNewTemp = QtWidgets.QPushButton()
        self.buttonNewTemp.setIcon(QtGui.QIcon("UI_Design/timeline-blue-18dp.svg"))
        self.buttonNewTemp.setIconSize(QtCore.QSize(180,180))
        self.buttonNewTempLabel = QtWidgets.QLabel("<b>Temperaturkurven-<br>berechnung</b>")
        self.buttonNewTempLabel.setFixedWidth(200)
        self.buttonNewTempLabel.setAlignment(QtCore.Qt.AlignCenter)
        self.buttonNewTempLabel.setTextFormat(QtCore.Qt.TextFormat(1))


        self.buttonNewU.clicked.connect(self.buttonNewUClicked)
        self.buttonNewTemp.clicked.connect(self.buttonNewTempClicked)
        self.buttonOpen.clicked.connect(self.buttonOpenFileClicked)


        buttonLayout.addWidget(self.buttonOpen)
        buttonLayout.addWidget(self.buttonOpenLabel)
        buttonLayout.addWidget(self.buttonNewU)
        buttonLayout.addWidget(self.buttonNewULabel)
        buttonLayout.addWidget(self.buttonNewTemp)
        buttonLayout.addWidget(self.buttonNewTempLabel)

        self.image = QtGui.QPixmap(QtGui.QPixmap("UI_Design/thermopgrafie.jpg").scaled(QtCore.QSize(self.imageWidget.rect().height(),self.imageWidget.rect().width())))
        #self.image.load("UI_Design/thermopgrafie.jpg")
        #self.image.scaled(QtCore.QSize(self.imageWidget.rect().height(),self.imageWidget.rect().width()))
        self.imageWidget.setPixmap(self.image)

        buttonWidget.setLayout(buttonLayout)

        tabLayout.addWidget(self.imageWidget)
        tabLayout.addWidget(buttonWidget)

    

        #style
        """
        self.setStyleSheet("QPushButton{"
        "border: 0px solid #ff0000;"
        "color: rgb(255, 255, 255);"
        "padding: 5px;"
        "background-color: #A0BEEA;"
        "}"
        "QPushButton:hover {"
        "border: 1px solid #333333;"
        "color: rgb(255, 255, 255);"
        "background-color: #2F63AF;"
        "}"
        "QPushButton:pressed {"
        "border: 1px solid #333333;"
        "color: rgb(255, 255, 255);"
        "background-color: #12499A;"
        "};")
        """

        #generate Tab
        self.setLayout(tabLayout)
        self.retranslateUi()
        self.show()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        #self.buttonOpen.setText(_translate("NewTab", "Öffnen..."))
        #self.buttonNewU.setText(_translate("NewTab", "Neue R-Berechnung"))
        #self.buttonNewTemp.setText(_translate("NewTab", "Neue Temperaturkurvenberechnung"))

    def buttonNewUClicked(self):
        self.parent().parent().parent().addNewTab(0)

    def buttonNewTempClicked(self):
        self.parent().parent().parent().addNewTab(1)

    def buttonOpenFileClicked(self):
       self.parent().parent().parent().openFile()

