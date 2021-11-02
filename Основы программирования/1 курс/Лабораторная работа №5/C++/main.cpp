#include <iostream>
#include <locale>

/* Варіант 29
   Знайти всі чотирьохзначні паліндроми */

using namespace std;

int main()
{
	locale::global(locale("rus"));

	for (int num = 1000; num < 10000; ++num)
	{
		bool palindrome = true; // Ініціалізація
		int numlen = 0;			// 
		int tempnum = num;		// змінних

		while (tempnum)	// Знаходження довжини числа
		{
			++numlen;
			tempnum /= 10;
		}

		for (int i = 0; i < numlen / 2; ++i)	// Перевірка на те, чи є число паліндромом
		{
			int first = num / pow(10, numlen - 1 - i);	// Знаходження наступної
			first %= 10;								// старшої цифри числа

			int last = 0;	// Ініціалізація змінної, що зберігатиме молодшу цифру числа

			tempnum = num;	// Змінюємо значення допоміжної змінної tempnum, щоб не змінювати змінну циклу

			for (int o = 0; o <= i; ++o)	// Знаходження наступної молодшої цифри числа
			{
				last = tempnum % 10;
				tempnum /= 10;
			}

			if (first != last)	// Якщо перша цифра не дорівнює останній, це число - не паліндром
			{
				palindrome = false;
			}
		}

		if (palindrome)	// Якщо число є паліндромом, виводимо його
		{
			cout << num << " - число-палiндром" << endl;
		}
	}

	system("pause");
}