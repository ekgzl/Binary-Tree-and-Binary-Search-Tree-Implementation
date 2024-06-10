//
// Created by enes4 on 10.06.2024.
//

#ifndef BINARY_BST_H
#define BINARY_BST_H

#include <iostream>
#include "BinaryTree.h"

using namespace std;

template <class T>
class BST {
public:
    void insert(T&);
    Node<T>* search(T&);
    void deleteNode(T&);
private:
    void deletefromTree(Node<T> *&);
};

template<class T>
void BST<T>::insert(T& item) {
    Node<T> *p = this->root;
    Node<T> *q = nullptr;
    Node<T> *newNode = new Node<T>;
    newNode->info = item;
    newNode->llink = nullptr;
    newNode->rlink = nullptr;

    while (p != nullptr) {
        q = p;
        if (item < p->info)
            p = p->llink;
        else
            p = p->rlink;
    }

    if (q == nullptr)
        this -> root = newNode;
    else if (item < q->info)
        q->llink = newNode;
    else
        q->rlink = newNode;
}

template<class T>
Node<T>* BST<T>::search(T& item) {
    Node<T> *p = this->root;
    while (p != nullptr) {
        if (p->info == item)
            return p;
        else if (item < p->info)
            p = p->llink;
        else
            p = p->rlink;
    }
    return nullptr;
}

template<class T>
void BST<T>::deletefromTree(Node<T> *& p) {
    Node<T> *delPtr;
    Node<T> *replacement;

    if (p == nullptr) {
        cout << "Item not found!" << endl;
    } else if (p->llink == nullptr) {
        delPtr = p;
        p = p->rlink;
        delete delPtr;
    } else if (p->rlink == nullptr) {
        delPtr = p;
        p = p->llink;
        delete delPtr;
    } else {
        replacement = p->llink;
        while (replacement->rlink != nullptr)
            replacement = replacement->rlink;
        p->info = replacement->info;
        deletefromTree(p->llink);
    }
}

template<class T>
void BST<T>::deleteNode(T& item) {
    Node<T> *p = this->root;
    Node<T> *q = nullptr;
    while (p != nullptr && p->info != item) {
        q = p;
        if (item < p->info)
            p = p->llink;
        else
            p = p->rlink;
    }

    if (p == nullptr) {
        cout << "Item not found!" << endl;
        return;
    }

    if (p->llink == nullptr || p->rlink == nullptr)
        deletefromTree(p);
    else {
        Node<T> *temp = p->llink;
        while (temp->rlink != nullptr)
            temp = temp->rlink;
        p->info = temp->info;
        deletefromTree(p->llink);
    }
}

#endif //BINARY_BST_H
