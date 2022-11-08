from sorts_base import Sorts
import sys
from random import randint
import time
from tqdm import tqdm


class Main:
    def __init__(self):
        self.sortslib = None
        self.Sorts_method_list = None
        print('Start Environment')
        self.dict_func = {}
        self.test_massive = [randint(0, 1000000) for i in range(randint(100, 10000))]

        # trying to connect with included libraries
        self.connect()

    def connect(self):
        try:
            self.sortslib
            self.sortslib = Sorts()
            self.Sorts_method_list = [method for method in dir(Sorts) if method.startswith('__') is False]
            print('There are:', len(self.Sorts_method_list), 'included methods')
            for i in tqdm(self.Sorts_method_list):
                time.sleep(1)
            print('Connection completed')
        except:
            print('Connection failed:')
            print('An error occurred while trying to load the sorts from .../sorts_base.py')
            print('Check it out in your folder.')
            sys.exit(1)
        self.operations()

    def operations(self):
        self.t_clear()
        print('Waiting for your command (sorts):')
        oper = input("$ ")
        if oper == 'help':
            print('Available commands at this step: ')
            print('I don"t want to write documentation, I"m a lazy ass.')
            print('Or push something another for turn back.')
            self.operations()
        if oper == 'exit':
            self.exit(1)
        if oper == 'sorts':
            print('Available commands at this step: ')
            print('<sorts list>/<sorts stress test> .. or push something another for turn back.')
            input_sort = input('$ ')


            if input_sort == 'sorts list':
                flag_to_change_test_massive = input('A u want to change test massive? Y/n:')
                if flag_to_change_test_massive in ['Y', 'y']:
                    self.test_massive = list(map(int, input('Enter your test massive: ').split()))
                    print('Your massive saved.')
                print('There are: ', self.Sorts_method_list)
                print('If you want to use any sorting - select it from the list.')
                input_sort2 = input('$ ')
                if input_sort2 == 'insertion':
                    print(self.sortslib.insertion(self.test_massive))
                    self.operations()
                if input_sort2 == 'quicksort':
                    print(self.sortslib.quicksort(self.test_massive))
                else:
                    print('Turning back...')
                    self.operations()

            if input_sort == 'sorts stress test':
                flag_to_change_test_massive = input('A u want to change test massive? Y/n:')
                if flag_to_change_test_massive in ['Y', 'y']:
                    self.test_massive = list(map(int, input('Enter your test massive: ').split()))
                    print('Your massive saved.')
                print('Quicksort test: ', self.sortslib.quicksort(self.test_massive))
                print('Insertion test: ', self.sortslib.insertion(self.test_massive))
                self.operations()

                self.operations()
            else:
                print('Command not find...')
                print('Turning back...')
                self.operations()
        if oper not in self.Sorts_method_list:
            print('Oops... Try another command!')
            self.operations()

    # ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    def t_clear(self):
        print(' ')
        print('----------------------------------------')
        print(' ')
        return

    def exit(self, code):
        print('Emergency stop | Code: ', code)
        print('Session closed.')
        self.t_clear()
        sys.exit(code)


# ----------------------------------------------------------

if __name__ == '__main__':
    try:
        Main()
    except:
        print('Something totally unexpected.')
        sys.exit(404)
