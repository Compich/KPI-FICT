#include <iostream>

using namespace std;

/* Варіант 29
   Задані дійсні числа x, y. 
   Визначити, чи належить точка з координатами (x, y) 
   заштрихованій частині площини*/

int main()
{
	locale::global(locale("rus"));

	double x, y;
	string ans;

	cout << "Введiть координату x: ";
	cin >> x;
	cout << "Введiть координату y: ";
	cin >> y;

	if (abs(x) <= 1)
	{
		if (y <= 1)
		{
			if (abs(x) <= y)
			{
				ans = "Точка належить заштрихованiй областi";
			}
			else
			{
				ans = "Точка не належить заштрихованiй областi";
			}
		}
		else
		{
			ans = "Точка не належить заштрихованiй областi";
		}
	}
	else
	{
		ans = "Точка не належить заштрихованiй областi";
	}

	cout << ans << endl;

	system("pause");

	return 0;
}