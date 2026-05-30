// Copyright 2021 NNTU-CS
#include <iostream>
#include "bst.h"

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> wordTree;

    makeTree(wordTree, "src/war_peace.txt");

    std::cout << "Глубина дерева: " << wordTree.depth() << std::endl;
    std::cout << "Поиск слова 'war': " << (wordTree.search("war") ? "Найдено" : "Не найдено") << std::endl;

    std::cout << "\nЧастотный анализ (топ слов):" << std::endl;
    printFreq(wordTree);

    return 0;
}




