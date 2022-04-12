from Person import Person
from Scholarship import Scholarship
import random

class Student(Person):
    def __init__(
            self,
            name=None,
            birthday=None,
            group_name=None,
            grade_point_average=None
    ):
        super().__init__(name, birthday)

        if group_name is None:
            group_prefixes = (
                "ІА", "ІК", "ІС", "ІП", "ІТ", "ІО", "ІМ", "ІВ"
            )

            group_name = f'{random.choice(group_prefixes)}-' \
                         f'{random.randint(11, 15)}'

        if grade_point_average is None:
            grade_point_average = round(random.uniform(60, 100), 2)

        self.__group_name = group_name
        self.__grade_point_average = grade_point_average

    def get_scholarship(self):
        scholarship = Scholarship.NONE

        if 95 <= self.__grade_point_average:
            scholarship = Scholarship.INCREASED
        elif 85 <= self.__grade_point_average:
            scholarship = Scholarship.DEFAULT

        return scholarship

    def get_salary(self):
        scholarship = self.get_scholarship()
        salary = 0

        if scholarship == Scholarship.DEFAULT:
            salary = 2000
        elif scholarship == Scholarship.INCREASED:
            salary = 2550

        return salary

    @property
    def group_name(self):
        return self.__group_name

    @property
    def get_grade_point_average(self):
        return self.__grade_point_average

    def __str__(self):
        return f'ПІБ студента {self.name}\n' \
               f'Дата народження: {self.birthday:%d.%m.%Y} ' \
               f'(вік: {self.get_age()})\n' \
               f'Номер академічної групи: {self.__group_name}\n' \
               f'Середній рейтинговий бал: {self.__grade_point_average}\n' \
               f'Стипендія: {self.get_scholarship().value}\n' \
               f'Місячний заробіток: {self.get_salary()} грн.' \

    def __repr__(self):
        return self.__str__()
