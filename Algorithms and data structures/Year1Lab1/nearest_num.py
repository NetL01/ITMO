a = int(input())
res = input().split()
min_diff = 100000
first = int(input())
for i in res:
    if abs(int(i)-first) < min_diff:
        min_diff = min(min_diff, abs(int(i)-first))
if str(first - min_diff) in res:
    print(str(first-min_diff))
else:
    print(str(first+min_diff))