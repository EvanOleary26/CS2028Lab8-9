#include "BinaryTree.h"

template<class T>
BinaryTree<T>::~BinaryTree() {
    //Recursively go through the tree removing everything from it
}

template<class T>
void BinaryTree<T>::rotateLeft(Node<T> *parent, Node<T> *child) {
    // turning "a->b->c" into "a<-b->c"
    // where parent is b (since its the new parent) and child is a (since it is the new child)
    //there is a case where the parent and child are not equal to each other. This is where we are trying to rotate the root
    if (root == child) {
        root = child->right;
        child->right = root->left;
        root->left = child;
    }
    if (parent->right == child) { //if new parent is to the right (like "a->b")
        parent->right = child->right; //"a->c"
        child->right = child->right->left;
        parent->right->left = child;
    }
    else { 
        parent->left = child->right;
        child->right = child->right->left;
        parent->left->left = child;
    }
}

template<class T>
void BinaryTree<T>::rotateRight(Node<T> *parent, Node<T> *child) {
    // turning "a<-b<-c" into "a<-b->c"
    // where parent is b (since its the new parent) and child is c (since it is the new child)
    if (root == child) {
        root = child->left;
        child->left = root->right;
        root->right = child;
    }
    if (parent->right == child) { //if new parent is to the left (like "a<-b")
        parent->right = child->left; //"a<-c"
        child->left = parent->right->right;
        parent->right->right = child;
    }
    else {
        parent->left = child->left;
        child->left = parent->left->right;	
        parent->left->right = child;
    }
}

template<class T>
void BinaryTree<T>::rotateLR(Node<T> *parent, Node<T> *child) {

}

template<class T>
void BinaryTree<T>::rotateRL(Node<T> *parent, Node<T> *child) {

}

template<class T>
void BinaryTree<T>::Insert(T inVal, Node<T> *parent) {  //Need to add Tree Balancing to this function
    if (root == nullptr) {
        Node<T>* newNode = new Node(inVal);
    }
    if (inVal < parent->data) { //add to left
        if (parent->left == nullptr) {
            parent->left = new Node(inVal);
        }
        else {
            Insert(inVal, parent->left);
        }
    }
    else if (inVal > parent->data) { //add to right
        if (parent->right == nullptr) {
            parent->right = new Node(inVal);
        }
        else {
            Insert(inVal, parent->right);
        }
    }
    else {
        //throw duplicate
    }
    size++;
}

template<class T>
T BinaryTree<T>::Find(T target, Node<T> *parent) {
    if (parent == nullptr) {
        throw Exception(0, "Cannot find item");
    }
    if (target == parent->data) {
        return parent->data;
    }
    if (target < parent->data) {
        return Find(target, parent->left);
    }
    else {
        return Find(target, parent->right);
    }
}

template<class T>
T* BinaryTree<T>::GetAllAscending() {   //Return a pointer to an array

}

template<class T>
T* BinaryTree<T>::GetAllDescending() {  //Return a pointer to an array

}

template<class T>
void BinaryTree<T>::EmptyTree() {   //Clear out the tree leaving a nullptr root node at the end

}

template<class T>
T BinaryTree<T>::Remove(T inVal) { //recursive remove – NEEDS inOrderPred FUNCTION TO WORK
	Node<T>* temp = root;
	T retVal;
	while (temp->data != inVal) {
		if (temp->data > inVal) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	if (temp->left == nullptr && temp->right == nullptr) { //leaf case
		retVal = temp->data;
		delete temp;
		return retVal;
	}
	else if (temp->left != nullptr && temp->right == nullptr) {//left child
		retVal = temp->data;
		Node<T>* replacement = temp->left;
		Remove(replacement->data);
		temp = replacement;
		return retVal;
	}
	else if (temp->left == nullptr && temp->right != nullptr) {//right child
		retVal = temp->data;
		Node<T>* replacement = temp->right;
		Remove(replacement->data);
		temp = replacement;
		return retVal;
	}
	else if (temp->left != nullptr && temp->right != nullptr) { //two children
		retVal = temp->data;
		Node<T>* replacement = inOrderPred(temp->data);
		Remove(replacement->data);
		return retVal;
	}
	else {
        throw Exception(0, "Item not found");
	}
}

template<class T>
Node<T>* BinaryTree<T>::inOrderPred(T inVal) {
	Node<T>* temp = root;
	while (temp->data != inVal) {
		if (temp->data > inVal) {
			temp = temp->left;
		}
		else {
			temp = temp->right;
		}
	}
	temp = temp->left; //gets left subtree
	while (temp->right != nullptr) { //finds greatest value in left subtree
		temp = temp->right;
	}
	return temp;
}

//Base Template
template class BinaryTree<Word>;