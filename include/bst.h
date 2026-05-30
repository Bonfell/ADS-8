// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_

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

  int depth(Node* node) const {
    if (node == nullptr) return -1;
    return 1 + std::max(depth(node->left), depth(node->right));
  }

  bool search(Node* node, const T& value) const {
    while (node) {
      if (value < node->key) node = node->left;
      else if (value > node->key) node = node->right;
      else return true;
    }
    return false;
  }

  int getFrequency(Node* node, const T& value) const {
    while (node) {
      if (value < node->key) node = node->left;
      else if (value > node->key) node = node->right;
      else return node->count;
    }
    return 0;
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

#endif  // INCLUDE_BST_H_
