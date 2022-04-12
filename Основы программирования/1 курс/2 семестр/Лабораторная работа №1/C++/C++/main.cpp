/*
* 1 курс, 2 семестр, Основи програмування, лабораторна робота №1.
* 
* Варіант 29
* Створити два текстових файли. Переписати в новий текстовий файл рядки,
* які є в першому вихідному файлі й відсутні у другому. Визначити кількість
* таких рядків. Вивести вміст вихідних і створених файлів.
*/
#include <locale>
#include <clocale>
#include <Windows.h>
#include <algorithm>
#include "Functions.h"

using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	locale::global(locale("rus_rus.1251"));


	string sFirstFileName = "file1.txt";
	string sSecondFileName = "file2.txt";
	string sThirdFileName = "file3.txt";
	char ch;

	cout << "Ви бажаєте перезаписати перший файл? [y/n]: ";
	cin >> ch;
	bool bTruncateFirst = ch == 'y' || ch == 'Y';
	cout << "Вводьте перший файл (Ctrl + G для завершення вводу):" << endl;
	writeFile(sFirstFileName, bTruncateFirst, true);

	cout << "Ви бажаєте перезаписати другий файл? [y/n]: ";
	cin >> ch;
	bool bTruncateSecond = ch == 'y' || ch == 'Y';
	cout << "Вводьте другий файл (Ctrl + G для завершення вводу):" << endl;
	writeFile(sSecondFileName, bTruncateSecond, true);

	vector<string> vFirstFileLines = readFile(sFirstFileName);
	vector<string> vSecondFileLines = readFile(sSecondFileName);
	vector<string> vUniqueLines = findUniqueElements(vFirstFileLines, vSecondFileLines);

	ofstream fThirdFile{ sThirdFileName };
	outputVector(vUniqueLines, false, fThirdFile);
	fThirdFile.close();

	vector<string> vThirdFileLines = readFile(sThirdFileName);

	cout << endl << "Перший файл:" << endl;
	outputVector(vFirstFileLines);
	cout << endl << "Другий файл:" << endl;
	outputVector(vSecondFileLines);
	cout << endl << "Третій файл (унікальні елементи першого файлу):" << endl;
	outputVector(vThirdFileLines);
	cout << endl << "Кількість таких елементів: " << vUniqueLines.size() << endl;

	system("pause");
}