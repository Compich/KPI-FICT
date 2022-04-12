/*
* 1 ����, 2 �������, ������ �������������, ����������� ������ �2.
*
* ������ 29
* �������� ���� �� ������� ��������, �� �������� ������ � ������� �� ����
* �����: �������, �����, ���� ����������, ������� ������� ������.
* �������������, �� ������� ���� ������� ������ - 100 ���., ������ �� �����
* ������� ��� �����. ���������� (� 60-�� ����) �������� ��������� ������ 5%.
* ��������� ������ �������� �� ����. �������� ����� ���� � ����������� ���
* ��������, �� �������� ���� �� �� 250 ���.
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

	cout << "�� ������ ������ ����� ��������? [y/n]: ";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		cout << "�� ������ ������������ ����? [y/n]: ";
		cin >> ch;
		bool bTruncateFile = ch == 'y' || ch == 'Y';
		writeFile(sFileName, bTruncateFile);
	}

	vector<TBuyer> vBuyers = readFile(sFileName);

	cout << "������ ��������:" << endl;
	outputBuyersList(vBuyers);

	int nTotalIncome = getShopIncome(vBuyers);
	cout << endl << "������ ��������: " << nTotalIncome << " ���." << endl;

	exportRichBuyers(sExportFileName, vBuyers, 250);

	vector<TBuyer> vRichBuyers = readFile(sExportFileName);

	cout << endl << "������ ��������, �� ��������� ����� 250 �������:" << endl;
	outputBuyersList(vRichBuyers);

	system("pause");
}