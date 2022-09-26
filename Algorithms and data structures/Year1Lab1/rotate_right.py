a = int(input())
res = input().split()
res2 = []
res2.append(res[-1])
for i in range(len(res)-1):
    res2.append(res[i])
print(*res2)
