from os import system

""" Варіант 29
    Знайти всі чотирьохзначні паліндроми """

for num in range(1000, 10000):
    palindrome = True
    numlen = 0
    tempnum = num

    while tempnum:
        numlen += 1
        tempnum //= 10

    for i in range(numlen // 2):
        first = num // 10 ** (numlen - i - 1)
        first %= 10

        last = 0

        tempnum = num

        for o in range(i + 1):
            last = tempnum % 10
            tempnum //= 10

        if first != last:
            palindrome = False

    if palindrome:
        print(f'{num} - число-паліндром')
    
system('pause')