"""
1 курс, 2 семестр, Основи програмування, лабораторна робота №2.

Варіант 29
Створити файл із списком покупців, які придбали товари зі знижкою на день
акції: прізвище, стать, дата народження, кількість одиниць товару.
Передбачається, що вартість однієї одиниці товару - 100 грн., знижка на товар
дорівнює віку особи. Пенсіонерам (з 60-ти років) надається додаткова знижка 5%.
Визначити виторг магазину за день. Створити новий файл з інформацією про
покупців, які придбали більш ніж на 250 грн.
"""
import Buyer
import datetime
from datetime import date
import pickle
from Functions import (write_file, read_file, output_buyers_list,
                        get_shop_income, export_rich_buyers)

if __name__ == '__main__':
    file_name = 'buyers.bin'
    export_file_name = 'richBuyers.bin'

    ch = input('Ви бажаєте додати нових покупців? [y/n]: ')
    if ch.lower() == 'y':
        ch = input('Ви бажаєте перезаписати файл? [y/n]: ')
        truncate_file = ch.lower() == 'y'
        write_file(file_name, truncate_file)

    buyers = read_file(file_name)

    print('Список покупців:')
    output_buyers_list(buyers)

    total_income = get_shop_income(buyers)
    print(f'\nВиторг магазину: {total_income} грн.')

    export_rich_buyers(export_file_name, buyers, 250)

    rich_buyers = read_file(export_file_name)

    print(f'\nСписок покупців, що витратили більше 250 гривень:')
    output_buyers_list(rich_buyers)

    input()
