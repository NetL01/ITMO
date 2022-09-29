import sys
import random
from PyQt5.QtWidgets import QWidget, QApplication, QPushButton, QMessageBox
from PyQt5.QtCore import pyqtSignal


class Button(QPushButton):
    mouseMoved = pyqtSignal()

    def mouseMoveEvent(self, event):
        self.mouseMoved.emit()


class Example(QWidget):
    def __init__(self):
        super().__init__()

        self.coords = [40, 40]
        self.btn_size = [120, 40]
        self.d = 15
        self.w = 500
        self.h = 400
        self.setGeometry(300, 300, self.w, self.h)
        self.setWindowTitle('Слыш хуило')

        pybutton = QPushButton("Таня лошара", self)
        pybutton.clicked.connect(self.clickMethod)
        pybutton.resize(100, 32)
        pybutton.move(100, 100)

        self.btn = Button(self)
        self.btn.setMouseTracking(True);
        self.btn.setText("Таня топ <3")
        self.btn.resize(*self.btn_size)
        self.btn.move(*self.coords)
        self.btn.mouseMoved.connect(self.moveButton)
        self.show()

    def clickMethod(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)

        # setting message for Message Box
        msg.setText("Я ТАК И ЗНАЛ")

        # setting Message box window title
        msg.setWindowTitle("КТО ПО ЖИЗНИ УЕБАН")

        # declaring buttons on Message Box
        msg.setStandardButtons(QMessageBox.Ok | QMessageBox.Cancel)

        # start the app
        retval = msg.exec_()

    def moveButton(self):
        self.coords[0] = random.randint(0, self.w - self.btn_size[0])
        self.coords[1] = random.randint(0, self.h - self.btn_size[1])
        self.btn.move(*self.coords)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    ex = Example()
    ex.show()
    sys.exit(app.exec_())