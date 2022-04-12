from Student import Student
from Teacher import Teacher
import typing

def generate_students(counter: int) -> typing.List[Student]:
    students = []

    for i in range(counter):
        students.append(Student())

    return students


def generate_teachers(counter: int) -> typing.List[Teacher]:
    teachers = []

    for i in range(counter):
        teachers.append(Teacher())

    return teachers


def get_teacher_with_highest_salary(teachers: typing.List[Teacher]):
    highest_index = 0
    highest_salary = teachers[0].get_salary()

    for index, teacher in enumerate(teachers[1:], 1):
        if highest_salary < teacher.get_salary():
            highest_index = index
            highest_salary = teacher.get_salary()

    return teachers[highest_index]
