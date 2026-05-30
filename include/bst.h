// Copyright 2021 NNTU-CS
#ifndef BST_H
#define BST_H

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

        Node(const T& k) : key(k), count(1), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const T& key) {
        if (!node) {
            return new Node(key);
        }

        if (key == node->key) {
            node->count++;
            return node;
        } else if (key < node->key) {
            node->left = insert(node->left, key);
        } else {
            node->right = insert(node->right, key);
        }
        return node;
    }

    Node* search(Node* node, const T& key) const {
        if (!node || node->key == key) return node;
        if (key < node->key) return search(node->left, key);
        return search(node->right, key);
    }

    int depth(Node* node) const {
        if (!node) return -1;
        return 1 + std::max(depth(node->left), depth(node->right));
    }

    void collectNodes(Node* node, std::vector<Node*>& nodes) const {
        if (!node) return;
        collectNodes(node->left, nodes);
        nodes.push_back(node);
        collectNodes(node->right, nodes);
    }

public:
    BST() : root(nullptr) {}

    ~BST() {}

    void insert(const T& key) {
        root = insert(root, key);
    }

    bool search(const T& key) const {
        return search(root, key) != nullptr;
    }

    int depth() const {
        return depth(root);
    }

    std::vector<std::pair<T, int>> getSortedByFreq() const {
        std::vector<Node*> nodes;
        collectNodes(root, nodes);

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
};

#endif





