#include <iostream>
#include <locale>

/* Варіант 29
   Знайти всі чотирьохзначні паліндроми */

using namespace std;

int main()
{
	locale::global(locale("rus")); // Встановлення локалізації консолі

	for (int i = 1000; i < 10000; ++i)
	{
		int number1 = i / 1000;		// Знаходження першої цифри в числі
		int number2 = i / 100 % 10;	// Знаходження другої цифри в числі
		int number3 = i / 10 % 10;	// Знаходження третьої цифри в числі
		int number4 = i % 10;		// Знаходження останньої цифри в числі

		if (number1 == number4 && number2 == number3) // Перевірка, чи є це число паліндромом
		{
			cout << i << " - число-палiндром" << endl; // Виведення відповідної інформації
		}
	}

	system("pause");
}