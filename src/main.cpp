// Copyright 2021 NNTU-CS
#include "../include/bst.h"
#include <iostream>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
  BST<std::string> tree;
  makeTree(tree, "src/war_peace.txt");
  if (!tree.isEmpty()) {
    std::cout << "Frequency of 'the' : " << tree.getFrequency("the") << std::endl;
    std::cout << "Frequency of 'and' : " << tree.getFrequency("and") << std::endl;
    std::cout << "Frequency of 'to'  : " << tree.getFrequency("to") << std::endl;
    printFreq(tree);
  }
  return 0;
}








