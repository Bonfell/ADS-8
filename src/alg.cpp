// Copyright 2021 NNTU-CS
#include "bst.h"
#include <fstream>
#include <cctype>
#include <iostream>
#include <vector>

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Ошибка открытия файла: " << filename << std::endl;
        return;
    }

    std::string word;
    char ch;

    while (file.get(ch)) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            word += static_cast<char>(std::tolower(static_cast<unsigned char>(ch)));
        } else {
            if (!word.empty()) {
                tree.insert(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        tree.insert(word);
    }

    file.close();
}

void printFreq(BST<std::string>& tree) {
    auto sortedData = tree.getSortedByFreq();

    std::ofstream outFile("result/freq.txt");
    if (!outFile) {
        std::cerr << "Ошибка создания файла результата!" << std::endl;
        return;
    }

    for (const auto& item : sortedData) {
        std::cout << item.first << ": " << item.second << std::endl;
        outFile << item.first << ": " << item.second << std::endl;
    }

    outFile.close();
}




