#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void writeFile(const string& sName, bool bTruncate, bool bIgnoreCin);
vector<string> readFile(const string& name);
void outputVector(const vector<string>& v, bool bEndWithNewline = true, ostream& os = cout);
vector<string> findUniqueElements(const vector<string>& vFirstLines, const vector<string>& vSecondLines);