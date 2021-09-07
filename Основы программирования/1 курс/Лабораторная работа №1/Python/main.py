import math
from os import system

x1 = float(input('x1 = '))
y1 = float(input('y1 = '))
x2 = float(input('x2 = '))
y2 = float(input('y2 = '))
a = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
print('a =', round(a, 4))

system('pause')