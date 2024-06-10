# Binary Tree and Binary Search Tree Implementation

This repository contains the implementation of a generic Binary Tree and a Binary Search Tree (BST) in C++. The Binary Tree class provides the basic functionality for a binary tree, while the BST class extends it with operations specific to a binary search tree.

## Table of Contents
- [Overview](#overview)
- [BinaryTree Class](#binarytree-class)
  - [Public Methods](#public-methods)
  - [Protected Methods](#protected-methods)
  - [Private Methods](#private-methods)
- [BST Class](#bst-class)
  - [Public Methods](#public-methods-1)
  - [Private Methods](#private-methods-1)
- [Usage](#usage)
- [License](#license)

## Overview
The project consists of two main classes:
1. **BinaryTree**: A generic binary tree class with basic tree traversal methods and utility functions.
2. **BST**: A binary search tree class that extends the BinaryTree class with insertion, search, and deletion functionalities.

## BinaryTree Class
The `BinaryTree` class is a template class that defines a binary tree structure and provides several methods for tree operations.

### Public Methods
- **BinaryTree()**: Constructor to initialize the tree.
- **~BinaryTree()**: Destructor to destroy the tree and free memory.
- **void inorder()**: Performs in-order traversal of the tree.
- **void postorder()**: Performs post-order traversal of the tree.
- **void preorder()**: Performs pre-order traversal of the tree.
- **int treeheight()**: Returns the height of the tree.
- **int count()**: Returns the number of nodes in the tree.
- **int leavescount()**: Returns the number of leaves in the tree.

### Protected Methods
- **Node\<T\>* root**: Root node of the tree.

### Private Methods
- **void destroy(Node\<T\>*& p)**: Recursively destroys the tree.
- **void inorderT(Node\<T\>* p)**: Helper function for in-order traversal.
- **void preorderT(Node\<T\>* p)**: Helper function for pre-order traversal.
- **void postorderT(Node\<T\>* p)**: Helper function for post-order traversal.
- **int height(Node\<T\>* p)**: Helper function to calculate the height of the tree.
- **int max(int a, int b)**: Helper function to return the maximum of two integers.
- **int nodecount(Node\<T\>* p)**: Helper function to count the nodes in the tree.
- **int leavescount(Node\<T\>* p)**: Helper function to count the leaves in the tree.

## BST Class
The `BST` class is a template class that extends the `BinaryTree` class to implement a binary search tree.

### Public Methods
- **void insert(T& item)**: Inserts a new item into the BST.
- **Node\<T\>* search(T& item)**: Searches for an item in the BST and returns the corresponding node.
- **void deleteNode(T& item)**: Deletes a node with the specified item from the BST.

### Private Methods
- **void deletefromTree(Node\<T\>*& p)**: Helper function to delete a node from the BST.

## Usage
To use the `BinaryTree` and `BST` classes in your project, include the header files and create instances of these classes as needed.

```cpp
#include "BinaryTree.h"
#include "BST.h"

int main() {
    BST<int> tree;
    int value = 5;
    tree.insert(value);
    
    Node<int>* result = tree.search(value);
    if (result != nullptr) {
        cout << "Found: " << result->info << endl;
    } else {
        cout << "Not Found" << endl;
    }
    
    tree.deleteNode(value);
    return 0;
}
