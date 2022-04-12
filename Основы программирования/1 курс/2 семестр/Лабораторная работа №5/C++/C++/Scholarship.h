#pragma once
#include <iostream>

using std::ostream;
using std::istream;

enum class Scholarship
{
	None, Default, Increased
};

ostream& operator << (ostream&, const Scholarship&);