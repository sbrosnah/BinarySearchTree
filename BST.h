#ifndef BST_H_
#define BST_H_

#include "BSTInterface.h"
#include "Node.h"
#include <iostream>

class BST : public BSTInterface {
public:
	BST();
	~BST();
	
	NodeInterface * getRootNode() const;
	
	bool add(int num);

	void findRightMost(Node *& ptr, Node *& previous);

	void erase(Node * local, Node * prev, Node * original);

	bool find(Node *& local, Node *& prev, int num);

	void insert(Node *& insertionNode, Node *& prev, int num);

	bool traverse(Node *& local, Node *& prev, int num);

	bool remove(int num);

	void clearHelper(Node * local, Node * prev);

	void clear();
	
protected:
	Node *root;
};

#endif