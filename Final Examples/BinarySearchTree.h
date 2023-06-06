#pragma once
#include "BinaryTree.h"
#include <assert.h>

template <class btElementType>
class BST : public BinaryTree<btElementType> {
public:
	BST();
	virtual void insert(const btElementType& d);
	virtual BinaryTree<btElementType>* retrieve(const btElementType& d);
protected:
	using BinaryTree <btElementType>::nullTree;
	using BinaryTree <btElementType>::treeData;
	using BinaryTree <btElementType>::leftTree;
	using BinaryTree <btElementType>::rightTree;
};

template <class btElementType>
void
BST<btElementType>
::insert(const btElementType& d) {
	if (nullTree) {
		nullTree = false;
		leftTree = new BST;
		rightTree = new BST;
		treeData = d;
	}
	else if (d == treeData) {
		treeData = d;
	}
	else if (d < treeData) {
		leftTree->insert(d);
	}
	else {
		rightTree->insert(d);
	}
}

template <class btElementType>
BinaryTree<btElementType>*
BST<btElementType>
::retrieve(const btElementType& d) {
	if (nullTree || d == treeData) {
		return this;
	}
	else if (d < treeData) {
		return ((BST<btElementType>*)leftTree)->retrieve(d);
	}
	else {
		return ((BST<btElementType>*)rightTree)->retrieve(d);
	}
}

template <class btElementType>
BST<btElementType>
::BST() : BinaryTree<btElementType>()
{

}