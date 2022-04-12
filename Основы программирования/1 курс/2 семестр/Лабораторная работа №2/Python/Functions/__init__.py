import typing
import Buyer
import pickle
from datetime import datetime

def input_buyer():
    surname = input('Введіть прізвище покупця: ')

    gender = int(
        input('Введіть стать покупця (1 - Чоловіча, 2 - Жіноча, 0 - Інша): ')
    )
    gender = 0 if gender < 0 or 2 < gender else gender

    birthday = datetime.strptime(
        input('Введіть дату народження покупця (Формат: DD.MM.YYYY): '),
        '%d.%m.%Y'
    ).date()

    amount = int(
        input('Введіть кількість одиниць придбаного покупцем товару: ')
    )

    return Buyer.Buyer(
        surname=surname,
        gender=gender,
        birthday=birthday,
        amount=amount
    )

def output_buyers_list(buyers: typing.List[Buyer.Buyer]):
    for buyer in buyers:
        print('\n', buyer, sep='')

def write_file(name: str, truncate: bool):
    break_input = False

    with open(name, f'{"w" if truncate else "a"}b') as file:
        while not break_input:
            buyer = input_buyer()

            pickle.dump(buyer, file)

            ch = input('Ви бажаєте додати ще одного покупця? [y/n]: ')

            if ch.lower() != 'y':
                break_input = True

def read_file(name: str) -> typing.List[Buyer.Buyer]:
    buyers = []
    with open(name, 'rb') as file:
        eof = False
        while not eof:
            try:
                buyer = pickle.load(file)
                buyers.append(buyer)
            except EOFError:
                eof = True

    return buyers

def get_shop_income(buyers: typing.List[Buyer.Buyer]):
    return sum(Buyer.get_buyer_spent(buyer) for buyer in buyers)

def export_rich_buyers(
    file_name: str,
    buyers: typing.List[Buyer.Buyer],
    threshold: int
):
    with open(file_name, 'wb') as file:
        for buyer in buyers:
            if threshold <= Buyer.get_buyer_spent(buyer):
                pickle.dump(buyer, file)
