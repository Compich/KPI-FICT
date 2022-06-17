#include "Node.h"
#include <locale>
#include <Windows.h>

int main()
{
	locale::global(locale("rus"));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "������� �������, �� ����� ������ � ������ (Ctrl + D ��� �������): ";
	Node root;
	for (char c; cin >> c && c != 4;)
	{
		root.addNode(c);
	}

	cout << "���������� ������:" << endl;
	printTree(&root, nullptr, false);

	cout << "��������� ������� (�����) ������: ";
	vector<char> leaves = root.getLeaves();
	for (char c : leaves)
	{
		cout << c << ' ';
	}
	cout << endl;

	return 0;
}