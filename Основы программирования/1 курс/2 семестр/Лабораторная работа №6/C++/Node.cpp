#include "Node.h"

void printTree(const Node* root, Trunk* prev, bool isRight)
{
	if (root != nullptr) {

		string prev_str = "    ";
		Trunk* trunk = new Trunk(prev, prev_str);

		printTree(root->right(), trunk, true);

		if (!prev)
		{
			trunk->m_str = "---";
		}
		else if (isRight)
		{
			trunk->m_str = ".---";
			prev_str = "   |";
		}
		else
		{
			trunk->m_str = "`---";
			prev->m_str = prev_str;
		}

		cout << *trunk;
		cout << " " << root->getData() << endl;

		if (prev)
		{
			prev->m_str = prev_str;
		}
		trunk->m_str = "   |";

		printTree(root->left(), trunk, false);
	}
}

Node::Node(char data)
	:m_data{ new char },
	m_left{ nullptr },
	m_right{ nullptr }
{
	*m_data = data;
}

Node::Node()
	:m_data{ nullptr },
	m_left{ nullptr },
	m_right{ nullptr }
{}

Node::~Node()
{
	if (m_data)
	{
		delete m_data;
	}
	if (m_left)
	{
		delete m_left;
	}
	if (m_right)
	{
		delete m_right;
	}
}

void Node::addNode(char n)
{
	if (!m_data)
	{
		m_data = new char{ n };
	}
	else if (n < *m_data)
	{
		if (m_left)
		{
			m_left->addNode(n);
		}
		else
		{
			m_left = new Node(n);
		}
	}
	else
	{
		if (m_right)
		{
			m_right->addNode(n);
		}
		else
		{
			m_right = new Node(n);
		}
	}
}

vector<char> Node::getLeaves() const
{
	vector<char> leaves;
	if (m_left)
	{
		vector<char> leftLeaves = m_left->getLeaves();
		for (char c : leftLeaves)
		{
			leaves.push_back(c);
		}
	}
	if (m_right)
	{
		vector<char> rightLeaves = m_right->getLeaves();
		for (char c : rightLeaves)
		{
			leaves.push_back(c);
		}
	}
	if (!m_left && !m_right)
	{
		leaves.push_back(*m_data);
	}
	return leaves;
}