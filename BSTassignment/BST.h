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

	bool addHelper(int num, Node *& local);

	void findRightMost(Node *& ptr, Node *& previous);

	//void erase(Node * local, Node * prev, Node * original);

	//bool find(Node *& local, Node *& prev, int num);

	//void insert(Node *& insertionNode, Node *& prev, int num);

	//bool traverse(Node *& local, Node *& prev, int num, int& currDepth);

	int findParentalDetails(Node * local, Node * prev);

	void calculateHeightAfterRemoval(Node * ptr);

	bool hasNoChildrenRemoval(Node * local, Node * prev);

	bool hasTwoChildrenRemoval(Node * local, Node * prev);

	bool hasOneChildRemoval(Node * local, Node * prev);

	int findRemovalDetails(Node * local, Node * prev);

	bool removeHelper(int num, Node *& local, Node *& prev);

	bool remove(int num);

	void calculateHeight(Node * ptr);

	int getHeight(Node * ptr);

	void clearHelper(Node * local, Node * prev);

	void clear();
	
private:
	Node *root;
	friend class AVL;
};

#endif