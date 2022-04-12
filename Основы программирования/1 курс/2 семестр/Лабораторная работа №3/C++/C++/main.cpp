/*
* 1 курс, 2 семестр, Основи програмування, лабораторна робота №3.
*
* Варіант 29
* Розробити клас, який є абстракцією тексту та підтримує операції додавання
* рядка до тексту і визначення частоти появи у тексті заданого символу
* (кількість символів/загальна кількість символів). Створити масив
* об'єктів даного класу. Доповнити кілька текстів новими рядками.
* Визначити символ, який найчастіше зустрічається у текстах
*/
#include "Functions.h"
#include <locale>
#include <Windows.h>

using std::locale;
using std::cin;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	locale::global(locale("rus_rus.1251"));

	String* rgStrings = nullptr;

	bool bBreak = false;
	size_t cCount = 0;

	cout << "Вводьте рядки (Ctrl + G для завершення):" << endl;

	while (!bBreak || cCount == 0)
	{
		string sLine;
		char ch;

		getline(cin, sLine);

		int nBreakPos = sLine.find(0x7);

		String sLineString = String(sLine.substr(0, nBreakPos));

		if (sLineString.symbolsCount() != 0)
		{
			rgStrings = addToArray(rgStrings, sLineString, cCount);
		}

		bBreak = nBreakPos != -1;
	}

	cout << endl << "Список рядків:" << endl;
	outputArray(rgStrings, cCount);

	int iEditNum;

	cout << "Введіть номер рядка для додавання тексту (0 для продовження): ";
	cin >> iEditNum;

	while (iEditNum != 0)
	{
		if (iEditNum < 0 || cCount <= iEditNum)
		{
			cout << "Введено невірний номер!" << endl;
		}

		string sLine;

		cout << "Введіть рядок, яким хочете доповнити обраний: ";
		cin.ignore();
		getline(cin, sLine);

		rgStrings[iEditNum - 1].addText(sLine);

		cout << "Введіть номер рядка для додавання тексту (0 для продовження): ";
		cin >> iEditNum;
	}

	cout << endl << "Список рядків:" << endl;
	outputArray(rgStrings, cCount);

	size_t nRepeats = 0;

	char chMostPopular = getMostPopularSymbol(rgStrings, cCount, nRepeats);

	cout << "Найчастіше зустрічається символ " << '\'' << chMostPopular << '\'' << endl
		<< "Кількість цього символу в усіх рядка: " << nRepeats << endl;

	system("pause");
}