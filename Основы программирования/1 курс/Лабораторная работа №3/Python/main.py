from math import pi, sin, log

""" Варiант 29
    Наближено (iз заданою точнiстю ε
    обчислити iнтеграл, використовуючи
    формулу прямокутникiв """

a = 0
b = pi
sum = 0
counter = 1

precision = float(input('Введіть тоічніть: '))
t = precision + 1
n = int(input('Введіть кількість відрізків розбиття: '))

h = (b - a) / n

while abs(t) > precision:
    t = log(2 + sin(a + counter * h - h / 2))
    sum += t
    print('t == %.10f' % t)
    counter += 1

sum *= h

print('Резульатат: %.10f' % sum)