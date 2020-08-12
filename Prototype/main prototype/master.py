# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore, QtWidgets, QtGui
from Tab import Tab
from NewTab import NewTab
from Printing import Print
from Parser import Parser
from Exporter import Exporter


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super(MainWindow,self).__init__()


        #menu bar
        bar=self.menuBar()
        """top menuBar"""
        self.menuBar().setStyleSheet("""
        QMenuBar{
        color: rgb(255, 255, 255);
        background-color: #4C7CC2;
        }
        QMenuBar:item:selected {
        border: 1px solid #333333;
        color: rgb(255, 255, 255);
        background-color: #224579;
        }
        QMenuBar:disabled{
        color: rgb(150, 150, 150);
        }
        QMenu{
        background-color: #ffffff;
        color: rgb(0,0,0);
        }
        QMenu:item:selected{
        color: rgb(0, 0, 0);
        background-color: #A0BEEA;
        }
        QMenu:item:disabled{
        color: rgb(150, 150, 150);
        };
        """)

        self.menuFile = bar.addMenu(QtCore.QCoreApplication.translate("MainWindow","Datei"))
        """File menu"""
        menuLanguage = bar.addMenu(QtCore.QCoreApplication.translate("MainWindow","Sprache"))
        """Language menu"""
        self.menuModus = bar.addMenu(QtCore.QCoreApplication.translate("MainWindow","Modus"))
        """Mode menu"""

        #language actions
        self.actionGerman = QtWidgets.QAction()
        """German action"""
        self.actionEnglish = QtWidgets.QAction()
        """English action"""
        menuLanguage.addAction(self.actionGerman)
        menuLanguage.addAction(self.actionEnglish)

        #file actions
        self.actionNew = QtWidgets.QAction()
        """New (File) action"""
        self.actionSave = QtWidgets.QAction()
        """Save (File) action"""
        self.actionSaveAs = QtWidgets.QAction()
        """Save As (File) action"""
        self.actionLoad = QtWidgets.QAction()
        """Open (File) action"""
        self.actionPrint = QtWidgets.QAction()
        """Print (File) action """

        self.actionPrint.triggered.connect(self.printing)
        self.actionNew.triggered.connect(self.switchToNewTab)
        self.actionSave.triggered.connect(self.quickSave)
        self.actionSaveAs.triggered.connect(self.saveAs)
        self.actionLoad.triggered.connect(self.openFile)

        self.menuFile.addAction(self.actionNew)
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionSaveAs)
        self.menuFile.addAction(self.actionLoad)
        self.menuFile.addSeparator()
        self.menuFile.addAction(self.actionPrint)

        self.menuFile.actions()[1].setEnabled(False)
        self.menuFile.actions()[2].setEnabled(False)
        self.menuFile.actions()[5].setEnabled(False)

        #modus actions
        self.actionModusU = QtWidgets.QAction()
        """U (Mode) action"""
        self.actionModusTemp = QtWidgets.QAction()
        """Temp (Mode) action"""

        self.actionModusU.triggered.connect(self.modusSwitchToU)
        self.actionModusTemp.triggered.connect(self.modusSwitchToTemp)

        self.menuModus.addAction(self.actionModusU)
        self.menuModus.addAction(self.actionModusTemp)
        self.menuModus.menuAction().setEnabled(False)



        #assemble menubar
        bar.addAction(self.menuFile.menuAction())
        bar.addAction(menuLanguage.menuAction())
        bar.addAction(self.menuModus.menuAction())

        bar.setMaximumHeight(30)

        #mainLayout.addWidget(self.menuBar)

        #tab widget
        self.tabWidget = QtWidgets.QTabWidget()
        """tabWidget which holds the core application"""
        self.tabWidget.setTabsClosable(True)
        self.tabWidget.setMovable(False)
        self.tabWidget.setMinimumHeight(600)
        self.tabWidget.setMinimumWidth(800)

        self.newTab = NewTab()
        """New Tab page"""
        self.tabWidget.addTab(self.newTab, "+")
        self.tabWidget.tabBar().tabButton(0,QtWidgets.QTabBar.RightSide).resize(0,0)

        self.tabWidget.currentChanged.connect(self.activateMenues)
        self.tabWidget.tabCloseRequested.connect(self.closeTab)


        self.setCentralWidget(self.tabWidget)

        self.retranslateUi()

        self.move(0,0)
        self.show()

    def activateMenues(self):
        """changes the availability of actions according to whether a normal tab or the New Tab page is in focus"""
        if(self.tabWidget.currentIndex()==(self.tabWidget.count()-1)):
            self.menuModus.menuAction().setEnabled(False)
            self.menuFile.actions()[1].setEnabled(False)
            self.menuFile.actions()[2].setEnabled(False)
            self.menuFile.actions()[5].setEnabled(False)
        else:
            self.menuModus.menuAction().setEnabled(True)
            self.menuFile.actions()[1].setEnabled(True)
            self.menuFile.actions()[2].setEnabled(True)
            self.menuFile.actions()[5].setEnabled(True)


    def addNewTab(self, modus, tabData=None):
        """adds new tab"""
        if(tabData is None):
            tab = Tab (modus, QtCore.QCoreApplication.translate("MainWindow","Neuer Tab"))
            self.tabWidget.insertTab(self.tabWidget.count()-1,tab, QtCore.QCoreApplication.translate("MainWindow","Neuer Tab"))
        else:
            tab = Tab (modus, tabData.name, tabData)
            self.tabWidget.insertTab(self.tabWidget.count()-1,tab, QtCore.QCoreApplication.translate("MainWindow",tabData.name))
        self.tabWidget.setCurrentIndex(self.tabWidget.count()-2)

    def closeTab(self,index):
        """closes Tab at index"""
        self.tabWidget.widget(index).removeSelf()
        self.tabWidget.removeTab(index)

    def modusSwitchToU(self):
        """switches current tab to U mode"""
        self.tabWidget.currentWidget().switchToU()

    def modusSwitchToTemp(self):
        """switches current tab to Temp mode"""
        self.tabWidget.currentWidget().switchToTemp()

    def printing(self):
        """opens Print dialogue"""
        print = Print(self.tabWidget.currentWidget())
        print.handlePreview()

    def saveAs(self):
        """opens Save File dialogue and saves current tab as a File"""
        tr = QtCore.QCoreApplication.translate
        fileName = QtWidgets.QFileDialog.getSaveFileName(self, tr("SaveDialog:", "Berechnung speichern"), "", tr("SaveDialog:","Bauphysikberechnung (*.baup);;Alle Dateien (*)"))
        if(all(fileName)):
            file = QtCore.QFile(fileName[0])
            if(not file.open(QtCore.QIODevice.WriteOnly)):
                QtWidgets.QMessageBox.Information(self, tr("SaveDialog:", "Datei kann nicht geöffnet werden"), file.errorString())
                return
            fileNameStringWithEnding= fileName[0].split("/")
            fileNameStringWithEnding=fileNameStringWithEnding[len(fileNameStringWithEnding)-1]
            fileNameStringWithEnding=fileNameStringWithEnding.split(".")
            fileNameString=""
            for x in range(len(fileNameStringWithEnding)-1):
                if x == 0:
                 fileNameString+=fileNameStringWithEnding[x]
                else:
                    fileNameString+="."+fileNameStringWithEnding[x]
            self.tabWidget.currentWidget().data.name = fileNameString
            self.tabWidget.currentWidget().data.currentFileLocation = fileName[0]
            exp = Exporter(self.tabWidget.currentWidget().data)
            exp.export(fileName[0])
            self.updateName()
        else:
            return

    def updateName(self):
        """updates name of current tab"""
        name = self.tabWidget.currentWidget().data.name
        self.tabWidget.setTabText(self.tabWidget.currentIndex(), name)

    def quickSave(self):
        """saves current tab. If it has not been saved previously, opens Save As dialogue"""
        if self.tabWidget.currentWidget().data.currentFileLocation is None:
            self.saveAs()
        else:
            exp = Exporter(self.tabWidget.currentWidget().data)
            exp.export(self.tabWidget.currentWidget().data.currentFileLocation)

    def openFile(self):
        """opens Open File dialogue"""
        tr = QtCore.QCoreApplication.translate
        fileName = QtWidgets.QFileDialog.getOpenFileName(self,tr("OpenDialog:", "Berechnung öffnen"), "", tr("OpenDialog:","Bauphysikberechnung (*.baup);;Alle Dateien (*)"))
        if(all(fileName)):
            file = QtCore.QFile(fileName[0])
            if(not file.open(QtCore.QIODevice.ReadOnly)):
                QtWidgets.QMessageBox.Information(self, tr("OpenDialog:", "Datei kann nicht geöffnet werden"), file.errorString())
                return

            parser = Parser(fileName[0])
            tabdata = parser.parse()
            self.addNewTab(tabdata.mode,tabdata)
            self.tabWidget.currentWidget().data.currentFileLocation = fileName[0]



    def switchToNewTab(self):
        """switches to New Tab tab"""
        self.tabWidget.setCurrentIndex(self.tabWidget.count()-1)

    def retranslateUi(self):
        _translate = QtCore.QCoreApplication.translate
        #language options
        self.actionGerman.setText(_translate("MainWindow", "Deutsch"))
        self.actionEnglish.setText(_translate("MainWindow", "English"))
        #file options
        self.actionSave.setText(_translate("MainWindow", "Speichern"))
        self.actionSave.setShortcut(_translate("MainWindow", "Ctrl+S"))
        self.actionSaveAs.setText(_translate("MainWindow", "Speichern unter..."))
        self.actionLoad.setText(_translate("MainWindow", "Öffnen"))
        self.actionPrint.setText(_translate("MainWindow", "Drucken"))
        self.actionPrint.setShortcut(_translate("MainWindow", "Ctrl+P"))
        self.actionNew.setText(_translate("MainWindow", "Neu"))
        self.actionNew.setShortcut(_translate("MainWindow", "Ctrl+T"))
        #modus options
        self.actionModusU.setText(_translate("MainWindow","U berechnen"))
        self.actionModusTemp.setText(_translate("MainWindow","Temperaturkurve berechnen"))




