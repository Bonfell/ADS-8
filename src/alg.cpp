// Copyright 2021 NNTU-CS
#include "../include/bst.h"
#include <fstream>
#include <iostream>
#include <cctype>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>

void makeTree(BST<std::string>& tree, const char* filename) {
    std::ifstream file(filename);
    
    if (!file) {
        std::cout << "File error! Could not open " << filename << std::endl;
        return;
    }
    
    std::string word;
    char ch;
    
    while (file.get(ch)) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            word += tolower(ch);
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
    if (tree.isEmpty()) {
        std::cout << "Tree is empty!" << std::endl;
        return;
    }
    
    std::vector<std::pair<std::string, int>> elements = tree.getSortedByKey();
    
    std::sort(elements.begin(), elements.end(), 
        [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            return a.second > b.second;
        });
    
    std::ofstream outFile("result/freq.txt");
    
    if (!outFile) {
        std::cout << "Error opening result/freq.txt for writing!" << std::endl;
        return;
    }
    
    std::cout << "\n=== Frequency Analysis Results ===" << std::endl;
    std::cout << "Total unique words: " << elements.size() << std::endl;
    std::cout << "================================\n" << std::endl;
    
    outFile << "Word Frequency Analysis\n";
    outFile << "=====================\n\n";
    outFile << "Word\t\t\tFrequency\n";
    outFile << "----\t\t\t---------\n\n";
    
    int count = 0;
    for (const auto& pair : elements) {
        std::cout << pair.first << " : " << pair.second << std::endl;
        outFile << pair.first << "\t\t\t" << pair.second << std::endl;
        count++;
        if (count >= 50 && count < elements.size()) {
            std::cout << "... and " << (elements.size() - 50) << " more words" << std::endl;
            for (; count < elements.size(); count++) {
                outFile << elements[count].first << "\t\t\t" << elements[count].second << std::endl;
            }
            break;
        }
    }
    
    outFile.close();
    
    std::cout << "\nResults saved to result/freq.txt" << std::endl;
}
