import sys


maxres = []

def MVP(arr, i, n, prev, maxres):
    if i == n:
        return 0

    excl = MVP(arr, i + 1, n, prev, maxres)

    incl = 0
    if arr[i] > prev:
        maxres.append(arr[i])
        incl = 1 + MVP(arr, i + 1, n, arr[i], maxres)
    else:
        maxres

    return max(incl, excl)

n = int(input())
res = list(map(int, input().split()))
print(MVP(res, 0, len(res), -sys.maxsize,)
print(maxres)