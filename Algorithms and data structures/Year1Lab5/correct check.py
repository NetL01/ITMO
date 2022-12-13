import sys

# Наша защита от time limit
sys.setrecursionlimit(10 ** 9)


def is_bin_tree(potok, min_x, max_x):
    global is_bin_tree_flag
    if potok[0] <= min_x or potok[0] >= max_x:
        is_bin_tree_flag = True
        return 'NO'
    if potok[1] != 0 and potok[2] != 0 and is_bin_tree_flag == False:
        is_bin_tree(res[potok[1] - 1], min_x, potok[0])
        is_bin_tree(res[potok[2] - 1], potok[0], max_x)
    if potok[1] != 0 and potok[2] == 0 and is_bin_tree_flag == False:
        is_bin_tree(res[potok[1] - 1], min_x, potok[0])
    if potok[1] == 0 and potok[2] != 0 and is_bin_tree_flag == False:
        is_bin_tree(res[potok[2] - 1], potok[0], max_x)
    if is_bin_tree_flag == False:
        return "YES"
    if is_bin_tree_flag == True:
        return 'NO'

# correction flag
is_bin_tree_flag = False

n = int(input())
min_x = - (10 ** 9)
max_x = 10 ** 9
if n == 0:
    print('YES')
else:
    res = []
    for i in range(n):
        line = list(map(int, input().split()))
        res.append(line)
    print(is_bin_tree(res[0], min_x, max_x))
