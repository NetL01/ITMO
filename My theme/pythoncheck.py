from datetime import datetime
from colorama import Fore


def custom_print(*args, **kwargs):
    print(datetime.utcnow(), *args, **kwargs)
    return

custom_print()


class Dog:
    __slots__ = []
    def __init__(self):
        pass
print(">"+"hello".center(20)+"<")
# print(assert 2 == 1)
print(Fore.MAGENTA + "dima pidor")
CURSOR_UP = "\033[1A"
CLEAR = "\x1b[2K"
# print(CURSOR_UP)
print(CLEAR)
A = input()
a = float("inf")
print(a)
