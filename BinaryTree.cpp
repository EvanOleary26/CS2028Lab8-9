#include "BinaryTree.h"

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
        Node* newNode = new Node(inVal);
    }
    if (inVal < parent->data) { //add to left
        if (parent->left == nullptr) {
            parent->left = new Node(inVal);
        }
        else {
            recInsert(inVal, parent->left);
        }
    }
    else if (inVal > parent->data) { //add to right
        if (parent->right == nullptr) {
            parent->right = new Node(inVal);
        }
        else {
            recInsert(inVal, parent->right);
        }
    }
    else {
        //throw duplicate
    }
    size++;
}

template<class T>
T* BinaryTree<T>::Find(T target, Node<T> *parent) {
    if (parent == nullptr) {
        //throw not found
    }
    if (target == parent->data) {
        return parent->data;
    }
    if (target < parent->data) {
        return recFind(target, parent->left);
    }
    else {
        return recFind(target, parent->right);
    }
}

template<class T>
T* BinaryTree<T>::GetAllAscending() {   //Return a pointer to an array

}

template<class T>
T* BinaryTree<T>::GetAllDescending() {  //Return a pointer to an array

}

template<class T>
void BinaryTree<T>::EmptyTree() {

}

template<class T>
T BinaryTree<T>::Remove(T inVal, Node<T> *parent) {

}