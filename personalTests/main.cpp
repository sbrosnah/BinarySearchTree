#include <iostream>
#include "BST.h"

void PrintInOrder(NodeInterface *ptr) {
	if (ptr == NULL) {
		return;
	} else {
		if(ptr->getLeftChild() != NULL) {
			PrintInOrder(ptr->getLeftChild());
		}
		cout << ptr->getData() << ", ";
		if(ptr->getRightChild() != NULL) {
			PrintInOrder(ptr->getRightChild());
		}
	}
}

int main() {
	BST * myTree = new BST();
	
	cout << "TESTING PRINT FUNCTION" << endl;
	cout << "		testing while root = NULL" << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;

	cout << "TESTING REMOVE FUNCTION" << endl;
	cout << "		testing if root to remove has Two children" << endl;
	cout << "			testing if rightMost has children" << endl;
	cout << "				that child's child is to the right" << endl;
	myTree->add(8);
	myTree->add(18);
	myTree->add(24);
	myTree->add(12);
	myTree->add(14);
	myTree->add(16);
	myTree->add(13);
	myTree->remove(18);
	//PrintInOrder(myTree->getRootNode()); cout << endl;
	cout << "expected is 8, 12, 13, 14, 16, 24" << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();

	cout << "			testing if rightMost has no children" << endl;
	myTree->add(8);
	myTree->add(18);
	myTree->add(24);
	cout << "hello" << endl;
	myTree->add(12);
	myTree->add(14);
	myTree->add(16);
	myTree->remove(18);
	cout << "18 is removed" << endl;
	cout << "expected is 8, 12, 14, 16, 24" << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();

	cout << "			testing if that node is root" << endl;
	cout << "				if rightmost has no children" << endl;
	myTree->add(8);
	myTree->add(4);
	myTree->add(12);
	myTree->add(2);
	myTree->add(6);
	myTree->add(1);
	myTree->remove(3);
	myTree->add(10);
	myTree->add(14);
	myTree->add(5);
	myTree->add(7);
	myTree->add(9);
	myTree->add(11);
	myTree->add(13);
	myTree->add(15);
	myTree->remove(8);
	cout << "8 is removed" << endl;
	cout << "expected is 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();

	cout << "					if rightmost has children" << endl;
	cout << "						it's child's child is to the left" << endl;
	myTree->add(8);
	myTree->add(4);
	myTree->add(12);
	myTree->add(2);
	myTree->add(1);
	myTree->remove(3);
	myTree->add(10);
	myTree->add(14);
	myTree->add(9);
	myTree->add(11);
	myTree->add(13);
	myTree->add(15);
	myTree->remove(8);
	cout << "8 is removed" << endl;
	cout << "expected is 1, 2, 3, 4, 9, 10, 11, 12, 13, 14, 15," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();
	
	cout << "		testing if root to remove has one child" << endl;
	cout << "			testing if it removed isn't root" << endl;
	cout << "				if its child is to the right" << endl;
	cout << "					if parent is to the right" << endl;
	myTree->add(8);
	myTree->add(4);
	myTree->add(6);
	myTree->add(5);
	myTree->add(7);
	myTree->remove(4);
	cout << "4 is removed" << endl;
	cout << "expected is 5, 6, 7, 8," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();

	cout << "					if it's parent is to the left" << endl;
	myTree->add(2);
	myTree->add(4);
	myTree->add(6);
	myTree->add(5);
	myTree->add(7);
	myTree->remove(4);
	cout << "4 is removed" << endl;
	cout << "expected is 2, 5, 6, 7," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();

	cout << "				if it's child is to the left" << endl;
	cout << "					if it's parent is to the right" << endl;
	myTree->add(8);
	myTree->add(6);
	myTree->add(4);
	myTree->add(3);
	myTree->add(5);
	myTree->remove(6);
	cout << "6 is removed" << endl;
	cout << "expected is 3, 4, 5, 8," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();
	cout << "					if it's parent is to the left" << endl;
	myTree->add(6);
	myTree->add(5);
	myTree->add(2);
	myTree->add(1);
	myTree->add(3);
	myTree->remove(5);
	cout << "5 is removed" << endl;
	cout << "expected is 1, 2, 3, 6," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();

	cout << "TESTING IF NODE TO REMOVE HAS NO CHILDREN" << endl;
	cout << " it's parent is to the left" << endl;
	myTree->add(6);
	myTree->add(5);
	myTree->add(2);
	myTree->add(1);
	myTree->add(3);
	myTree->remove(3);
	cout << "3 is removed" << endl;
	cout << "expected is 1, 2, 5, 6," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();
	cout << "	it's parent is to the right" << endl;
	myTree->add(6);
	myTree->add(5);
	myTree->add(2);
	myTree->add(1);
	myTree->add(3);
	myTree->remove(1);
	cout << "1 is removed" << endl;
	cout << "expected is 2, 3, 5, 6," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();
	
	cout << "REMOVE ALL AND THEN ADD" << endl;
	myTree->add(6);
	myTree->add(5);
	myTree->add(2);
	myTree->add(1);
	myTree->add(3);
	myTree->remove(6);
	myTree->remove(5);
	myTree->remove(2);
	myTree->remove(1);
	myTree->remove(3);
	cout << "expected: " << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl << endl;

	cout << "TESTING REMOVE IF DATA ISN'T IN TREE" << endl;
	myTree->add(6);
	myTree->add(5);
	myTree->add(2);
	myTree->add(1);
	myTree->add(3);
	bool notR = myTree->remove(7);
	if(!notR) {
			cout << "7 is not removed" << endl;
	}
	cout << "expected is 1, 2, 3, 5, 6," << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();

	cout << "TESTING IF NODE TO REMOVE IS ROOT AND HAS ONE CHILD" << endl;
	cout << " if that is a right child" << endl;
	myTree->add(8);
	myTree->add(10);
	myTree->add(12);
	myTree->remove(8);
	cout << "expected is 10, 12" << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();
	cout << "	if this is a left child" << endl;
	myTree->add(8);
	myTree->add(6);
	myTree->add(4);
	myTree->remove(8);
	cout << "expected is 4, 6" << endl;
	PrintInOrder(myTree->getRootNode());
	cout << endl;
	myTree->clear();
	delete myTree;

	}