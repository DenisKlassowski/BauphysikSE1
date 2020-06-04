# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore, QtWidgets, QtGui
from Tab import Tab
from NewTab import NewTab


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(MainWindow,self).__init__()

        #menu bar
        bar=self.menuBar()

        menuFile = bar.addMenu(QtCore.QCoreApplication.translate("MainWindow","Datei"))
        menuLanguage = bar.addMenu(QtCore.QCoreApplication.translate("MainWindow","Sprache"))
        self.menuModus = bar.addMenu(QtCore.QCoreApplication.translate("MainWindow","Modus"))

        #language actions
        self.actionGerman = QtWidgets.QAction()
        self.actionEnglish = QtWidgets.QAction()
        menuLanguage.addAction(self.actionGerman)
        menuLanguage.addAction(self.actionEnglish)

        #file actions
        self.actionNew = QtWidgets.QAction()
        self.actionSave = QtWidgets.QAction()
        self.actionSaveAs = QtWidgets.QAction()
        self.actionLoad = QtWidgets.QAction()
        self.actionPrint = QtWidgets.QAction()

        menuFile.addAction(self.actionNew)
        menuFile.addAction(self.actionSave)
        menuFile.addAction(self.actionSaveAs)
        menuFile.addAction(self.actionLoad)
        menuFile.addSeparator()
        menuFile.addAction(self.actionPrint)

        #modus actions
        self.actionModusU = QtWidgets.QAction()
        self.actionModusTemp = QtWidgets.QAction()

        self.actionModusU.triggered.connect(self.modusSwitchToU)
        self.actionModusTemp.triggered.connect(self.modusSwitchToTemp)

        self.menuModus.addAction(self.actionModusU)
        self.menuModus.addAction(self.actionModusTemp)
        self.menuModus.menuAction().setEnabled(False)



        #assemble menubar
        bar.addAction(menuFile.menuAction())
        bar.addAction(menuLanguage.menuAction())
        bar.addAction(self.menuModus.menuAction())

        bar.setMaximumHeight(30)

        #mainLayout.addWidget(self.menuBar)

        #tab widget
        self.tabWidget = QtWidgets.QTabWidget()
        self.tabWidget.setTabsClosable(True)
        self.tabWidget.setMovable(False)
        self.tabWidget.setMinimumHeight(600)
        self.tabWidget.setMinimumWidth(800)

        self.newTab = NewTab()
        self.tabWidget.addTab(self.newTab, "+")
        self.tabWidget.tabBar().tabButton(0,QtWidgets.QTabBar.RightSide).resize(0,0)

        self.tabWidget.currentChanged.connect(self.activateModusMenu)
        self.tabWidget.tabCloseRequested.connect(self.closeTab)


        self.setCentralWidget(self.tabWidget)

        self.retranslateUi()

        self.move(0,0)
        self.show()

    def activateModusMenu(self):
        if(self.tabWidget.currentIndex()==(self.tabWidget.count()-1)):
            self.menuModus.menuAction().setEnabled(False)
        else:
            self.menuModus.menuAction().setEnabled(True)

    def addNewTab(self, modus):
        tab = Tab (modus, QtCore.QCoreApplication.translate("MainWindow","Neuer Tab"))
        self.tabWidget.insertTab(self.tabWidget.count()-1,tab, tab.data.name)
        self.tabWidget.setCurrentIndex(self.tabWidget.count()-2)

    def closeTab(self,index):
        self.tabWidget.removeTab(index)

    def modusSwitchToU(self):
        self.tabWidget.currentWidget().switchToU()

    def modusSwitchToTemp(self):
        self.tabWidget.currentWidget().switchToTemp()

    def retranslateUi(self):

        _translate = QtCore.QCoreApplication.translate
        #language options
        self.actionGerman.setText(_translate("MainWindow", "Deutsch"))
        self.actionEnglish.setText(_translate("MainWindow", "English"))
        #file options
        self.actionSave.setText(_translate("MainWindow", "Speichern"))
        self.actionSave.setShortcut(_translate("MainWindow", "Ctrl+S"))
        self.actionSaveAs.setText(_translate("MainWindow", "Speichern unter..."))
        self.actionLoad.setText(_translate("MainWindow", "Laden"))
        self.actionPrint.setText(_translate("MainWindow", "Drucken"))
        self.actionPrint.setShortcut(_translate("MainWindow", "Ctrl+P"))
        self.actionNew.setText(_translate("MainWindow", "Neu"))
        self.actionNew.setShortcut(_translate("MainWindow", "Ctrl+N, Ctrl+T"))
        #modus options
        self.actionModusU.setText(_translate("MainWindow","U berechnen"))
        self.actionModusTemp.setText(_translate("MainWindow","Temperaturkurve berechnen"))




