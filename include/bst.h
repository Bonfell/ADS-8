// Copyright 2021 NNTU-CS
#ifndef BST_H
#define BST_H

#include <algorithm>
#include <utility>
#include <vector>

template <typename T>
class BST {
 private:
  struct Node {
    T key;
    int count;
    Node* left;
    Node* right;
    explicit Node(const T& value) : key(value), count(1), left(nullptr), right(nullptr) {}
  };
  Node* root;

 public:
  BST() : root(nullptr) {}
  ~BST() { clear(root); }

  void insert(const T& value) {
    if (root == nullptr) {
      root = new Node(value);
      return;
    }
    Node* cur = root;
    while (true) {
      if (value < cur->key) {
        if (cur->left == nullptr) {
          cur->left = new Node(value);
          return;
        }
        cur = cur->left;
      } else if (value > cur->key) {
        if (cur->right == nullptr) {
          cur->right = new Node(value);
          return;
        }
        cur = cur->right;
      } else {
        cur->count++;
        return;
      }
    }
  }

  int depth() const {
    return depth(root);
  }

  bool search(const T& value) const {
    Node* cur = root;
    while (cur) {
      if (value < cur->key) cur = cur->left;
      else if (value > cur->key) cur = cur->right;
      else return true;
    }
    return false;
  }

  int getFrequency(const T& value) const {
    Node* cur = root;
    while (cur) {
      if (value < cur->key) cur = cur->left;
      else if (value > cur->key) cur = cur->right;
      else return cur->count;
    }
    return 0;
  }

  std::vector<std::pair<T, int>> getSortedByKey() const {
    std::vector<std::pair<T, int>> elements;
    inorder(root, elements);
    return elements;
  }

  bool isEmpty() const { return root == nullptr; }

 private:
  int depth(Node* node) const {
    if (node == nullptr) return -1;
    return 1 + std::max(depth(node->left), depth(node->right));
  }

  void inorder(Node* node, std::vector<std::pair<T, int>>& elements) const {
    if (node == nullptr) return;
    inorder(node->left, elements);
    elements.emplace_back(node->key, node->count);
    inorder(node->right, elements);
  }

  void clear(Node* node) {
    if (node == nullptr) return;
    clear(node->left);
    clear(node->right);
    delete node;
  }
};

#endif
