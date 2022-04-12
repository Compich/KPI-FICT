"""
1 курс, 2 семестр, Основи програмування, лабораторна робота №1.

Варіант 29
Створити два текстових файли. Переписати в новий текстовий файл рядки,
які є в першому вихідному файлі й відсутні у другому. Визначити кількість
таких рядків. Вивести вміст вихідних і створених файлів.
"""
from Functions import *

if __name__ == '__main__':
    first_file_name = 'file1.txt'
    second_file_name = 'file2.txt'
    third_file_name = 'file3.txt'

    ch = input('Ви бажаєте перезаписати перший файл? [y/n]: ')
    truncate_first = ch.lower() == 'y'
    print('Вводьте перший файл (Ctrl + G для завершення вводу):')
    write_file(first_file_name, truncate_first)

    ch = input('Ви бажаєте перезаписати другий файл? [y/n]: ')
    truncate_second = ch.lower() == 'y'
    print('Вводьте другий файл (Ctrl + G для завершення вводу):')
    write_file(second_file_name, truncate_second)

    first_file_lines = read_file(first_file_name)
    second_file_lines = read_file(second_file_name)
    unique_lines = find_unique_elements(first_file_lines, second_file_lines)

    write_lines_to_file(third_file_name, unique_lines)

    third_file_lines = read_file(third_file_name)

    print('\nПерший файл:', '\n'.join(first_file_lines), sep='\n')
    print('\nДругий файл:', '\n'.join(second_file_lines), sep='\n')
    print(
        '\nТретій файл (унікальні елементи першого файлу):',
        '\n'.join(third_file_lines),
        sep='\n'
    )
    print(f'\nКількість таких елементів: {len(unique_lines)}')

    system('pause')
