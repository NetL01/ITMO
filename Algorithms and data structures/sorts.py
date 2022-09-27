def quick_sort(data):
    if len(data) <= 1:
        return data
    border = data[0]
    left = list(filter(lambda x: x < border, data))
    center = [x for x in data if x == border]
    right = list(filter(lambda x: x > border, data))
    return quick_sort(left) + center + quick_sort(right)

#to do
def quicksort_help(data):
    if len(data) <= 1:
        return data
    border = data[0]
    left = list(filter(lambda x: x < border, data))
    center = [x for x in data if x == border]
    right = list(filter(lambda x: x > border, data))
    return quick_sort(left) + center + quick_sort(right)

# ----------------------------------------------------------

def insertion(data):
    for i in range(len(data)):
        j = i - 1
        key = data[i]
        while data[j] > key and j >= 0:
            data[j+1] = data[j]
            j -= 1
        data[j+1] = key
    return data

def insertion_help(data):
    step = 1
    for i in range(len(data)):
        j = i - 1
        key = data[i]
        while data[j] > key and j >= 0:
            data[j+1] = data[j]
            j -= 1
        data[j+1] = key
        if j != -1 and j != 0:
            print('Step:', step, ':', data)
            step += 1
    return data

# ----------------------------------------------------------


print('QuickSort: ', quicksort_help([1, 4, 6, 4, 2, 8, 5, 0, 1, 10, 142, 5]))
print('InsertionSort:', insertion_help([1, 4, 6, 4, 2, 8, 5]))