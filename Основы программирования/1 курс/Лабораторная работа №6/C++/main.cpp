#include <iostream>
#include <locale>
#include <iomanip>

/* ¬ар≥ант 29 */

using namespace std;

double y(double);
double f(double);
double f1(double, int);
double f2(double, int);
double fact(int);
double sum(int, int, double(double, int), double);

int main()
{
	locale::global(locale("rus"));

	double a;
	cout << "¬ведiть число а: ";
	cin >> a;
	double result = y(a);
	cout << "result == " << result << endl;

	system("pause");
}

double y(double a)
{
	double res1 = f(0.5);
	double res2 = f(a - 0.1);
	double res3 = f(4 * a - 1);
	double res = (2 * res1 - 3 * res2) / (5 - res3);
	return res;
}

double f(double x)
{
	double sum1 = sum(0, 20, f1, x);
	double sum2 = sum(0, 20, f2, x);
	double res = sum1 / sum2;
	return res;
}

double f1(double x, int k)
{
	double res = pow(x, 2 * k + 1) / fact(2 * k + 1);
	return res;
}

double f2(double x, int k)
{
	double res = pow(x, 2 * k) / fact(2 * k);
	return res;
}

double sum(int start, int end, double func(double, int), double x)
{
	double s = 0;
	for (int k = start; k <= end; ++k)
	{
		s += func(x, k);
	}
	return s;
}

double fact(int n)
{
	double f = 1;
	for (int i = 2; i <= n; ++i)
	{
		f *= i;
	}
	return f;
}
