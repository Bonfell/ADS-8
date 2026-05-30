// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>

template <typename T>
class BST {
private:
    struct Node {
        T key;
        int count;
        Node* left;
        Node* right;
        
        Node(const T& value) : key(value), count(1), left(nullptr), right(nullptr) {}
    };
    
    Node* root;
    
    void insert(Node*& node, const T& value) {
        if (node == nullptr) {
            node = new Node(value);
        } else if (value < node->key) {
            insert(node->left, value);
        } else if (value > node->key) {
            insert(node->right, value);
        } else {
            node->count++;
        }
    }
    
    int depth(Node* node) const {
        if (node == nullptr) return 0;
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return 1 + std::max(leftDepth, rightDepth);
    }
    
    bool search(Node* node, const T& value) const {
        if (node == nullptr) return false;
        if (value < node->key) return search(node->left, value);
        if (value > node->key) return search(node->right, value);
        return true;
    }
    
    void inorder(Node* node, std::vector<std::pair<T, int>>& elements) const {
        if (node == nullptr) return;
        inorder(node->left, elements);
        elements.push_back({node->key, node->count});
        inorder(node->right, elements);
    }
    
    void clear(Node* node) {
        if (node == nullptr) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }
    
public:
    BST() : root(nullptr) {}
    
    ~BST() {
        clear(root);
    }
    
    void insert(const T& value) {
        insert(root, value);
    }
    
    int depth() const {
        return depth(root);
    }
    
    bool search(const T& value) const {
        return search(root, value);
    }
    
    std::vector<std::pair<T, int>> getSortedByKey() const {
        std::vector<std::pair<T, int>> elements;
        inorder(root, elements);
        return elements;
    }
    
    bool isEmpty() const {
        return root == nullptr;
    }
};

#endif  // INCLUDE_BST_H_
