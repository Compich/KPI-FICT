#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include "TBuyer.h"

using namespace std;

TDate stringToTDate(const string&);
TBuyer inputBuyer();
void outputBuyer(const TBuyer&);
void outputBuyersList(const vector<TBuyer>&);
void writeFile(const string&, bool);
int amountOfBuyersInFile(istream&);
vector<TBuyer> readFile(const string&);
int ageOfBuyer(const TBuyer&);
TDate getCurrentDate();
void validateDate(TDate&);
string dateToString(const TDate&);
int buyerDiscount(const TBuyer&);
int getShopIncome(const vector<TBuyer>&);
int getBuyerSpent(const TBuyer&);
void exportRichBuyers(const string&, const vector<TBuyer>&, int);