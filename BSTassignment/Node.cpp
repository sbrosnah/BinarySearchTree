#include "Node.h"

Node::Node(int data) {
	//cout << "in Node Constructor" << endl;
	this->data = data;
	height = 0;
	leftChild = NULL;
	rightChild = NULL;
}

Node::~Node() {
	//cout << "In Node Destructor" << endl;
	leftChild = NULL;
	rightChild = NULL;
	height = 0;
	data = 0;
}

int Node::getData() const {
	//cout << "in Node::getData" << endl;
	return data;
}

void Node::setData(int data) {
	this->data = data;
}

NodeInterface * Node::getLeftChild() const {
	//cout << "in Node::getLeftChild" << endl;
	if(leftChild != NULL) {
		return leftChild;
	}
	else {
		//cout << "ERROR: leftChild is NULL" << endl;
		return NULL;
	}
}

NodeInterface * Node::getRightChild() const {
	//cout << "in Node::getRightChild" << endl;
	if(rightChild != NULL) {
		return rightChild;
	} else {
		//cout << "ERROR: rightChild is NULL" << endl;
		return NULL;
	}
}

void Node::setHeight(int num) {
	height = num;
}

int Node::getHeight() {
	return height;
}
