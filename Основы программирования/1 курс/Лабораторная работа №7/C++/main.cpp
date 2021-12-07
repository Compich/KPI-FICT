#include <iostream>
#include <locale>
#include <limits>
#include <iomanip>

using namespace std;

double* input_array(int);
void output_array(double*, int);
double process_array(double*, int);
void selection_sort(double*, int);
double sum_of_elements(double*, int);

int main()
{
	locale::global(locale("rus"));

	srand(time(NULL));

	int n;
	cout << "Введiть розмiр масиву: ";
	cin >> n;

	double* Y = input_array(n);
	cout << "Згенерований масив:" << endl;
	output_array(Y, n);

	double sum = process_array(Y, n);
	cout << "Масив пicля обробки:" << endl;
	output_array(Y, n);

	cout << "Сума елементiв, що знаходяться на парних позицiях: " << fixed << setprecision(2) << sum << endl;

	system("pause");

	return 0;
}

double* input_array(int size)
{
	double* Y = new double[size];
	for (int i = 0; i < size; ++i)
	{
		Y[i] = (RAND_MAX / 2 - rand()) / 100.f;
	}
	return Y;
}

void output_array(double* Y, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << setw(8) << fixed << setprecision(2) << Y[i];
	}
	cout << endl << endl;
}

double process_array(double* Y, int size)
{
	selection_sort(Y, size);
	double sum = sum_of_elements(Y, size);
	return sum;
}

void selection_sort(double* Y, int size)
{
	for (int i = 0; i < size; ++i)
	{
		int pos = i;
		double tmp = Y[i];
		for (int j = i + 1; j < size; ++j)
		{
			if (tmp < Y[j])
			{
				pos = j;
				tmp = Y[j];
			}
		}
		Y[pos] = Y[i];
		Y[i] = tmp;
	}
}

double sum_of_elements(double* Y, int size)
{
	double sum = 0;
	for (int i = 1; i < size; i += 2)
	{
		sum += Y[i];
	}
	return sum;
}