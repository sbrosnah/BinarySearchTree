#include "BST.h"

BST::BST() {
	//cout << "In constructor" << endl;
	root = NULL;
}

BST::~BST() {
	//cout << "in Destructor" << endl;
	if(root != NULL) {
		clear();
		root = NULL;
	} else {
		//cout << "already clear" << endl;

	}
}


NodeInterface * BST::getRootNode() const {
	if(root != NULL) {
		return root;
	} else {
		//cout << "ERROR: root is NULL" << endl;
		return NULL;
	}
}
/*
bool BST::traverse(Node *& local, Node *& prev, int num, int& currDepth) {
	//cout << "in traverse" << endl;
	bool found = false;
	if (root != NULL) {
		if(local != NULL && local->data == num) {
			//cout << "data found in tree. don't add" << endl;
			return true;
		} else if(local != NULL && local->data > num){
			//cout << "data is smaller than localRoot" << endl;
			//cout << "current localRoot is not the end. recurse" << endl;
			currDepth++;
			found = traverse(local->leftChild, local, num, currDepth);
			
			return found;
		} else if (local != NULL && local->data < num){
			//cout << "data is larger than local Root" << endl;
			//cout << "courrent localRoot is not the end. recurse" << endl;
			currDepth++;
			found = traverse(local->rightChild, local, num, currDepth);
			return found;
		} else {
			//cout << "at an end. add data here" << endl;
			insert(local, prev, num);
			return false;
		}
	} else {
		//cout << "no data in tree" << endl;
		insert(local, prev, num);
		return false;
	}
	return false;
}

void BST::insert(Node *& local, Node *& prev, int num) {
	if(root == NULL) {
		//cout << "creating a root pointer" << endl;
		root = new Node(num);
		//calculateHeight(root);
		//cout << "root is: " << root->data << endl;
	} else {
		//cout << "creating a localRoot" << endl;
		//calculateHeight(prev);
		if(prev->data < num) {
			//cout << " at previous' right child" << endl;
			//cout << "inserting: " << num << endl;
			local = new Node(num);
			prev->rightChild = local;
		} else if (prev->data > num) {
			//cout << " at previous' left child" << endl;
			//cout << "inserting: " << num << endl;
			local = new Node(num);
			prev->leftChild = local;
		} else {
			//cout << "error in BST::insert. uncaught exceptrion" << endl;
		}
	}
}

bool BST::add(int num) {
	//cout << " in add" << endl;
	Node * localRoot;
	Node * previous;
	localRoot = root;
	previous = root;
	int currDepth = 0;
	bool inTree = traverse(localRoot, previous, num, currDepth);
	if(!inTree) {
		return true;
	} else {
		return false;
	} 
}
*/

bool BST::addHelper(int num, Node *& local) {
	if(local == NULL) {
		local = new Node(num);
		return true;
	} else if (local->getData() == num) {
		return false;
	} else if (num < local->getData()) {
		bool rval = addHelper(num, local->leftChild);
		calculateHeight(local);
		return rval;
	} else if (num > local->getData()) {
		bool rval = addHelper(num, local->rightChild);
		calculateHeight(local);
		return rval;
	}
	return false;
}

bool BST::add(int num) {
	bool added = addHelper(num, root);
	return added;
}


void BST::findRightMost(Node *& ptr, Node *& prev) {
	if (ptr->rightChild != NULL) {
		prev = ptr;
		ptr = ptr->rightChild;
		findRightMost(ptr, prev);
	} 
} 
/*
bool BST::find(Node *& local, Node *& prev, int num) {
	//cout << "finding..." << endl;
	bool found = false;
	if(local != NULL && local->data == num) {
		//cout << "found; local are previous roots are set" << endl;
		return true;
	} else {
		if(local != NULL && num < local->data) {
			//cout << "data is less than local root and local root has left child... recurse" << endl;
			prev = local;
			local = local->leftChild;
			found = find(local, prev, num);
			calculateHeight(prev);
			return found;
		} else if(local != NULL && num > local->data){
			//cout << "data is greater than localRoot and localRoot has rightChild... recurse" << endl;
			prev = local;
			local = local->rightChild;
			found = find(local, prev, num);
			calculateHeight(prev);
			return found;
		} else {
			//cout << "not found" << endl;
			if(root != NULL) {
				//cout << "set localRoot back to root for next time" << endl;
				local = root;
			} else {
				//cout << "tree is empty; set all else to NULL" << endl;
				prev = NULL;
				local = NULL;
			}
			return false;
		} 
	}
	return false; 
}
*/
/* 
rearranges the data to the right of a localRoot that was removed which had two children. 
*/
/*
void BST::erase(Node * local, Node * prev, Node * original) {
	//cout << "in erase" << endl;
	//cout << "local is: " << local->data << endl;
	//cout << "prev is: " << prev->data << endl;
	//cout << "original is: " << original->data << endl;
	if(local->leftChild == NULL && local->rightChild == NULL) {
		//cout << "local has no children" << endl;
		if(prev != original) {
			//cout << "local's parent is not original" << endl;
			prev->rightChild = NULL;
			delete local;
			return;
		} else {
			prev->leftChild = NULL;
			delete local;
			return;
		}
	} else {
		//cout << "local has children" << endl;
		//cout << "local has a left child" << endl;
		if(prev != original) {
			//cout << "local's parent is not original" << endl;
			prev->rightChild = local->leftChild;
			delete local;
			//cout << "deletion successful" << endl;
			return;
		} else {
			//cout << "local's parent is original" << endl;
			prev->leftChild = local->leftChild;
			delete local;
			return;
		}
	}	
}


bool BST::remove(int num) {
	//cout << "in remove" << endl;
	Node * localRoot;
	Node * previous;
	localRoot = root;
	previous = root;
	bool found = find(localRoot, previous, num);
	if(found) {
		
		if(localRoot->leftChild != NULL && localRoot->rightChild != NULL) {
			//cout << "there are two children" << endl;
			previous = localRoot;
			Node * largestRightChild = localRoot->leftChild;
			findRightMost(largestRightChild, previous);
			//cout << "localRoot is: " << localRoot->data << endl;
			//cout << "largestRightChild is: " << largestRightChild->data << endl;
			//cout <<"previous is: " << previous->data << endl;
			localRoot->data = largestRightChild->data;
			//cout << "new localRoot is: " << localRoot->data << endl;
			erase(largestRightChild, previous, localRoot);
			return true;
		} else if (localRoot->leftChild == NULL && localRoot->rightChild == NULL) {
			//cout << "there are no children" << endl;
			if(localRoot == root) {
				//cout << "deleting last node in tree" << endl;
				clear();
				return true;
			}
			if(previous->leftChild != NULL && previous->leftChild->data == localRoot->data) {
				//cout << "it's parent is to the right" << endl;
				previous->leftChild = NULL;
				delete localRoot;
				return true;
			} else {
				//cout << "it's parent is to the left" << endl;
				previous->rightChild = NULL;
				delete localRoot;
				return true;
			}
		} else {
			//cout << "there is one child" << endl;
			if(localRoot->leftChild != NULL) {
				//cout << "it is a leftChild" << endl;
				if(previous->data > localRoot->data) {
					//cout << "parent is to the right" << endl;
					previous->leftChild = localRoot->leftChild;
					delete localRoot;
					return true;
				} else if (previous->data < localRoot->data) {
					//cout << "parent is to the left" <<endl;
					previous->rightChild = localRoot->leftChild;
					delete localRoot;
					return true;
				} else {
					//cout << "we are deleting the root node which has one child" << endl;
					if(localRoot->rightChild != NULL) {
						//cout << "root's rightChild becomes new root" << endl;
						root = localRoot->rightChild;
						delete localRoot;
						return true;
					} else {
						//cout << "root's leftChild becomes new root" << endl;
						root = localRoot->leftChild;
						delete previous;
						return true;
					}
				}
			} else {
				//cout << "it is a rightChild" << endl;
				if(previous->data > localRoot->data) {
					//cout << "parent is to the right" << endl;
					previous->leftChild = localRoot->rightChild;
					delete localRoot;
					return true;
				} else if (previous->data < localRoot->data) {
					//cout << "parent is to the left" <<endl;
					previous->rightChild = localRoot->rightChild;
					delete localRoot;
					return true;
				} else {
					//cout << "we are deleting the root node which has one child" << endl;
					if(localRoot->rightChild != NULL) {
						//cout << "root's rightChild becomes new root" << endl;
						root = localRoot->rightChild;
						delete localRoot;
						return true;
					}
				}
			}
		}
	} else {
		//cout << "not found" << endl;
		return false;
	}
	return false;
}
*/

int BST::findParentalDetails(Node * local, Node * prev) {
	if(prev->rightChild == local) {
		//cout << "parent is to the left" << endl;
		return 1;
	} else if(prev->leftChild == local) {
		//cout << "parent is to the right" << endl;
		return 2;
	} else {
		//cout << "prev == local" << endl;
		return 3;
	}
cout << "error in findParentalDetails" << endl;
return 0;
}

bool BST::hasNoChildrenRemoval(Node * local, Node * prev){
	if(prev->rightChild == local) {
		prev->rightChild = NULL;
		delete local;
		return true;
	}else if(prev->leftChild == local) {
		prev->leftChild = NULL;
		delete local;
		return true;
	} else {
		clear();
		return true;
	}
	return false;
}

bool BST::hasTwoChildrenRemoval(Node * local, Node * prev){
	Node *largestRightChild = local->leftChild;
	prev = local;
	findRightMost(largestRightChild, prev);
	local->data = largestRightChild->data;
	int details = findRemovalDetails(largestRightChild, prev);
	if(details == 2) {
		//cout << "there is one child" << endl;
		if(prev == root) {
			prev->leftChild = largestRightChild->leftChild;
			delete largestRightChild;
			return true;
		} else {
			prev->rightChild = largestRightChild->leftChild;
			delete largestRightChild;
			return true;
		}
	} else if (details == 3) {
		//cout << "there are no children" << endl;
		details = findParentalDetails(largestRightChild, prev);
		if(details == 1) {
			prev->rightChild = NULL;
			delete largestRightChild;
			return true;
		}else if (details == 2) {
			prev->leftChild = NULL;
			delete largestRightChild;
			return true;
		} else {
			cout << "error in hasTwoChildrenRemoval" << endl;	
		}
	}
}

bool BST::hasOneChildRemoval(Node * local, Node * prev){
	int details = findParentalDetails(local, prev);
	if(local->rightChild != NULL) {
		if(details == 1) {
			//cout << "prev is: " << prev->data << endl;
			//cout << "local is: " << local->data << endl;
			//cout << "local->rightChild is: " << local->rightChild->data << endl;
			prev->rightChild = local->rightChild;
			delete local;
			//local = NULL;
			return true;
		} else if(details == 2) {
			prev->leftChild = local->rightChild;
			delete local;
			local = NULL;
			return true;
		} else if(details == 3) {
			root = local->rightChild;
			delete local;
			local = NULL;
			return true;
		} else {
			cout << "error in hasOneChildRemoval: has rightChild" << endl;
		}
	} else {
		if(details == 1) {
			prev->rightChild = local->leftChild;
			delete local;
			local = NULL;
			return true;
		} else if(details == 2) {
			prev->leftChild = local->leftChild;
			delete local;
			local = NULL;
			return true;
		} else if(details == 3) {
			root = local->leftChild;
			delete local;
			local = NULL;
			return true;
		} else {
			cout << "error in hasOneChildRemoval: has leftChild" << endl;
		}
	}
	return false;
}

int BST::findRemovalDetails(Node *local, Node *prev) {
	if(local->rightChild != NULL && local->leftChild != NULL) {
		//cout << "there are 2 children" << endl;
		return 1;
	}else if(local->rightChild == NULL ^ local->leftChild == NULL) {
		//cout << "there is 1 child" << endl;
		return 2;
	} else {
		//cout << "there are no children" << endl;
		return 3;
	}
	cout << "error" << endl;
	return 0;
}

void BST::calculateHeightAfterRemoval(Node * ptr) {
	if(ptr == NULL) {
		return;
	}
	int max = 0;
	
	if(ptr->leftChild == NULL && ptr->rightChild == NULL) {
		ptr->setHeight(0);
		return;
	}
	
	if(getHeight(ptr->leftChild) > max) {
		max = getHeight(ptr->leftChild);
	}
	if(getHeight(ptr->rightChild) > max) {
		max = getHeight(ptr->rightChild);
	}
	ptr->setHeight(max + 1);

	//cout << "height calculated for " << ptr->data << " is: " << ptr->getHeight() << endl;
}

bool BST::removeHelper(int num, Node *& local, Node *& prev) {
	if(local == NULL) {
		return false;
	} else if (local->data == num) {
		bool removed = false;
		int details = findRemovalDetails(local, prev);
		if(details == 1) {
			//cout << local->data << "has 2 children " << endl;
			removed = hasTwoChildrenRemoval(local, prev);
		} else if(details == 2) {
			//cout << local->data << " has 1 child ";
			removed = hasOneChildRemoval(local, prev);
		} else if(details == 3) {
			//cout << "has no children" << endl;
			removed = hasNoChildrenRemoval(local, prev);
		} else {
			cout << "error in removeHelper" << endl;
		}
		return removed;
	} else if (num < local->data) {
		//cout << "traversing..." << endl;
		//cout << "local is: " << local->data << endl;
		//cout << "prev is: " << prev->data << endl;
		bool rval = removeHelper(num, local->leftChild, local);
		calculateHeightAfterRemoval(local);
		return rval;
	} else if (num > local->data) {
		//cout << "traversing..." << endl;
		//cout << "local is: " << local->data << endl;
		//cout << "prev is: " << prev->data << endl;
		bool rval = removeHelper(num, local->rightChild, local);
		calculateHeightAfterRemoval(local);
		return rval;
	}
	return false;
}

bool BST::remove(int num) {
	//cout << "in remove" << endl;
	bool removed = removeHelper(num, root, root);
	return removed;
}

void BST::calculateHeight(Node *ptr) {
	if(ptr == NULL) {
		return;
	}
	int max = 0;
	if(getHeight(ptr->leftChild) > max) {
		max = getHeight(ptr->leftChild);
	}else if(getHeight(ptr->rightChild) > max) {
		max = getHeight(ptr->rightChild);
	}
	ptr->setHeight(max + 1);

	//cout << "height calculated for " << ptr->data << " is: " << ptr->getHeight() << endl;
}

int BST::getHeight(Node *ptr){
	if(ptr == NULL) {
		return 0;
	} else {
		return ptr->getHeight();
	}
}

void BST::clearHelper(Node * local, Node * prev) {
	if(local != NULL) {
		clearHelper(local->leftChild, prev);
		clearHelper(local->rightChild, prev);
		//cout << "deleting: " << local->data << endl;
		delete local;
	}
}

void BST::clear() {
	if(root != NULL) {
		Node *local = root;
		Node *previous = root;
		clearHelper(local, previous);
		root = NULL;
	} else {
		//cout << "Already cleared" << endl;
	}
}
