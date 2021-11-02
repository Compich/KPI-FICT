#include <iostream>
#include <locale>

/* ������ 29
   ������ �� ������������� ��������� */

using namespace std;

int main()
{
	locale::global(locale("rus"));

	for (int num = 1000; num < 10000; ++num)
	{
		bool palindrome = true; // �����������
		int numlen = 0;			// 
		int tempnum = num;		// ������

		while (tempnum)	// ����������� ������� �����
		{
			++numlen;
			tempnum /= 10;
		}

		for (int i = 0; i < numlen / 2; ++i)	// �������� �� ��, �� � ����� ����������
		{
			int first = num / pow(10, numlen - 1 - i);	// ����������� ��������
			first %= 10;								// ������ ����� �����

			int last = 0;	// ����������� �����, �� ���������� ������� ����� �����

			tempnum = num;	// ������� �������� �������� ����� tempnum, ��� �� �������� ����� �����

			for (int o = 0; o <= i; ++o)	// ����������� �������� ������� ����� �����
			{
				last = tempnum % 10;
				tempnum /= 10;
			}

			if (first != last)	// ���� ����� ����� �� ������� �������, �� ����� - �� ��������
			{
				palindrome = false;
			}
		}

		if (palindrome)	// ���� ����� � ����������, �������� ����
		{
			cout << num << " - �����-���i�����" << endl;
		}
	}

	system("pause");
}