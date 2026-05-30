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
    explicit Node(const T& value)
        : key(value), count(1), left(nullptr), right(nullptr) {}
  };
  Node* root;

  Node* insert(Node* node, const T& value) {
    if (node == nullptr) return new Node(value);
    if (value < node->key)
      node->left = insert(node->left, value);
    else if (value > node->key)
      node->right = insert(node->right, value);
    else
      node->count++;
    return node;
  }

  int depth(Node* node) const {
    if (node == nullptr) return -1;
    return 1 + std::max(depth(node->left), depth(node->right));
  }

  bool search(Node* node, const T& value) const {
    if (node == nullptr) return false;
    if (value < node->key) return search(node->left, value);
    if (value > node->key) return search(node->right, value);
    return true;
  }

  int getFrequency(Node* node, const T& value) const {
    if (node == nullptr) return 0;
    if (value < node->key) return getFrequency(node->left, value);
    if (value > node->key) return getFrequency(node->right, value);
    return node->count;
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

 public:
  BST() : root(nullptr) {}
  ~BST() { clear(root); }

  void insert(const T& value) { root = insert(root, value); }
  int depth() const { return depth(root); }
  bool search(const T& value) const { return search(root, value); }
  int getFrequency(const T& value) const { return getFrequency(root, value); }
  std::vector<std::pair<T, int>> getSortedByKey() const {
    std::vector<std::pair<T, int>> elements;
    inorder(root, elements);
    return elements;
  }
  bool isEmpty() const { return root == nullptr; }
};

#endif








