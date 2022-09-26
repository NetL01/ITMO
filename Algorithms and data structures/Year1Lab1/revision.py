a = int(input())
res = input().split()
# находим первое наименьшее
first_min = int(res[0])
for i in res:
    first_min = min(first_min, int(i))
# удаляем его из списка
res.remove(str(first_min))
# второе наименьшее
second_min = int(res[0])
for i in res:
    second_min = min(second_min, int(i))
print(first_min, second_min)