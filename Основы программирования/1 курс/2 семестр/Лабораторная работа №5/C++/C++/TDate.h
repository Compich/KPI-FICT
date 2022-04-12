#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <string>
using namespace std;
struct TDate
{
	TDate(int a_nDay, int a_nMonth, int a_nYear);
	TDate();
	static TDate getCurrentDate();
	int day;
	int month;
	int year;
};

ostream& operator << (ostream&, const TDate&);
//istream& operator >> (istream&, TDate&);