#include <cmath>
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char* argv[])
{
	double x1, y1, x2, y2;
	double a;

	cout << "x1 = ";
	cin >> x1;

	cout << "y1 = ";
	cin >> y1;

	cout << "x2 = ";
	cin >> x2;

	cout << "y2 = ";
	cin >> y2;

	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

	cout << "a = " << a << endl;

	system("pause");
	return 0;
}