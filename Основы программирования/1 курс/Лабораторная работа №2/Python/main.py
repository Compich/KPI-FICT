from os import system

x = float(input('Введіть координату x: '))
y = float(input('Введіть координату y: '))

if abs(x) <= 1:
    if (y <= 1):
        if (abs(x) <= y):
            ans = 'Точка належить заштрихованій області'
        else:
            ans = 'Точка не належить заштрихованій області'
    else:
        ans = 'Точка не належить заштрихованій області'
else:
    ans = 'Точка не належить заштрихованій області'

print(ans)

system('pause')