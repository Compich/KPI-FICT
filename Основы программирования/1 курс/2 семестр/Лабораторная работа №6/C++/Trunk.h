#pragma once
#include <string>
#include <iostream>

using namespace std;

struct Trunk
{
	Trunk(Trunk* prev, string str);

	Trunk* m_prev;
	string m_str;
};

ostream& operator << (ostream& os, const Trunk& trunk);