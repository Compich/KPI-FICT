#pragma once
#include <vector>
#include "Trunk.h"
#include <iostream>

using namespace std;

class Node
{
public:
	Node(char data);
	Node();
	~Node();
	char getData() const { return *m_data; }
	void addNode(char n);
	const Node* left() const { return m_left; }
	const Node* right() const { return m_right; }
	vector<char> getLeaves() const;
private:
	char* m_data;
	Node* m_left, * m_right;
};

void printTree(const Node* root, Trunk* prev, bool isRight);