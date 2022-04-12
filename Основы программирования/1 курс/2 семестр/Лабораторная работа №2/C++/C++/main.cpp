/*
* 1 курс, 2 семестр, Основи програмування, лабораторна робота №2.
*
* Варіант 29
* Створити файл із списком покупців, які придбали товари зі знижкою на день
* акції: прізвище, стать, дата народження, кількість одиниць товару.
* Передбачається, що вартість однієї одиниці товару - 100 грн., знижка на товар
* дорівнює віку особи. Пенсіонерам (з 60-ти років) надається додаткова знижка 5%.
* Визначити виторг магазину за день. Створити новий файл з інформацією про
* покупців, які придбали більш ніж на 250 грн.
*/
#include <locale>
#include <Windows.h>
#include "Functions.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	locale::global(locale("rus_rus.1251"));

	string sFileName = "buyers.bin";
	string sExportFileName = "richBuyers.bin";
	char ch;

	cout << "Ви бажаєте додати нових покупців? [y/n]: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cout << "Ви бажаєте перезаписати файл? [y/n]: ";
		cin >> ch;
		bool bTruncateFile = ch == 'y' || ch == 'Y';
		writeFile(sFileName, bTruncateFile);
	}

	vector<TBuyer> vBuyers = readFile(sFileName);

	cout << "Список покупців:" << endl;
	outputBuyersList(vBuyers);

	int nTotalIncome = getShopIncome(vBuyers);
	cout << endl << "Виторг магазину: " << nTotalIncome << " грн." << endl;

	exportRichBuyers(sExportFileName, vBuyers, 250);

	vector<TBuyer> vRichBuyers = readFile(sExportFileName);

	cout << endl << "Список покупців, що витратили більше 250 гривень:" << endl;
	outputBuyersList(vRichBuyers);

	system("pause");
}