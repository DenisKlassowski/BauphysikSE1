# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore, QtWidgets


class NewTab(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)

        # overall layout of tab
        tabLayout = QtWidgets.QVBoxLayout()
        tabLayout.setContentsMargins(0,0,0,0)
        tabLayout.setSpacing(0)
        tabLayout.setAlignment(QtCore.Qt.AlignCenter)

        #buttons
        self.buttonOpen = QtWidgets.QPushButton()
        self.buttonNewU = QtWidgets.QPushButton()
        self.buttonNewTemp = QtWidgets.QPushButton()

        self.buttonNewU.clicked.connect(self.buttonNewUClicked)
        self.buttonNewTemp.clicked.connect(self.buttonNewTempClicked)

        tabLayout.addWidget(self.buttonOpen)
        tabLayout.addWidget(self.buttonNewU)
        tabLayout.addWidget(self.buttonNewTemp)

        #generate Tab
        self.setLayout(tabLayout)
        self.retranslateUi()
        self.show()

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        self.buttonOpen.setText(_translate("NewTab", "Öffnen..."))
        self.buttonNewU.setText(_translate("NewTab", "Neue R-Berechnung"))
        self.buttonNewTemp.setText(_translate("NewTab", "Neue Temperaturkurvenberechnung"))

    def buttonNewUClicked(self):
        self.parent().parent().parent().addNewTab(0)

    def buttonNewTempClicked(self):
        self.parent().parent().parent().addNewTab(1)

