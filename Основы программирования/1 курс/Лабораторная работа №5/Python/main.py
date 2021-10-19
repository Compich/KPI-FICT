from os import system

""" Варіант 29
    Знайти всі чотирьохзначні паліндроми """

for i in range(1000, 10000):
    i_str = str(i)
    if i_str == i_str[::-1]:
        print(f'{i} - число-паліндром')

system('pause')