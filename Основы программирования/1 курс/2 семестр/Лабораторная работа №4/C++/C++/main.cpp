/*
* 1 курс, 2 семестр, Основи програмування, лабораторна робота №4.
*
* Варіант 29
* Розробити клас "Вектор", членами якого є сферичні координати вектора у
* просторі. Реалізувати для нього декілька конструкторів, геттери, метод
* обчислення йцого декартових координат. Перевантажити оператори:
* "+=" для збільшення полярного кута на вказану величину (у градусах),
* "!=" для перевірки неколінеарності векторів. Створити три вектори
* (В1, В2, В3), використовуючи різні конструктори. Збільшити полярний кут
* вектора В1 на вказану величину. Знайти декартові координати зміненого
* вектора В1. Перевірити колінеарніть векторів В2 і В3.
*/

#include <locale>
#include <Windows.h>
#include "Vector.h"

using std::locale;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	locale::global(locale("rus_rus.1251"));

	srand(time(nullptr));

	TPoint p1;
	cout << "Введіть декартові координати першого вектора у форматі x; y; z: ";
	cin >> p1;
	Vector v1(p1);

	double dbR, dbPolar, dbAzimuthal;
	char ch1, ch2;
	cout << "Введіть полярні координати другого вектора у форматі радіус; полярний_кут; азимутальний кут: ";
	cin >> dbR >> ch1 >> dbPolar >> ch2 >> dbAzimuthal;
	Vector v2(dbR, dbPolar, dbAzimuthal);

	Vector v3;

	cout << "Перший вектор:" << endl << v1 << endl << endl << "Другой вектор:" << endl << v2 << endl << endl << "Третій вектор:" << endl << v3 << endl;

	double ddbPolar;
	cout << endl << "На скільки градусів треба збільшити полярний кут першого вектора?: ";
	cin >> ddbPolar;
	v1 += ddbPolar;

	cout << "Перший вектор:" << endl << v1 << endl << endl;

	bool bNonCollinearity = v2 != v3;

	if (bNonCollinearity)
	{
		cout << "Другий та третій вектори неколінеарні" << endl;
	}
	else
	{
		cout << "Другий та третій вектори колінеарні" << endl;
	}
	
	system("pause");
	return 0;
}