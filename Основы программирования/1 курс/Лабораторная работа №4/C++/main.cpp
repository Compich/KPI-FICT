#include <iostream>
#include <locale>

/* ������ 29
   ��� �������� ������������ ����� n ��������� */

using namespace std;

int main()
{
	locale::global(locale("rus")); // ������������ ���������� ������

	int n;			// ����������
	double sum = 0; // ������

	cout << "����i�� �i���i��� ����i� n: ";
	cin >> n; // �������� ������� �����

	if (n < 1) // �������� ������� ����� �� ������������
	{
		cout << "����� n �� ���� ���� ������ �� 1" << endl;
		return 0;
	}

	cout.precision(10); // ������������ ������� ������ ������ cout

	for (int i = 0; i < n; ++i)
	{
		sum = sqrt(2 + sum); // ���������� ������� ����
		cout << "sum = " << sum << endl; // ��������� �� ����� ������� ����
	}

	cout << "���������: " << sum << endl; // ��������� ����������

	system("pause");
	return 0;
}