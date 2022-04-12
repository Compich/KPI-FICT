#include "TDate.h"

TDate::TDate(int a_nDay, int a_nMonth, int a_nYear)
	:day{ a_nDay }, month{ a_nMonth }, year{ a_nYear }
{
	time_t dtCurrentTimeT = time(nullptr);
	tm* dtNow = localtime(&dtCurrentTimeT);
	
	int now_year = dtNow->tm_year + 1900;
	int now_month = dtNow->tm_mon + 1;
	int now_day = dtNow->tm_mday;

	int aDaysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (now_year < this->year)
	{
		this->year = now_year;
	}
	else if (this->year < 1900)
	{
		this->year = 1900;
	}

	if (12 < this->month)
	{
		this->month = 12;
	}
	else if (this->month < 1)
	{
		this->month = 1;
	}

	if (this->year == now_year && now_month < this->month)
	{
		this->month = now_month;
	}

	if (aDaysInMonth[this->month - 1] < this->day)
	{
		this->day = aDaysInMonth[this->month - 1];
	}
	else if (this->day < 1)
	{
		this->day = 1;
	}

	if (this->year == now_year && this->month == now_month && now_day < this->day)
	{
		this->day = now_day;
	}
}

TDate TDate::getCurrentDate()
{
	time_t dtCurrentTimeT = time(nullptr);
	tm* dtNow = localtime(&dtCurrentTimeT);

	return TDate(dtNow->tm_mday, dtNow->tm_mon + 1, dtNow->tm_year + 1900);
}

ostream& operator << (ostream& os, const TDate& a_dt)
{
	if (a_dt.day < 10)
	{
		os << 0;
	}
	os << a_dt.day << '.';

	if (a_dt.month < 10)
	{
		os << 0;
	}
	os << a_dt.month << '.' << to_string(a_dt.year);

	return os;
}

//istream& operator >> (istream& is, TDate& a_dt)
//{
//	int day, month, year;
//	int ch1, ch2;
//	
//	is >> day >> ch1 >> month >> ch2 >> year;
//
//	a_dt = TDate(day, month, year);
//
//	return is;
//}

TDate::TDate()
{
	int nDay, nMonth, nYear;
	int aDaysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	nYear = 1950 + rand() % 55;
	nMonth = 1 + rand() % 12;
	nDay = 1 + rand() % aDaysInMonth[nMonth];

	day = nDay;
	month = nMonth;
	year = nYear;
}