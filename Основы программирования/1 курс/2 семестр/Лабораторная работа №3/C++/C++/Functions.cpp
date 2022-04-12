#include "Functions.h"

String* addToArray(String* a_rgOldArr, const String& a_sNew, size_t& a_nCurSize)
{
	String* newArr = new String[a_nCurSize + 1];

	for (size_t i = 0; i < a_nCurSize; ++i)
	{
		newArr[i] = a_rgOldArr[i];
	}

	if (a_rgOldArr != nullptr)
	{
		delete[] a_rgOldArr;
	}

	newArr[a_nCurSize] = a_sNew;

	++a_nCurSize;

	return newArr;
}

char* addToArray(char* a_rgOldArr, char a_chNew, size_t& a_nCurSize)
{
	char* newArr = new char[a_nCurSize + 1];

	for (size_t i = 0; i < a_nCurSize; ++i)
	{
		newArr[i] = a_rgOldArr[i];
	}

	if (a_rgOldArr != nullptr)
	{
		delete[] a_rgOldArr;
	}

	newArr[a_nCurSize] = a_chNew;

	++a_nCurSize;

	return newArr;
}

void outputArray(String* a_rgArr, size_t a_nSize)
{
	for (size_t i = 0; i < a_nSize; ++i)
	{
		cout << i + 1 << ". ";
		a_rgArr[i].output(cout);
		cout << endl;
	}
}

bool isInArr(char* a_rgArr, size_t a_nSize, char a_ch)
{
	bool bIsInArr = false;

	for (size_t i = 0; i < a_nSize; ++i)
	{
		if (a_rgArr[i] == a_ch)
		{
			bIsInArr = true;
		}
	}
	
	return bIsInArr;
}

char getMostPopularSymbol(const String* a_rgArr, size_t a_nArrSize, size_t& a_nRepeats)
{
	char* rgUniqueChars = nullptr;
	size_t nUniqueSize = 0;

	for (size_t i = 0; i < a_nArrSize; ++i)
	{
		for (size_t j = 0; j < a_rgArr[i].symbolsCount(); ++j)
		{
			if (!isInArr(rgUniqueChars, nUniqueSize, a_rgArr[i].getSymbol(j)))
			{
				rgUniqueChars = addToArray(rgUniqueChars, a_rgArr[i].getSymbol(j), nUniqueSize);
			}
		}
	}

	char chMostPopular = a_rgArr[0].getSymbol(0);
	a_nRepeats = 0;

	for (size_t i = 0; i < nUniqueSize; ++i)
	{
		char chToFind = rgUniqueChars[i];
		size_t nLocalRepeats = 0;

		for (int j = 0; j < a_nArrSize; ++j)
		{
			nLocalRepeats += a_rgArr[j].count(chToFind);
		}

		if (a_nRepeats < nLocalRepeats)
		{
			chMostPopular = chToFind;
			a_nRepeats = nLocalRepeats;
		}
	}

	return chMostPopular;
}