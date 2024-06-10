//
// Created by enes4 on 10.06.2024.
//

#ifndef BINARY_BINARYTREE_H
#define BINARY_BINARYTREE_H


#include <iostream>

using namespace std;

template<class T>
struct Node{
    T info;
    Node<T> *llink,*rlink;
};

template<class T>
class BinaryTree {
protected:
    Node<T> *root;
private:
    void destroy(Node<T>*&);
    void inorderT(Node<T>*);
    void preorderT(Node<T>*);
    void postorderT(Node<T>*);
    int height(Node<T>*);
    int max(int,int);
    int nodecount(Node<T>*);
    int leavescount(Node<T>*);
public:
    BinaryTree();
    ~BinaryTree();
    void inorder();
    void postorder();
    void preorder();
    int treeheight();
    int count();
    int leavescount();
};


template<class T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
    destroy(root);
}

template<class T>
void BinaryTree<T>::destroy(Node<T>*& p) {
    if (p != nullptr) {
        destroy(p->llink);
        destroy(p->rlink);
        delete p;
        p = nullptr;
    }
}

template<class T>
void BinaryTree<T>::inorderT(Node<T>* p) {
    if (p != nullptr) {
        inorderT(p->llink);
        cout << p->info << " ";
        inorderT(p->rlink);
    }
}

template<class T>
void BinaryTree<T>::inorder() {
    inorderT(root);
}



#endif //BINARY_BINARYTREE_H
