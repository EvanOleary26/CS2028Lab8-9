#ifndef __BINARYTREE__H
#define __BINARYTREE__H

#include "Node.h"
 

template <class T>
class BinaryTree {
    private:
        Node<T> *root;
        int size;

        void rotateLeft(Node<T> *parent, Node<T> *child);
        void rotateRight(Node<T> *parent, Node<T> *child);
        void rotateLR(Node<T> *parent, Node<T> *child);
        void rotateRL(Node<T> *parent, Node<T> *child);
    public:
        //Constructor
        BinaryTree() : root(nullptr), size(0) {}

        //Deconstructor
        ~BinaryTree();

        //Functions
        void Insert(T inVal, Node<T> *parent);
        T *Find(T target, Node<T> *parent);
        int returnSize() { return size; }
        T* GetAllAscending();       //Returns a pointer to an array
        T* GetAllDescending();      //Returns a pointer to an array
        void EmptyTree();
        T Remove(T inVal, Node<T> *parent);
};










#endif