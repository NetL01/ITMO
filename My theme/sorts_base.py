import time


class Sorts:
    def __init__(self):
        self.feedback()
        return

    def feedback(self):
        print('<Sorts feedback>')
        return

# QUICKSORT ////////////////////////////////////////////////////////////////////////////////////////////////////////////
    def quicksort(self, data):
        start_time = time.time()
        self.quicksort_do(data)
        print("--- %s seconds ---" % (time.time() - start_time))

    def quicksort_do(self, data):
        if len(data) <= 1:
            return data
        border = data[0]
        left = list(filter(lambda x: x < border, data))
        center = [x for x in data if x == border]
        right = list(filter(lambda x: x > border, data))
        return self.quicksort_do(left) + center + self.quicksort_do(right)

    # to do

#INSERTION//////////////////////////////////////////////////////////////////////////////////////////////////////////////

    def insertion(self, data):
        start_time = time.time()
        self.insertion_do(data)
        print("--- %s seconds ---" % (time.time() - start_time))

    def insertion_do(self, data):
        for i in range(len(data)):
            j = i - 1
            key = data[i]
            while data[j] > key and j >= 0:
                data[j + 1] = data[j]
                j -= 1
            data[j + 1] = key
        return