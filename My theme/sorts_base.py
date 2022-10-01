import time



class Sorts:
    def __init__(self):
        self.feedback()
        return

    def feedback(self):
        print('Sorts list loaded')
        return

    def quicksort(self, data):
        if len(data) <= 1:
            return data
        border = data[0]
        left = list(filter(lambda x: x < border, data))
        center = [x for x in data if x == border]
        right = list(filter(lambda x: x > border, data))
        return self.quick_sort(left) + center + self.quick_sort(right)

    # to do
    def quicksort_by_step(self, data):
        if len(data) <= 1:
            return data
        border = data[0]
        left = list(filter(lambda x: x < border, data))
        center = [x for x in data if x == border]
        right = list(filter(lambda x: x > border, data))
        return self.quicksort_by_step(left) + center + self.quicksort_by_step(right)

    # ----------------------------------------------------------

    def insertion(self, data):
        start_time = time.time()
        print(start_time)
        for i in range(len(data)):
            j = i - 1
            key = data[i]
            while data[j] > key and j >= 0:
                data[j + 1] = data[j]
                j -= 1
            data[j + 1] = key
        print(data)
        a = time.time()
        print(a)
        print("--- %s seconds ---" % (time.time() - start_time))
        return


    def insertion_by_step(self, data):
        step = 1
        for i in range(len(data)):
            j = i - 1
            key = data[i]
            while data[j] > key and j >= 0:
                data[j + 1] = data[j]
                j -= 1
            data[j + 1] = key
            if j != -1 and j != 0:
                print('Step:', step, ':', data)
                step += 1
        return data