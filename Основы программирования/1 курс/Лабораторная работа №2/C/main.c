#include <stdio.h>
#include <locale.h>
#include < math.h >

int main()
{
	double x, y;

	printf("x = ");
	scanf_s("%lf", &x);

	printf("y = ");
	scanf_s("%lf", &y);

	setlocale(LC_ALL, "ukr");
	if (fabs(x) <= 1 && 0 <= y && y <= 1 && fabs(x) <= y)
	{
		printf("����� � ������������ (%lf, %lf) �������� �����������i� ������i �������", x, y);
	}
	else
	{
		printf("����� � ������������ (%lf, %lf) �� �������� �����������i� ������i �������", x, y);
	}

	system("pause");
	return 0;
}