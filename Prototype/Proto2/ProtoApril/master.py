# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'master.ui'
#
# Created by: PyQt5 UI code generator 5.14.2
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1065, 842)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.tabWidget = QtWidgets.QTabWidget(self.centralwidget)
        self.tabWidget.setGeometry(QtCore.QRect(10, 10, 1051, 781))
        self.tabWidget.setTabsClosable(True)
        self.tabWidget.setMovable(True)
        self.tabWidget.setObjectName("tabWidget")
        self.tab = QtWidgets.QWidget()
        self.tab.setObjectName("tab")
        self.widgetTabContent = QtWidgets.QWidget(self.tab)
        self.widgetTabContent.setGeometry(QtCore.QRect(0, 0, 1051, 781))
        self.widgetTabContent.setLocale(QtCore.QLocale(QtCore.QLocale.German, QtCore.QLocale.Germany))
        self.widgetTabContent.setObjectName("widgetTabContent")
        self.ScrollCircumstances = QtWidgets.QScrollArea(self.widgetTabContent)
        self.ScrollCircumstances.setGeometry(QtCore.QRect(10, 10, 441, 311))
        self.ScrollCircumstances.setWidgetResizable(True)
        self.ScrollCircumstances.setObjectName("ScrollCircumstances")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 439, 309))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.WidgetTemp = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.WidgetTemp.setGeometry(QtCore.QRect(0, 0, 441, 91))
        self.WidgetTemp.setLocale(QtCore.QLocale(QtCore.QLocale.German, QtCore.QLocale.Germany))
        self.WidgetTemp.setObjectName("WidgetTemp")
        self.label = QtWidgets.QLabel(self.WidgetTemp)
        self.label.setGeometry(QtCore.QRect(20, 10, 47, 13))
        self.label.setObjectName("label")
        self.label_2 = QtWidgets.QLabel(self.WidgetTemp)
        self.label_2.setGeometry(QtCore.QRect(90, 10, 47, 13))
        self.label_2.setObjectName("label_2")
        self.doubleSpinBoxTempOut = QtWidgets.QDoubleSpinBox(self.WidgetTemp)
        self.doubleSpinBoxTempOut.setGeometry(QtCore.QRect(180, 10, 62, 22))
        self.doubleSpinBoxTempOut.setToolTipDuration(3)
        self.doubleSpinBoxTempOut.setObjectName("doubleSpinBoxTempOut")
        self.label_3 = QtWidgets.QLabel(self.WidgetTemp)
        self.label_3.setGeometry(QtCore.QRect(280, 10, 47, 13))
        self.label_3.setObjectName("label_3")
        self.label_4 = QtWidgets.QLabel(self.WidgetTemp)
        self.label_4.setGeometry(QtCore.QRect(90, 50, 47, 13))
        self.label_4.setObjectName("label_4")
        self.doubleSpinBoxTempIn = QtWidgets.QDoubleSpinBox(self.WidgetTemp)
        self.doubleSpinBoxTempIn.setGeometry(QtCore.QRect(180, 50, 62, 22))
        self.doubleSpinBoxTempIn.setToolTipDuration(3)
        self.doubleSpinBoxTempIn.setObjectName("doubleSpinBoxTempIn")
        self.label_5 = QtWidgets.QLabel(self.WidgetTemp)
        self.label_5.setGeometry(QtCore.QRect(280, 50, 47, 13))
        self.label_5.setObjectName("label_5")
        self.widget = QtWidgets.QWidget(self.scrollAreaWidgetContents)
        self.widget.setGeometry(QtCore.QRect(0, 90, 441, 71))
        self.widget.setObjectName("widget")
        self.label_6 = QtWidgets.QLabel(self.widget)
        self.label_6.setObjectName("label_6")
        self.ScrollCircumstances.setWidget(self.scrollAreaWidgetContents)
        self.graphicsView = QtWidgets.QGraphicsView(self.widgetTabContent)
        self.graphicsView.setGeometry(QtCore.QRect(460, 10, 571, 311))
        self.graphicsView.setObjectName("graphicsView")
        self.ButtonGraph = QtWidgets.QPushButton(self.widgetTabContent)
        self.ButtonGraph.setGeometry(QtCore.QRect(10, 340, 75, 23))
        self.ButtonGraph.setToolTip("")
        self.ButtonGraph.setToolTipDuration(3)
        self.ButtonGraph.setWhatsThis("")
        self.ButtonGraph.setLocale(QtCore.QLocale(QtCore.QLocale.German, QtCore.QLocale.Germany))
        self.ButtonGraph.setCheckable(False)
        self.ButtonGraph.setAutoDefault(False)
        self.ButtonGraph.setDefault(False)
        self.ButtonGraph.setFlat(False)
        self.ButtonGraph.setObjectName("ButtonGraph")
        self.scrollArea = QtWidgets.QScrollArea(self.widgetTabContent)
        self.scrollArea.setGeometry(QtCore.QRect(10, 380, 1021, 351))
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents_2 = QtWidgets.QWidget()
        self.scrollAreaWidgetContents_2.setObjectName("scrollAreaWidgetContents_2")
        self.scrollArea.setWidget(self.scrollAreaWidgetContents_2)
        self.AddLayerButton = QtWidgets.QPushButton(self.widgetTabContent)
        self.AddLayerButton.setGeometry(QtCore.QRect(950, 350, 75, 23))
        self.AddLayerButton.setObjectName("AddLayerButton")
        self.tabWidget.addTab(self.tab, "")
        self.tab_2 = QtWidgets.QWidget()
        self.tab_2.setObjectName("tab_2")
        self.tabWidget.addTab(self.tab_2, "")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1065, 21))
        self.menubar.setObjectName("menubar")
        self.menuLanguage = QtWidgets.QMenu(self.menubar)
        self.menuLanguage.setObjectName("menuLanguage")
        self.menuDatei = QtWidgets.QMenu(self.menubar)
        self.menuDatei.setObjectName("menuDatei")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionDeutsch = QtWidgets.QAction(MainWindow)
        self.actionDeutsch.setObjectName("actionDeutsch")
        self.actionEnglish = QtWidgets.QAction(MainWindow)
        self.actionEnglish.setObjectName("actionEnglish")
        self.actionSpeichern = QtWidgets.QAction(MainWindow)
        self.actionSpeichern.setObjectName("actionSpeichern")
        self.actionSpeichern_unter = QtWidgets.QAction(MainWindow)
        self.actionSpeichern_unter.setObjectName("actionSpeichern_unter")
        self.actionLaden = QtWidgets.QAction(MainWindow)
        self.actionLaden.setObjectName("actionLaden")
        self.actionDrucken = QtWidgets.QAction(MainWindow)
        self.actionDrucken.setObjectName("actionDrucken")
        self.actionNeu = QtWidgets.QAction(MainWindow)
        self.actionNeu.setObjectName("actionNeu")
        self.menuLanguage.addAction(self.actionDeutsch)
        self.menuLanguage.addAction(self.actionEnglish)
        self.menuDatei.addAction(self.actionNeu)
        self.menuDatei.addAction(self.actionSpeichern)
        self.menuDatei.addAction(self.actionSpeichern_unter)
        self.menuDatei.addAction(self.actionLaden)
        self.menuDatei.addSeparator()
        self.menuDatei.addAction(self.actionDrucken)
        self.menubar.addAction(self.menuDatei.menuAction())
        self.menubar.addAction(self.menuLanguage.menuAction())

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.WidgetTemp.setToolTip(_translate("MainWindow", "Temperatur in °C"))
        self.label.setText(_translate("MainWindow", "Temp"))
        self.label_2.setText(_translate("MainWindow", "außen"))
        self.doubleSpinBoxTempOut.setToolTip(_translate("MainWindow", "Temperatur in °C"))
        self.label_3.setText(_translate("MainWindow", "°C"))
        self.label_4.setText(_translate("MainWindow", "innen"))
        self.doubleSpinBoxTempIn.setToolTip(_translate("MainWindow", "Temperatur in °C"))
        self.label_5.setText(_translate("MainWindow", "°C"))
        self.label_6.setText(_translate("MainWindow", "andere Daten"))
        self.ButtonGraph.setStatusTip(_translate("MainWindow", "Zeigt einen Graphen an"))
        self.ButtonGraph.setText(_translate("MainWindow", "Visualisieren"))
        self.AddLayerButton.setText(_translate("MainWindow", "Hinzufügen"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab), _translate("MainWindow", "Tab 1"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_2), _translate("MainWindow", "Tab 2"))
        self.menuLanguage.setTitle(_translate("MainWindow", "Sprache"))
        self.menuDatei.setTitle(_translate("MainWindow", "Datei"))
        self.actionDeutsch.setText(_translate("MainWindow", "Deutsch"))
        self.actionEnglish.setText(_translate("MainWindow", "English"))
        self.actionSpeichern.setText(_translate("MainWindow", "Speichern"))
        self.actionSpeichern.setShortcut(_translate("MainWindow", "Ctrl+S"))
        self.actionSpeichern_unter.setText(_translate("MainWindow", "Speichern unter..."))
        self.actionLaden.setText(_translate("MainWindow", "Laden"))
        self.actionDrucken.setText(_translate("MainWindow", "Drucken"))
        self.actionDrucken.setShortcut(_translate("MainWindow", "Ctrl+P"))
        self.actionNeu.setText(_translate("MainWindow", "Neu"))
        self.actionNeu.setShortcut(_translate("MainWindow", "Ctrl+N, Ctrl+T"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
