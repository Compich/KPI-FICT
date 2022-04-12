from datetime import date, datetime
from textwrap import dedent

class Buyer:
    def __init__(
        self,
        surname = '',
        gender = 1,
        birthday = date.today(),
        amount = 0
    ):
        self.surname = surname
        self.gender = gender
        self.birthday = birthday
        self.amount = amount

    def __repr__(self):
        if self.gender == 1:
            gender_str = 'Чоловіча'
        elif self.gender == 2:
            gender_str = 'Жіноча'
        else:
            gender_str = 'Інша'

        return dedent(f"""\
            Прізвище: {self.surname}
            Стать: {gender_str}
            Дата народження: {self.birthday:%d.%m.%Y}
            Кількість придбаного товару: {self.amount} шт.
            Знижка: {buyer_discount(self)}%
            Усього витрачено: {get_buyer_spent(self)} грн.""")

def age_of_buyer(buyer: Buyer):
    return datetime.fromtimestamp(
        (date.today() - buyer.birthday).total_seconds()
    ).year - 1970

def buyer_discount(buyer: Buyer):
    total_discount = age_of_buyer(buyer)

    if 60 < total_discount:
        total_discount += 5

    return 100 if 100 < total_discount else total_discount

def get_buyer_spent(buyer: Buyer):
    return buyer.amount * 100 * ((100 - buyer_discount(buyer)) / 100)
