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

bool BST::traverse(Node *& local, Node *& prev, int num) {
	//cout << "in traverse" << endl;
	if (root != NULL) {
		if(local != NULL && local->data == num) {
			//cout << "data found in tree. don't add" << endl;
			return true;
		} else if(local != NULL && local->data > num){
			//cout << "data is smaller than localRoot" << endl;
			//cout << "current localRoot is not the end. recurse" << endl;
			prev = local;
			local = local->leftChild;
			return traverse(local, prev, num);
		} else if (local != NULL && local->data < num){
			//cout << "data is larger than local Root" << endl;
			//cout << "courrent localRoot is not the end. recurse" << endl;
			prev = local;
			local = local->rightChild;
			return traverse(local, prev, num);
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
		//cout << "root is: " << root->data << endl;
	} else {
		//cout << "creating a localRoot" << endl;
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
	bool inTree = traverse(localRoot, previous, num);
	if(!inTree) {
		return true;
	} else {
		return false;
	} 
}

void BST::findRightMost(Node *& ptr, Node *& prev) {
	if (ptr->rightChild != NULL) {
		prev = ptr;
		ptr = ptr->rightChild;
		findRightMost(ptr, prev);
	} else {
		//cout << "returning these values..." << endl;
		//cout << "right most node is " << ptr->data << endl;
		//cout << " prev node is " << prev->data << endl;
	}
} 

bool BST::find(Node *& local, Node *& prev, int num) {
	//cout << "finding..." << endl;
	if(local != NULL && local->data == num) {
		//cout << "found; local are previous roots are set" << endl;
		return true;
	} else {
		if(local != NULL && num < local->data) {
			//cout << "data is less than local root and local root has left child... recurse" << endl;
			prev = local;
			local = local->leftChild;
			return find(local, prev, num);
		} else if(local != NULL && num > local->data){
			//cout << "data is greater than localRoot and localRoot has rightChild... recurse" << endl;
			prev = local;
			local = local->rightChild;
			return find(local, prev, num);
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

/* 
rearranges the data to the right of a localRoot that was removed which had two children. 
*/
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
		if(/*local->parent*/prev != original) {
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
