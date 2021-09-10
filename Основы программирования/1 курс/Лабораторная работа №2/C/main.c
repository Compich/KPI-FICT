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
		printf("Точка з координатами (%lf, %lf) належить заштрихованiй частинi площини", x, y);
	}
	else
	{
		printf("Точка з координатами (%lf, %lf) не належить заштрихованiй частинi площини", x, y);
	}

	system("pause");
	return 0;
}