#include <stdio.h>
#include <math.h>

int main()
{
	double x1, y1, x2, y2;
	double a;

	printf("x1 = ");
	scanf_s("%lf", &x1);

	printf("y1 = ");
	scanf_s("%lf", &y1);

	printf("x2 = ");
	scanf_s("%lf", &x2);

	printf("y2 = ");
	scanf_s("%lf", &y2);

	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	printf("a = %f\n", a);


	system("pause");
}