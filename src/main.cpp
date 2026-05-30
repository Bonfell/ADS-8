// Copyright 2021 NNTU-CS
#include "../include/bst.h"

#include <chrono>
#include <iostream>
#include <string>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> tree;

  std::cout << "Starting frequency analysis..." << std::endl;

  makeTree(tree, "src/war_peace.txt");

  if (!tree.isEmpty()) {
    printFreq(tree);
  } else {
    std::cout << "Failed to build tree. File may not exist or is empty." << std::endl;
  }

  return 0;
}
