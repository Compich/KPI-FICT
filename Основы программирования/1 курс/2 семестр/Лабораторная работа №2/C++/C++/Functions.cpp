#include "Functions.h"

TDate stringToTDate(const string& s)
{
	int day, month, year;
	char ch1, ch2;

	istringstream iss{ s };

	iss >> day >> ch1 >> month >> ch2 >> year;

	TDate dtDate;

	dtDate.day = day;
	dtDate.month = month;
	dtDate.year = year;

	validateDate(dtDate);

	return dtDate;
}

TBuyer inputBuyer()
{
	TBuyer buyer;
	int nGender;
	string sBirthday;

	cout << "Введіть прізвище покупця: ";
	cin >> buyer.surname;

	cout << "Введіть стать покупця (1 - Чоловіча, 2 - Жіноча, 0 - Інша): ";
	cin >> nGender;
	buyer.m_nGender = (nGender < 0 || 2 < nGender) ? 0 : nGender;

	cout << "Введіть дату народження покупця (Формат: DD.MM.YYYY): ";
	cin >> sBirthday;
	buyer.m_dtBirthday = stringToTDate(sBirthday);

	cout << "Введіть кількість одиниць придбаного покупцем товару: ";
	cin >> buyer.m_nAmount;

	return buyer;
}

void outputBuyer(const TBuyer& a_buyer)
{
	string sGender;

	if (a_buyer.m_nGender == 1)
	{
		sGender = "Чоловіча";
	}
	else if (a_buyer.m_nGender == 2)
	{
		sGender = "Жіноча";
	}
	else
	{
		sGender = "Інша";
	}

	cout << "Прізвище: " << a_buyer.surname << endl
		<< "Стать: " << sGender << endl
		<< "Дата народження: " << dateToString(a_buyer.m_dtBirthday) << endl
		<< "Кількість придбаного товару: " << a_buyer.m_nAmount << " шт." << endl
		<< "Знижка: " << buyerDiscount(a_buyer) << '%' << endl
		<< "Усього витрачено: " << getBuyerSpent(a_buyer) << " грн." << endl;
}

void outputBuyersList(const vector<TBuyer>& a_vBuyers)
{
	for (const TBuyer& buyer : a_vBuyers)
	{
		cout << endl;
		outputBuyer(buyer);
	}
}

void writeFile(const string& a_sName, bool a_bTruncate)
{
	ofstream ost{ a_sName, ios_base::binary | (a_bTruncate ? ios_base::out : ios_base::app) };

	bool bBreak = false;

	while (!bBreak)
	{
		TBuyer buyer = inputBuyer();

		ost.write((const char*)&buyer, sizeof(buyer));

		char ch;
		cout << "Ви бажаєте додати ще одного покупця? [y/n]: ";
		cin >> ch;

		if (ch != 'y' && ch != 'Y')
		{
			bBreak = true;
		}
	}
}

int amountOfBuyersInFile(istream& is)
{
	auto startPos = is.tellg();
	is.seekg(ios::beg, ios::end);
	int size = is.tellg() / sizeof(TBuyer);
	is.seekg(startPos);
	return size;
}

vector<TBuyer> readFile(const string& a_sName)
{
	ifstream ist{ a_sName, ios_base::binary };
	int nAmountOfBuyers = amountOfBuyersInFile(ist);

	vector<TBuyer> vBuyers;

	for (int i = 0; i < nAmountOfBuyers; ++i)
	{
		TBuyer buyer;

		ist.read((char*)&buyer, sizeof(buyer));

		vBuyers.push_back(buyer);
	}

	return vBuyers;
}

int ageOfBuyer(const TBuyer& a_buyer)
{
	TDate dtCurrent = getCurrentDate();

	int nYears;
	int aDaysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	nYears = dtCurrent.year - a_buyer.m_dtBirthday.year;

	if (dtCurrent.month < a_buyer.m_dtBirthday.month || (dtCurrent.month == a_buyer.m_dtBirthday.month && dtCurrent.day < a_buyer.m_dtBirthday.day))
	{
		--nYears;
	}

	return nYears;
}


void validateDate(TDate& a_dt)
{
	TDate dtCurrent = getCurrentDate();
	int aDaysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (dtCurrent.year < a_dt.year)
	{
		a_dt.year = dtCurrent.year;
	}
	else if (a_dt.year < 1900)
	{
		a_dt.year = 1900;
	}

	if (12 < a_dt.month)
	{
		a_dt.month = 12;
	}
	else if (a_dt.month < 1)
	{
		a_dt.month = 1;
	}

	if (a_dt.year == dtCurrent.year && dtCurrent.month < a_dt.month)
	{
		a_dt.month = dtCurrent.month;
	}

	if (aDaysInMonth[a_dt.month - 1] < a_dt.day)
	{
		a_dt.day = aDaysInMonth[a_dt.month - 1];
	}
	else if (a_dt.day < 1)
	{
		a_dt.day = 1;
	}

	if (a_dt.year == dtCurrent.year && a_dt.month == dtCurrent.month && dtCurrent.day < a_dt.day)
	{
		a_dt.day = dtCurrent.day;
	}
}

string dateToString(const TDate& a_dt)
{
	ostringstream oss;

	if (a_dt.day < 10)
	{
		oss << 0;
	}
	oss << a_dt.day << '.';

	if (a_dt.month < 10)
	{
		oss << 0;
	}
	oss << a_dt.month << '.' << to_string(a_dt.year);

	return oss.str();
}

int buyerDiscount(const TBuyer& a_buyer)
{
	int nTotalDiscount = ageOfBuyer(a_buyer);

	if (60 < nTotalDiscount)
	{
		nTotalDiscount += 5;
	}

	return 100 < nTotalDiscount ? 100 : nTotalDiscount;
}

int getShopIncome(const vector<TBuyer>& a_vBuyers)
{
	int nTotalIncome = 0;

	for (const TBuyer& buyer : a_vBuyers)
	{
		nTotalIncome += getBuyerSpent(buyer);
	}

	return nTotalIncome;
}

int getBuyerSpent(const TBuyer& a_buyer)
{
	return a_buyer.m_nAmount * 100 * (static_cast<float>(100 - buyerDiscount(a_buyer))) / 100;
}

void exportRichBuyers(const string& a_sFileName, const vector<TBuyer>& a_vBuyers, int a_nThreshold)
{
	ofstream ost{ a_sFileName, ios_base::binary };
	for (const TBuyer& buyer : a_vBuyers)
	{
		if (a_nThreshold <= getBuyerSpent(buyer))
		{
			ost.write((char*)&buyer, sizeof(TBuyer));
		}
	}
}

TDate getCurrentDate()
{
	TDate dtCurrent;

	time_t dtCurrentTimeT = time(nullptr);
	tm* dtNow = localtime(&dtCurrentTimeT);

	dtCurrent.year = dtNow->tm_year + 1900;
	dtCurrent.month = dtNow->tm_mon + 1;
	dtCurrent.day = dtNow->tm_mday;

	return dtCurrent;
}