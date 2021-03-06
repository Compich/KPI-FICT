/*
* 1 ????, 2 ???????, ?????? ?????????????, ??????????? ?????? ?5.
*
* ??????? 29
* ???????????? ???? "?????", ???? ??????? ϲ?, ???? ?????????? ? ??????
* ?????????? ?? ???? ?? ?????????? ????????? ?????????. ?? ?????? ????? ?????
* ???????? ?????-??????? "???????", ???? ??????? ????????? ????? ???????????
* ????? ????????, ???????? ??????????? ??? ?? ???????????? ????????? ?????,
* ?????? ????????? ??????䳿 ? ?????? ??????? (?????????, ????????, ?????), ??
* "????????", ???? ??????? ????????? ????? ?????????, ??? ???????? ?????
* ???????, ??????? ????????? ?????, ??? ??????? ???????? ?? ?????? ??????????,
* ?? ??????. ???????? n ????????? ? m ??????????. ??? ????????? ???????????
* ?????? ???????? ??????䳿 (?????????, ???? ??????????? ??? ?????? 95, ?
* ???????? - ???? ???????? ??????????? ??? ?????? 85, ??? ????? 95), ???
* ?????????? - ??????? ????????? ?????. ????????? ??? ?????????, ?? ???
* ????????? ??????? ????????? ?????.
*/
#include <locale>
#include <Windows.h>
#include "Functions.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	locale::global(locale("rus_rus.1251"));

	srand(time(nullptr));

	size_t n, m;
	cout << "??????? ????????? ????????????: ";
	cin >> n;
	cout << "??????? ?????????? ????????????: ";
	cin >> m;

	Student* rgStudents = generateStudents(n);
	Teacher* rgTeachers = generateTeachers(m);

	cout << endl << "??????????? ????????:" << endl;
	outputStudents(rgStudents, n);
	cout << "??????????? ?????????:" << endl;
	outputTeachers(rgTeachers, m);

	if (m)
	{
		Teacher teacherWithHighestSalary = getTeacherWithHighestSalary(rgTeachers, m);

		cout << "???????? ?? ?????????? ?????????:" << endl << teacherWithHighestSalary << endl;
	}

	system("pause");
	return 0;
}