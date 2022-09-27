class Sorts:
    def __init__(self):
        self.feedback()
        return

    def feedback(self):
        print('Sorts list loaded')

    def quicksort(self, data):
        if len(data) <= 1:
            return data
        border = data[0]
        left = list(filter(lambda x: x < border, data))
        center = [x for x in data if x == border]
        right = list(filter(lambda x: x > border, data))
        return self.quick_sort(left) + center + self.quick_sort(right)

    # to do
    def quicksort_help(self, data):
        if len(data) <= 1:
            return data
        border = data[0]
        left = list(filter(lambda x: x < border, data))
        center = [x for x in data if x == border]
        right = list(filter(lambda x: x > border, data))
        return self.quicksort(left) + center + self.quicksort(right)

    # ----------------------------------------------------------

    def insertion(self, data):
        for i in range(len(data)):
            j = i - 1
            key = data[i]
            while data[j] > key and j >= 0:
                data[j + 1] = data[j]
                j -= 1
            data[j + 1] = key
        return data

    def insertion_help(self, data):
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