/*
* 1 ����, 2 �������, ������ �������������, ����������� ������ �1.
* 
* ������ 29
* �������� ��� ��������� �����. ���������� � ����� ��������� ���� �����,
* �� � � ������� ��������� ���� � ������ � �������. ��������� �������
* ����� �����. ������� ���� �������� � ��������� �����.
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

	cout << "�� ������ ������������ ������ ����? [y/n]: ";
	cin >> ch;
	bool bTruncateFirst = ch == 'y' || ch == 'Y';
	cout << "������� ������ ���� (Ctrl + G ��� ���������� �����):" << endl;
	writeFile(sFirstFileName, bTruncateFirst, true);

	cout << "�� ������ ������������ ������ ����? [y/n]: ";
	cin >> ch;
	bool bTruncateSecond = ch == 'y' || ch == 'Y';
	cout << "������� ������ ���� (Ctrl + G ��� ���������� �����):" << endl;
	writeFile(sSecondFileName, bTruncateSecond, true);

	vector<string> vFirstFileLines = readFile(sFirstFileName);
	vector<string> vSecondFileLines = readFile(sSecondFileName);
	vector<string> vUniqueLines = findUniqueElements(vFirstFileLines, vSecondFileLines);

	ofstream fThirdFile{ sThirdFileName };
	outputVector(vUniqueLines, false, fThirdFile);
	fThirdFile.close();

	vector<string> vThirdFileLines = readFile(sThirdFileName);

	cout << endl << "������ ����:" << endl;
	outputVector(vFirstFileLines);
	cout << endl << "������ ����:" << endl;
	outputVector(vSecondFileLines);
	cout << endl << "����� ���� (������� �������� ������� �����):" << endl;
	outputVector(vThirdFileLines);
	cout << endl << "ʳ������ ����� ��������: " << vUniqueLines.size() << endl;

	system("pause");
}