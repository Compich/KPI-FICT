#include <iostream>

using namespace std;

/* ������ 29
   ����� ���� ����� x, y. 
   ���������, �� �������� ����� � ������������ (x, y) 
   ������������ ������ �������*/

int main()
{
	locale::global(locale("rus"));

	double x, y;
	string ans;

	cout << "����i�� ���������� x: ";
	cin >> x;
	cout << "����i�� ���������� y: ";
	cin >> y;

	if (abs(x) <= 1)
	{
		if (y <= 1)
		{
			if (abs(x) <= y)
			{
				ans = "����� �������� �����������i� ������i";
			}
			else
			{
				ans = "����� �� �������� �����������i� ������i";
			}
		}
		else
		{
			ans = "����� �� �������� �����������i� ������i";
		}
	}
	else
	{
		ans = "����� �� �������� �����������i� ������i";
	}

	cout << ans << endl;

	system("pause");

	return 0;
}