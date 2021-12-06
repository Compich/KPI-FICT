from os import system

""" Варіант 29 """

def y(a: float):
    res1 = f(0.5)
    res2 = f(a - 0.1)
    res3 = f(4 * a - 1)
    res = (2 * res1 - 3 * res2) / (5 - res3)
    return res

def f(x: float):
    sum1 = sum(0, 20, f1, x)
    sum2 = sum(0, 20, f2, x)
    return sum1 / sum2

def f1(x: float, k: int):
    res = pow(x, 2 * k + 1) / fact(2 * k + 1)
    return res

def f2(x: float, k: int):
    res = pow(x, 2 * k) / fact(2 * k)
    return res

def sum(start: int, end: int, func, x: float):
    s = 0
    for k in range(start, end + 1):
        s += func(x, k)
    return s

def fact(n: int):
    f = 1
    for i in range(2, n + 1):
        f *= i
    return f

def main():
    print('Введіть число а: ', end='')
    a = float(input())
    result = y(a)
    print(f'res == {round(result, 6)}')
    system('pause')

if __name__ == '__main__':
    main()

    