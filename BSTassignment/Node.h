#pragma once

#include "NodeInterface.h"
#include <iostream>
using namespace std;

class Node : public NodeInterface {
public:
	Node(int data);
	~Node();

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	int getData() const;

	void setData(int data);

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	NodeInterface * getRightChild() const;

	int getHeight();

	void setHeight(int num);

protected:
	int data;
	int height;
private:
	Node *leftChild;
	Node *rightChild;
	friend class BST;
	friend class AVL;
};