class Fridge:
    def __init__(self):
        self.storage = {'milk': 1000, 'meat': 1000, 'peaces_of_cheese': 1000,
                        'gummy_bears': 1000}
        # self.part_of_day = self.get_day_time()
        print('Fridge started')
        print('Use: take/put/check')
        self.operations()

    def operations(self):
        print('------------------------------------------------------')
        a = input("$ ")

        if a == 'check':
            self.check()
        if a == 'take':
            self.take()
        if a == 'put':
            self.put()
        if a == 'exit':
            self.exit()
        if a not in ['check', 'take', 'put']:
            print('There are no function to do what you want yet.')
            print('Try check/put/take/exit.')
            self.operations()

    def check(self):
        print('Currently in your fridge: ')
        for key, value in self.storage.items():
            print("{0}: {1}".format(key, value))
        self.operations()

    def take(self):
        print('Product names: ', list(self.storage.keys()))
        print('Format: <type of eat> <how to take>')
        command = input().split()
        try:
            storage_now = self.storage[command[0]]
            if self.storage[command[0]] - int(command[1]) >= 0:
                self.storage[command[0]] -= int(command[1])
                print('Success! |', storage_now, '-->', self.storage[command[0]])
                self.operations()
            else:
                print('Make sure you dont take too much food')
                self.operations()
        except:
            print('Enter the data in the correct format')
            self.operations()

    def put(self):
        print('Product names: ', list(self.storage.keys()))
        print('Format: <type of eat> <how to put>')
        command = input().split()
        try:
            storage_now = self.storage[command[0]]
            # на случай, если кто-то захочет положить отрицательное количество
            if self.storage[command[0]] + int(command[1]) >= 0:
                self.storage[command[0]] += int(command[1])
                print('Success! |', storage_now, '-->', self.storage[command[0]])
                self.operations()
            else:
                print('Something went wrong???...')
                self.operations()
        except:
            print('Enter the data in the correct format')
            self.operations()


if __name__ == "__main__":
    print('Welcome to the Fridge by NetL01')
    Fridge()
