/*
* 1 ����, 2 �������, ������ �������������, ����������� ������ �3.
*
* ������ 29
* ��������� ����, ���� � ����������� ������ �� ������� �������� ���������
* ����� �� ������ � ���������� ������� ����� � ����� �������� �������
* (������� �������/�������� ������� �������). �������� �����
* ��'���� ������ �����. ��������� ����� ������ ������ �������.
* ��������� ������, ���� ��������� ����������� � �������
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

	cout << "������� ����� (Ctrl + G ��� ����������):" << endl;

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

	cout << endl << "������ �����:" << endl;
	outputArray(rgStrings, cCount);

	int iEditNum;

	cout << "������ ����� ����� ��� ��������� ������ (0 ��� �����������): ";
	cin >> iEditNum;

	while (iEditNum != 0)
	{
		if (iEditNum < 0 || cCount <= iEditNum)
		{
			cout << "������� ������� �����!" << endl;
		}

		string sLine;

		cout << "������ �����, ���� ������ ��������� �������: ";
		cin.ignore();
		getline(cin, sLine);

		rgStrings[iEditNum - 1].addText(sLine);

		cout << "������ ����� ����� ��� ��������� ������ (0 ��� �����������): ";
		cin >> iEditNum;
	}

	cout << endl << "������ �����:" << endl;
	outputArray(rgStrings, cCount);

	size_t nRepeats = 0;

	char chMostPopular = getMostPopularSymbol(rgStrings, cCount, nRepeats);

	cout << "��������� ����������� ������ " << '\'' << chMostPopular << '\'' << endl
		<< "ʳ������ ����� ������� � ��� �����: " << nRepeats << endl;

	system("pause");
}