#include <iostream>
#include <locale>

/* Варіант 29
   Для заданого натурального числа n обчислити */

using namespace std;

int main()
{
	locale::global(locale("rus")); // Встановлення локалізації консолі

	int n;			// Оголошення
	double sum = 0; // змінних

	cout << "Введiть кiлькiсть членiв n: ";
	cin >> n; // Введення кількості членів

	if (n < 1) // Перевірка кількості членів на натуральність
	{
		cout << "Число n не може бути меншим за 1" << endl;
		return 0;
	}

	cout.precision(10); // Встановлення точності потоку виводу cout

	for (int i = 0; i < n; ++i)
	{
		sum = sqrt(2 + sum); // Обчислення проміжної суми
		cout << "sum = " << sum << endl; // Виведення на екран проміжної суми
	}

	cout << "Результат: " << sum << endl; // Виведення результату

	system("pause");
	return 0;
}