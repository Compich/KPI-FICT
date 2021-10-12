#include <iostream>
#include <locale>
#include <cmath>

/* Варiант 29
   Наближено (iз заданою точнiстю ε
   обчислити iнтеграл, використовуючи
   формулу прямокутникiв */

using namespace std;

int main()
{
	locale::global(locale("rus"));

	double precision, h, t, a = 0, b = M_PI, sum = 0; // Оголошення
	int n, counter = 1;								  // змiнних

	cout << "Введiть точнiсть: ";
	cin >> precision; // Введення точностi

	cout << "Введiть кiлькiсть вiдрiзкiв розбиття: ";
	cin >> n; // Введеня кiлькостi вiдрiзкiв розбиття для формули
	h = (b - a) / n; // Розрахунок висоти

	cout.precision(10); // Встановлення точностi для потоку виводу на екран

	do
	{
		t = log(2 + sin(a + counter * h - h / 2)); // Обчислення наступного члена ряду
		sum += t;
		cout << "t == " << fixed << t << endl; // Виведення цього члена ряду
		++counter;
	} while (abs(t) > precision);

	sum *= h;

	cout << fixed << "Результат: " << sum << endl; // Виведення результату

	return 0;
}