#include "Node.h"
#include <locale>
#include <Windows.h>

int main()
{
	locale::global(locale("rus"));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Вводьте символи, що треба додати в дерево (Ctrl + D для зупинки): ";
	Node root;
	for (char c; cin >> c && c != 4;)
	{
		root.addNode(c);
	}

	cout << "Сформоване дерево:" << endl;
	printTree(&root, nullptr, false);

	cout << "Термінальні вершини (листя) дерева: ";
	vector<char> leaves = root.getLeaves();
	for (char c : leaves)
	{
		cout << c << ' ';
	}
	cout << endl;

	return 0;
}