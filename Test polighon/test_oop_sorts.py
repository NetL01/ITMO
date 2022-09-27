import sys
import yadisk
import os
import pyAesCrypt
from os import stat, remove
import random


class YandexDiskOperations():
    def __init__(self):
        self.dict_func = {'ttr': self.ttr, 'p': self.p}

    def p(self):
        pass

    def ttr(self):
        pass
    def additional_func(self):
        # print(locals())
        # print(sys.argv)
        # locals()[sys.argv[1]](sys.argv[2], sys.argv[3])
        # self.dict_func[sys.argv[1]](sys.argv[2], sys.argv[3])
        res = sys.argv[3]
        self.dict_func[sys.argv[1]](sys.argv[2], sys.argv[3])

class InputBox():
    def __init__(self):
        self.smth = YandexDiskOperations()

    def another_func(self):
        self.smth.additional_func()


if __name__ == '__main__':
    # start = YandexDiskOperations()
    location = InputBox()
    location.another_func()
