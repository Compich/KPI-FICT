#include <iostream>
#include <locale>

/* ������ 29
   ������ �� ������������� ��������� */

using namespace std;

int main()
{
	locale::global(locale("rus")); // ������������ ���������� ������

	for (int i = 1000; i < 10000; ++i)
	{
		int number1 = i / 1000;		// ����������� ����� ����� � ����
		int number2 = i / 100 % 10;	// ����������� ����� ����� � ����
		int number3 = i / 10 % 10;	// ����������� ������ ����� � ����
		int number4 = i % 10;		// ����������� �������� ����� � ����

		if (number1 == number4 && number2 == number3) // ��������, �� � �� ����� ����������
		{
			cout << i << " - �����-���i�����" << endl; // ��������� �������� ����������
		}
	}

	system("pause");
}