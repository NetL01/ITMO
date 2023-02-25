from tqdm import tqdm

import random
name = input("Name: ")
age = input('Age: ')



def analytics_part_one(name):
    words = [x for x in name.lower()]
    part_one_total = 0
    for i in words:
        if i in ['д', 'и', 'м', 'а']:
            part_one_total += 10
    part_one_percent = part_one_total / 100
    return part_one_percent
# max -> 40

def analytics_part_two(age):
    part_two_total = 0
    if int(age) in range(1, 18):
        part_two_total += 10
    if int(age) >= 18:
        part_two_total += 20
    if int(age) == 18 and name == "Дима":
        part_two_total += 40
    part_two_percent = part_two_total / 100
    return part_two_percent

# max -> 70

def random_awayken_part():
    random_part = random.randint(0, 20)
    return random_part/100

total_one = analytics_part_one(name)
total_two = analytics_part_two(age)
total_three = random_awayken_part()

total = total_one + total_two + total_three+100
if total > 1:
    print(name, ":  сфинктер разъебан, анализ не провести, но по моему нескромному мнению, ответ очевиден")
else:
    print(name, "садомит на: ", total*100, "%!")

class Analytics:
    def __init__(self, total_percent):
        self.total_percent = total_percent
