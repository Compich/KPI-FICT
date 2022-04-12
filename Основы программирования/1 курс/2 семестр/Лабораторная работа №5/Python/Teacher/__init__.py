import random
import typing

from Person import Person
from Discipline import Discipline

class Teacher(Person):
    def __init__(
        self,
        name=None,
        birthday=None,
        disciplines=None
    ):
        super().__init__(name, birthday)

        if disciplines is None:
            disciplines = []
            disciplines_count = random.randint(1, 3)

            while len(disciplines) != disciplines_count:
                discipline = Discipline()
                if not discipline.name in [dsc.name for dsc in disciplines]:
                    disciplines.append(discipline)

        self.__disciplines: typing.List[Discipline] = disciplines


    def get_salary(self):
        salary_base = 500
        total_salary = 0

        for discipline in self.__disciplines:
            total_salary += discipline.number_of_hours * salary_base

        return total_salary


    def add_discipline(self, discipline: Discipline):
        self.__disciplines.append(discipline)
        return self


    def __str__(self):
        result = f'ПІБ викладача {self.name}\n' \
                 f'Дата народження: {self.birthday:%d.%m.%Y} ' \
                 f'(вік: {self.get_age()})\n' \
                 f'Місячний заробіток: {self.get_salary()} грн.\n' \
                 f'Дисципліни викладача:\n'

        for discipline in self.__disciplines:
            result += f'{discipline}\n'

        return result


    def __repr__(self):
        return self.__str__()
