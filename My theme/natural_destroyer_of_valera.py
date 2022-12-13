from tqdm import tqdm
import time
import random

# Пункт 1: примите ислам

dict = {"Яковенко Валера": 0, "Бездомов Никита": 0, "Дима": 0, "Васильев Костя": 0, "Крючкова Саша": 0, "Фазил": 0, "Петровский Андрей": 0, "Загута Никита": 0, "Кузнецов Дмитрий": 0,
        "Разуваев Никита": 0, "Силкин Семён": 0, "Стрельцов Кирилл": 0, "Аниськин Клементий": 0, "Бадьин Роман": 0,"Брюханова Диана": 0, "Васильев Иван": 0,
        "Головлёв Федор": 0, "Дурасова Анна": 0, "Жудинов Данил": 0}

print('Запуск процесса определения части пидорства...')
for key, value in dict.items():
    dict[key] = random.randint(0, 100)
print('Степень пидорства определена.')
print('Введите валера пидор чтобы узнать свой педо-рейтинг')
a = input(':__ ')
sorted(dict.items(), key=lambda item: (item[1], item[0]))
k = 0
pidors = []
cocorols = []
good_boys = []

sorted_dict = {}
sorted_keys = sorted(dict, key=dict.get,reverse=True)  # [1, 3, 2]

for w in sorted_keys:
    sorted_dict[w] = dict[w]


for key, value in sorted_dict.items():
    if k == 0:
        print("Пидор дня: ", key, "с результатом: ", value)
        print('Остальные:')
    else:
        print(key, value)
    k += 1
