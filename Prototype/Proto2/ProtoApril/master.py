# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore, QtWidgets, QtGui
from Tab import Tab


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(MainWindow,self).__init__()

        bar=self.menuBar()

        menuFile = bar.addMenu(QtCore.QCoreApplication.translate("MainWindow","Datei"))
        menuLanguage = bar.addMenu(QtCore.QCoreApplication.translate("MainWindow","Sprache"))

        self.actionGerman = QtWidgets.QAction()
        self.actionEnglish = QtWidgets.QAction()
        self.actionNew = QtWidgets.QAction()
        self.actionSave = QtWidgets.QAction()
        self.actionSaveAs = QtWidgets.QAction()
        self.actionLoad = QtWidgets.QAction()
        self.actionPrint = QtWidgets.QAction()

        menuLanguage.addAction(self.actionGerman)
        menuLanguage.addAction(self.actionEnglish)
        menuFile.addAction(self.actionNew)
        menuFile.addAction(self.actionSave)
        menuFile.addAction(self.actionSaveAs)
        menuFile.addAction(self.actionLoad)
        menuFile.addSeparator()
        menuFile.addAction(self.actionPrint)


        bar.addAction(menuFile.menuAction())
        bar.addAction(menuLanguage.menuAction())
        bar.setMaximumHeight(20)

        #mainLayout.addWidget(self.menuBar)

        self.tabWidget = QtWidgets.QTabWidget()
        self.tabWidget.setTabsClosable(True)
        self.tabWidget.setMovable(True)
        self.tabWidget.setMinimumHeight(600)
        self.tabWidget.setMinimumWidth(1000)

        self.tab = Tab()
        self.tabWidget.addTab(self.tab, "")


        self.setCentralWidget(self.tabWidget)


        self.retranslateUi()

        self.move(0,0)
        self.show()

    def retranslateUi(self):

        _translate = QtCore.QCoreApplication.translate
        self.actionGerman.setText(_translate("MainWindow", "Deutsch"))
        self.actionEnglish.setText(_translate("MainWindow", "English"))
        self.actionSave.setText(_translate("MainWindow", "Speichern"))
        self.actionSave.setShortcut(_translate("MainWindow", "Ctrl+S"))
        self.actionSaveAs.setText(_translate("MainWindow", "Speichern unter..."))
        self.actionLoad.setText(_translate("MainWindow", "Laden"))
        self.actionPrint.setText(_translate("MainWindow", "Drucken"))
        self.actionPrint.setShortcut(_translate("MainWindow", "Ctrl+P"))
        self.actionNew.setText(_translate("MainWindow", "Neu"))
        self.actionNew.setShortcut(_translate("MainWindow", "Ctrl+N, Ctrl+T"))





