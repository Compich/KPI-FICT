
from os import system
import typing


def write_file(name: str, truncate: bool):
    """
    Здійснює зчитування рядків з клавіатури та записує їх у файл.

    Args:
        name (str): Назва файлу
        truncate (bool): Перезаписати файл чи дописати в кінець
    """
    with open(name, 'w' if truncate else 'a') as output_file:
        break_input = False

        while not break_input:
            line = input()

            break_pos = line.find(chr(0x7))
            # break_pos = line.find('~')

            if break_pos != -1:
                line = line[:break_pos]
                break_input = True

            if line:
                output_file.write(line)

            if break_pos == -1:
                output_file.write('\n')


def read_file(name: str):
    """
    Зчитує рядки з файлу.

    Args:
        name (str): Назва файлу

    Returns:
        lines (typin.List[str])
    """
    with open(name) as input_file:
        lines = [line.strip() for line in input_file.readlines()]

    return lines


def find_unique_elements(
        first_list: typing.List[typing.Any],
        second_list: typing.List[typing.Any]
):
    """
    Знаходить значення, що містяться в першому списку, але відсутні в другому.

    Args:
        first_list (typing.List[typing.Any]): Перший список
        second_list (typing.List[typing.Any]): Другий список

    Returns:
        (typing.List[typing.Any]): Унікальні елементи списку
    """
    return list(set(first_list) - set(second_list))


def write_lines_to_file(name: str, lines: typing.List[str]):
    """
    Записує рядки до файлу.

    Args:
        name (str): Назва файлу
        lines (typing.List[str]): Рядки, які треба записати
    """
    with open(name, 'w') as output_file:
        output_file.write('\n'.join(lines))
