import datetime
import typing
import random
from abc import abstractmethod


class Person(object):
    def __init__(
            self,
            name=None,
            birthday=None,
    ):
        if name is None:
            last_names = (
                "Алєксєєв", "Боровков", "Веремчук", "Гіжицький",
                "Головатюк", "Головня", "Гуськов", "Демиденко",
                "Друзенко", "Дякунчак", "Звєрєв", "Калашніков",
                "Кашка", "Книш", "Кузьменков", "Куценко",
                "Лесів", "Лисенко", "Лошак", "Ляля", "Негрієнко",
                "Панченко", "Прищепа", "Рябов", "Савенко",
                "Сідак", "Тарасьнок", "Тихонов", "Трикош",
                "Шамков", "Ющенко"
            )

            first_names = (
                "Андрій", "Іван", "Ігор", "Даніїл", "Владислав",
                "Олександр", "Кирило", "Олексій", "Микола",
                "Максим", "Дмитро", "Артемій", "Віктор",
                "Сергій", "Юрій", "Федір"
            )

            patronymics = (
                "Олександрович", "Ігорович", "Денисович",
                "Ростиславович", "Михайлович", "Олексійович",
                "Юрійович", "Віталійович", "Миколайович",
                "Євгенович", "Сергійович", "Олегович",
                "Ілліч", "Іванович", "Костянтинович",
                "Станіславович", "Андрійович",
                "Володимирович", "Дмитрович",
                "Вікторович"
            )

            name = f'{random.choice(last_names)} ' \
                   f'{random.choice(first_names)} ' \
                   f'{random.choice(patronymics)}'

        if birthday is None:
            random_date_start = datetime.date(year=1950, month=1, day=1)
            random_date_end = datetime.date(2004, 12, 31)
            random_day = random.randint(
                0,
                (random_date_end - random_date_start).days
            )
            birthday = random_date_start + datetime.timedelta(days=random_day)

        self.__name = name
        self.__birthday = birthday

    @property
    def name(self) -> str:
        return self.__name

    @name.setter
    def name(self, name: str):
        self.__name = name

    @property
    def birthday(self) -> datetime.date:
        return self.__birthday

    @birthday.setter
    def birthday(self, new_date: datetime.date):
        self.__birthday = new_date

    def get_age(self):
        return datetime.datetime.fromtimestamp(
            (datetime.date.today() - self.__birthday).total_seconds()
        ).year - 1970

    @abstractmethod
    def get_salary(self):
        ...
