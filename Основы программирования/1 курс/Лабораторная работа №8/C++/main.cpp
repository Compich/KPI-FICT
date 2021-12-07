#include <iostream>
#include <locale>
#include <limits>
#include <iomanip>

using namespace std;

double** input_matrix(int);
void output_matrix(double**, int);
void output_array(double*, int);
double* process_matrix(double**, int);

int main()
{
	locale::global(locale("rus"));

	srand(time(NULL));

	int n;
	cout << "¬ведiть розмiр матрицi: ";
	cin >> n;

	double** B = input_matrix(n);
	cout << "«генерована матриц€:" << endl;
	output_matrix(B, n);

	double* X = process_matrix(B, n);
	cout << "—кал€рний добуток i-го р€дка матрицi на стовпцi, що мiст€ть найменшi елементи радкiв:" << endl;
	output_array(X, n);

	system("pause");

	return 0;
}

double** input_matrix(int size)
{
	double** B = new double* [size];
	for (int i = 0; i < size; ++i)
	{
		B[i] = new double[size];
		for (int j = 0; j < size; ++j)
		{
			B[i][j] = (RAND_MAX / 2 - rand()) / 100.f;
		}
	}
	return B;
}

void output_matrix(double** matrix, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << setw(8) << fixed << setprecision(2) << matrix[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void output_array(double* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << setw(10) << fixed << setprecision(2) << arr[i];
	}
	cout << endl << endl;
}

double* process_matrix(double** A, int size)
{
	double* X = new double[size];
	for (int i = 0; i < size; ++i)
	{
		double min_element = A[i][0];
		int min_element_column = 0;
		for (int j = 1; j < size; ++j)
		{
			if (A[i][j] < min_element)
			{
				min_element = A[i][j];
				min_element_column = j;
			}
		}

		X[i] = 0;

		for (int o = 0; o < size; ++o)
		{
			X[i] += A[i][o] * A[o][min_element_column];
		}
	}
	return X;
}
