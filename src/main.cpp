// Copyright 2021 NNTU-CS
#include <iostream>
#include "bst.h"

void MakeTree(BST<std::string>& tree, const char* filename);
void PrintFreq(BST<std::string>& tree);

int main() {
  BST<std::string> word_tree;

  MakeTree(word_tree, "src/war_peace.txt");

  std::cout << "Глубина дерева: " << word_tree.Depth() << std::endl;

  PrintFreq(word_tree);

  return 0;
}







