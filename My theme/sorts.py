from sorts_base import Sorts
import sys

class Main:
    def __init__(self):
        print('Start Operations')
        self.sortslib = Sorts()
        self.dict_func = {}
        self.Sorts_method_list = [method for method in dir(Sorts) if method.startswith('__') is False]
        self.test_massive = []

        try:
            self.sortslib
        except:
            print('An error occurred while trying to load the sorts from ../sorts_base.py.')
            print('Check it out in your folder.')
            sys.exit(1)
        self.operations()

    def operations(self):
        self.t_clear()
        print('Waiting for your command:')
        oper = input("$ ")
        if oper == 'help':
            print('Available commands at this step: ')
            print('I don"t want to write documentation, I"m a lazy ass.')
            print('Or push something another for turn back.')
            self.operations()
        if oper =='exit':
            self.exit(1)
        if oper == 'sorts':
            print('Available commands at this step: ')
            print('sorts list/ .. or push something another for turn back.')
            input_sort = input('$ ')
            if input_sort == 'sorts list':
                flag_to_change_test_massive = input('A u want to change test massive? Y/n:')
                if flag_to_change_test_massive in ['Y', 'y']:
                    self.test_massive = list(map(int, input('Enter your test massive: ').split()))
                    print('Your massive saved')
                print('There are: ', self.Sorts_method_list)
                print('If you want to use any sorting - select it from the list.')
                input_sort2 = input('$ ')
                if input_sort2 == 'insertion':
                    print(self.sortslib.insertion(self.test_massive))
                    self.operations()
                else:
                    print('Turning back...')
                    self.operations()

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