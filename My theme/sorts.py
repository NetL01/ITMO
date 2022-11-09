from sorts_base import Sorts
import sys
from random import randint
import time
from tqdm import tqdm



class Main:
    def __init__(self):
        self.test_massive = [randint(1, 1000) for i in range(randint(1111, 9999))]
        self.sortslib = None
        self.Sorts_method_list = None
        print('Start Environment')
        self.dict_func = {}


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
        try:
            self.t_clear()
            print('Waiting for your command <test_massive/sorts/stress_test/help/exit...>:')
            oper = input("$ ")
            if oper == 'help':
                print('Nothing will help you.')
                self.operations()
            if oper == 'exit':
                self.exit(1)
            if oper == 'sorts':
                print('Available commands at this step: ')
                print('<sorts list>/<sorts stress test> .. or push something another for turn back.')
                self.aftersorts()
            if oper == 'stress_test':
                self.stress_test()
            if oper == 'test_massive':
                flag_to_change_m = input('Do u want to create your test massive? Y/n: ')
                if flag_to_change_m == 'Y' or flag_to_change_m == 'y':
                    self.set_test_massive()
                else:
                    print('Generated array size:', len(self.test_massive))
                    time.sleep(1)
            else:
                self.operations()
        except:
            print('Some problems <operations stage>')
            self.operations()


    def aftersorts(self):
        # part of sorts
        try:
            type_of_sort = input('Enter you selected sort - <insertion/quicksort/...>')
            if type_of_sort == 'insertion':
                print(self.sortslib.insertion(self.test_massive))
                self.operations()
            if type_of_sort == ' quicksort':
                print(self.sortslib.quicksort(self.test_massive))
                self.operations()
        except:
            print('Some problems <sort selection stage>')
            self.operations()

    def stress_test(self):
        try:
            print('Forming conditions for passing an array through imported sorts')
            for i in tqdm(randint(3, 5)):
                time.sleep(1)
            print('Quicksort test: ', self.sortslib.quicksort(self.test_massive))
            time.sleep(0.5)
            print('Insertion test: ', self.sortslib.insertion(self.test_massive))
            time.sleep(0.5)
            print('Stress test completed')
            self.operations()
        except:
            print('Some problems <stress test stage>')
            self.operations()


    # ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    def set_test_massive(self):
        print('Customizing your input size and type')

        size = input('Enter your desired size: ')
        range_nums = input('Select the desired range of numbers (with a space)')
        lowrange, highrange = range_nums.split()
        self.test_massive = [randint(int(lowrange), int(highrange)) for i in range(int(size))]
        print('Size:', size, 'Value range: from', lowrange, 'to', highrange)
        time.sleep(1)
        print('Combining your massive')
        time.sleep(1)
        for i in tqdm(range(len(self.test_massive))):
            time.sleep(0.0001)
        print('Combining complete')

        #    print('Error creating')

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
