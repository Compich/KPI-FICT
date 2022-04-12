/*
* 1 ����, 2 �������, ������ �������������, ����������� ������ �4.
*
* ������ 29
* ��������� ���� "������", ������� ����� � ������� ���������� ������� �
* �������. ���������� ��� ����� ������� ������������, �������, �����
* ���������� ����� ���������� ���������. ������������� ���������:
* "+=" ��� ��������� ��������� ���� �� ������� �������� (� ��������),
* "!=" ��� �������� ������������� �������. �������� ��� �������
* (�1, �2, �3), �������������� ��� ������������. �������� �������� ���
* ������� �1 �� ������� ��������. ������ �������� ���������� ��������
* ������� �1. ��������� ���������� ������� �2 � �3.
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
	cout << "������ �������� ���������� ������� ������� � ������ x; y; z: ";
	cin >> p1;
	Vector v1(p1);

	double dbR, dbPolar, dbAzimuthal;
	char ch1, ch2;
	cout << "������ ������ ���������� ������� ������� � ������ �����; ��������_���; ������������ ���: ";
	cin >> dbR >> ch1 >> dbPolar >> ch2 >> dbAzimuthal;
	Vector v2(dbR, dbPolar, dbAzimuthal);

	Vector v3;

	cout << "������ ������:" << endl << v1 << endl << endl << "������ ������:" << endl << v2 << endl << endl << "����� ������:" << endl << v3 << endl;

	double ddbPolar;
	cout << endl << "�� ������ ������� ����� �������� �������� ��� ������� �������?: ";
	cin >> ddbPolar;
	v1 += ddbPolar;

	cout << "������ ������:" << endl << v1 << endl << endl;

	bool bNonCollinearity = v2 != v3;

	if (bNonCollinearity)
	{
		cout << "������ �� ����� ������� ����������" << endl;
	}
	else
	{
		cout << "������ �� ����� ������� ��������" << endl;
	}
	
	system("pause");
	return 0;
}