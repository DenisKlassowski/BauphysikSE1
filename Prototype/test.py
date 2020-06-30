from PyQt5 import QtCore, QtGui,QtWidgets
from PyQt5.QtCore import *
from PyQt5.QtGui import *
import sys

class PicButton(QtWidgets.QAbstractButton):
    def __init__(self, pixmap, pixmap_hover, pixmap_pressed, parent=None):
        super(PicButton, self).__init__(parent)
        self.pixmap = pixmap
        self.pixmap_hover = pixmap_hover
        self.pixmap_pressed = pixmap_pressed

        self.pressed.connect(self.update)
        self.released.connect(self.update)

    def paintEvent(self, event):
        pix = self.pixmap_hover if self.underMouse() else self.pixmap
        if self.isDown():
            pix = self.pixmap_pressed

        painter = QtGui.QPainter(self)
        painter.drawPixmap(event.rect(), pix)

    def enterEvent(self, event):
        self.update()

    def leaveEvent(self, event):
        self.update()

    def sizeHint(self):
        return QtCore.QSize(200, 200)


app = QtWidgets.QApplication(sys.argv)
window = QtWidgets.QWidget()
layout = QtWidgets.QHBoxLayout(window)

button = PicButton(QtGui.QPixmap("images/1.png"), QtGui.QPixmap("images/2.png"), QtGui.QPixmap("images/3.png"))
layout.addWidget(button)

window.show()
sys.exit(app.exec_())