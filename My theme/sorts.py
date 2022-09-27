from sorts_base import Sorts
import sys

class Main:
    def __init__(self):
        print('Start Operations')
        sortslib = Sorts()
        self.dict_func = {}
        self.Sorts_method_list = [method for method in dir(Sorts) if method.startswith('__') is False]

        try:
            sortslib
        except:
            print('An error occurred while trying to load the sorts from ../sorts_base.py.')
            print('Check it out in your folder.')
            sys.exit(1)
        self.operations()

    def operations(self):
        oper = input("$ ")
        if oper == 'help':
            print('Available commands at this step: ')
            print('...')
            print('Or push something another for turn back.')
            self.operations()
        if oper == 'sorts':
            print('Available commands at this step: ')
            print('sorts list/ .. or push something another for turn back.')
            oper = input('$ ')
            if oper == 'sorts list':
                print('There are: ', self.Sorts_method_list)
                print('If you want to use any sorting - select it from the list.')
                self.operations()
            else:
                print('Turning back...')
                self.operations()
        if oper not in self.Sorts_method_list:
            print('Oops... Try another command!')
            self.operations()

    def t_clear(self):
        print(' ')
        print('----------------------------------------')
        print(' ')
        return



# ----------------------------------------------------------

if __name__ == '__main__':
    Main()