#include "BinaryTree.h"
#include <iostream>

using namespace std;

int main() {
	string name = "Suho Han";
	int number = 20192650;

	cout << number << " " << name << endl;

	typedef BinaryTree <char> charTree;
	typedef charTree* charTreePtr;

	charTreePtr bt1(new charTree);
	bt1->insert('D');

	charTreePtr bt2(new charTree);
	bt2->insert('E');

	charTreePtr bt3(new charTree);
	bt3->insert('B');
	bt3->makeLeft(bt1);
	bt3->makeRight(bt2);

	charTreePtr bt4(new charTree);
	bt4->insert('F');

	charTreePtr bt5(new charTree);
	bt5->insert('C');
	bt5->makeRight(bt4);

	charTreePtr bt6(new charTree);
	bt6->insert('A');
	bt6->makeLeft(bt3);
	bt6->makeRight(bt5);

	cout << "Root contains: " << bt6->getData() << endl;
	cout << "Left subtree root: " << bt6->left()->getData() << endl;
	cout << "Right subtree root: " << bt6->right()->getData() << endl;

	cout << "Leftmost child is: " << bt6->left()->left()->getData() << endl;
	cout << "Rightmost child is: " << bt6->right()->right()->getData() << endl;

	return 0;

}