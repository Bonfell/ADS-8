// Copyright 2021 NNTU-CS
#include <iostream>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> wordTree;

    makeTree(wordTree, "src/war_peace.txt");

    std::cout << "Глубина дерева: " << wordTree.depth() << std::endl;

    auto freqData = wordTree.getSortedByFreq();
    std::cout << "Топ-5 слов:" << std::endl;
    for (size_t i = 0; i < 5 && i < freqData.size(); ++i)
        std::cout << freqData[i].first << ": " << freqData[i].second << std::endl;

    printFreq(wordTree);

    return 0;
}






