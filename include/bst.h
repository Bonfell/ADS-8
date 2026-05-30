// Copyright 2021 NNTU-CS
#ifndef BST_H_
#define BST_H_

#include <algorithm>
#include <string>
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

    explicit Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
  };

  Node* root_;

  Node* Insert(Node* node, const T& key);
  Node* Search(Node* node, const T& key) const;
  int Depth(Node* node) const;
  void CollectNodes(Node* node, std::vector<Node*>& nodes) const;

 public:
  BST() : root_(nullptr) {}
  ~BST();

  void Insert(const T& key);
  bool Search(const T& key) const;
  int Depth() const;
  std::vector<std::pair<T, int>> GetSortedByFreq() const;
};

template <typename T>
typename BST<T>::Node* BST<T>::Insert(Node* node, const T& key) {
  if (!node) {
    return new Node(key);
  }

  if (key == node->key) {
    node->count++;
    return node;
  } else if (key < node->key) {
    node->left = Insert(node->left, key);
  } else {
    node->right = Insert(node->right, key);
  }
  return node;
}

template <typename T>
typename BST<T>::Node* BST<T>::Search(Node* node, const T& key) const {
  if (!node || node->key == key) return node;
  if (key < node->key) return Search(node->left, key);
  return Search(node->right, key);
}

template <typename T>
int BST<T>::Depth(Node* node) const {
  if (!node) return -1;
  return 1 + std::max(Depth(node->left), Depth(node->right));
}

template <typename T>
void BST<T>::CollectNodes(Node* node, std::vector<Node*>& nodes) const {
  if (!node) return;
  CollectNodes(node->left, nodes);
  nodes.push_back(node);
  CollectNodes(node->right, nodes);
}

template <typename T>
BST<T>::~BST() {
}

template <typename T>
void BST<T>::Insert(const T& key) {
  root_ = Insert(root_, key);
}

template <typename T>
bool BST<T>::Search(const T& key) const {
  return Search(root_, key) != nullptr;
}

template <typename T>
int BST<T>::Depth() const {
  return Depth(root_);
}

template <typename T>
std::vector<std::pair<T, int>> BST<T>::GetSortedByFreq() const {
  std::vector<Node*> nodes;
  CollectNodes(root_, nodes);

  std::vector<std::pair<T, int>> result;
  for (auto* n : nodes) {
    result.emplace_back(n->key, n->count);
  }

  std::sort(result.begin(), result.end(),
      [](const std::pair<T, int>& a, const std::pair<T, int>& b) {
        return a.second > b.second;
      });
  return result;
}

#endif







