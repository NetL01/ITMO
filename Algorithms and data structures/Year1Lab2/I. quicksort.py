n = int(input())
m = list(map(int, input().split()))
def quick_sort(s):
    if len(s) <= 1:
        return s
    elem = s[0]
    left = (list(filter(lambda x: x < elem, s)))
    center = [i for i in s if i == elem]
    right = (list(filter(lambda x: x > elem, s)))
    return quick_sort(left) + center + quick_sort(right)

print(*quick_sort(m))

def quick_sort(s):
    if len(s) <= 1:
        return s
    elem = s[0]
    left = list(filter(lambda x: x < elem, s))
    center = [i for i in s if i == elem]
    right = list(filter(lambda x: x > elem, s))
    return quick_sort(left) + center + quick_sort(right)







def qsort(L):
    if L: return list(map(int, qsort(filter(lambda x: x < L[0], L[1:])) + L[0:1] + qsort(filter(lambda x: x >= L[0], L[1:]))))
    return []