import sys

# Наша защита от time limit
sys.setrecursionlimit(10**9)
ans = []


def length(potok, k):
    if potok[1] == 0 and potok[2] == 0:
        return ans.append(k+1)
    if potok[1] != 0:
        # print('1 - ', potok[1], a[potok[1]-1])
        length(res[potok[1]-1], k+1)
    if potok[2] != 0:
        # print('2 - ', potok[2], a[potok[2]-1])
        length(res[potok[2]-1], k+1)


num = int(input())
if num == 0:
    print(0)
else:
    res = []
    for i in range(num):
        t = list(map(int, input().split()))
        res.append(t)
    length(res[0], 0)
    print(max(ans))