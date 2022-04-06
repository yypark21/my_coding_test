import sys
from PyQt5.QtWidgets import QPushButton, QWidget, QApplication, QLineEdit
import os

path = './train_result/'

def remove_dir(num):
    file_list = os.listdir(path)
    for file in file_list:
        name = file.split('.')[0]
        if len(name.split('-')) == 2 and int(name.split('-')[1]) > num:
            os.remove(path+file)

def modify_checkpointfile(num):
    str = ''
    with open(path + 'checkpoint') as f:
        lines = f.readlines()
        lines[0] = 'model_checkpoint_path: "ckpt-%d"\n'%num
        new_lines = lines[ : num + 1 ] + lines[ int(len(lines)/2) : int(len(lines)/2) + num ]
        new_lines.append(lines[-1])
    for i in new_lines:
        str += ''.join(i)
    with open(path + 'checkpoint', 'w') as f :
        f.write(str)


class Ui_MainWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.setupUi()

    def setupUi(self):
        self.setWindowTitle('train_result_converter')
        self.resize(300, 120)
        self.line_edit = QLineEdit(self)
        self.line_edit.move(75,35)
        self.button = QPushButton(self)
        self.button.move(75, 75)
        self.button.setText('확인')
        self.button.clicked.connect(self.button_event)
        self.show()

    def button_event(self):
        text = self.line_edit.text() # line_edit text 값 가져오기
        if text is not '':
            remove_dir(int(text))
            modify_checkpointfile(int(text))
        sys.exit()


def main():
    app = QApplication(sys.argv)
    ui = Ui_MainWindow()
    sys.exit(app.exec_())

if __name__=="__main__":
    main()
    
