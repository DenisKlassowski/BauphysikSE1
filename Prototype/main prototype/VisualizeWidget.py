# This Python file uses the following encoding: utf-8
from PyQt5 import QtCore
from PyQt5 import QtWidgets


class VisualizeWidget(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)
        layout = QtWidgets.QVBoxLayout()

        self.placeholderLabel = QtWidgets.QLabel()
        self.placeholderLabel.setText("this is a placeholder")

        layout.addWidget(self.placeholderLabel)

        self.setLayout(layout)

