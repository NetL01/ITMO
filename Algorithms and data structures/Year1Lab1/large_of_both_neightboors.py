a = int(input())
res = input().split()
count = 0
for i in range(1, len(res)-1):
    if res[i-1] < res[i] and res[i+1] < res[i]:
        count += 1
print(count)
