#include "Functions.h"

void writeFile(const string& sName, bool bTruncate, bool bIgnoreCin)
{
	ofstream ost{ sName, bTruncate ? ios_base::out : ios_base::app };
	ost.imbue(locale("rus_rus.1251"));

	bool bBreak = false;

	if (bIgnoreCin)
	{
		cin.ignore();
	}

	while (!bBreak)
	{
		string sLine = "";

		getline(cin, sLine);

		int nBreakPos = sLine.find(0x7);

		sLine = sLine.substr(0, nBreakPos);

		if (sLine.length() != 0)
		{
			ost << sLine << endl;
		}

		if (nBreakPos != -1)
		{
			bBreak = true;
		}
	}
}

vector<string> readFile(const string& name)
{
	vector<string> vLines;
	ifstream ist{ name };
	string sLine;
	while (!ist.eof())
	{
		getline(ist, sLine);
		if (sLine.length() != 0)
		{
			vLines.push_back(sLine);
		}
	}
	return vLines;
}

void outputVector(const vector<string>& v, bool bEndWithNewline, ostream& os)
{
	for (int i = 0; i < v.size(); ++i)
	{
		os << v[i];

		if (bEndWithNewline || i != v.size() - 1)
		{
			os << endl;
		}
	}
}

vector<string> findUniqueElements(const vector<string>& vFirstLines, const vector<string>& vSecondLines)
{
	vector<string> vUniqueElements;

	for (const string& sLine : vFirstLines)
	{
		auto it = find(vSecondLines.begin(), vSecondLines.end(), sLine);

		if (it == vSecondLines.end() && find(vUniqueElements.begin(), vUniqueElements.end(), sLine) == vUniqueElements.end())
		{
			vUniqueElements.push_back(sLine);
		}
	}

	return vUniqueElements;
}
