#pragma once
#include "String.h"

using std::endl;

String* addToArray(String* a_rgOldArr, const String& a_sNew, size_t& a_nCurSize);
char* addToArray(char* a_rgOldArr, char a_chNew, size_t& a_nCurSize);
void outputArray(String* a_rgArr, size_t a_nSize);
bool isInArr(char* a_rgArr, size_t a_nSize, char a_ch);
char getMostPopularSymbol(const String* a_rgArr, size_t a_nArrSize, size_t& a_nRepeats);