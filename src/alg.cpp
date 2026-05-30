// Copyright 2021 NNTU-CS
#include "../include/bst.h"
#include <cctype>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

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
  if (tree.isEmpty()) return;
  std::vector<std::pair<std::string, int>> elements = tree.getSortedByKey();
  std::sort(elements.begin(), elements.end(),
    [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
      return a.second > b.second;
    });
  std::ofstream outFile("result/freq.txt");
  if (!outFile) return;
  for (const auto& pair : elements) {
    outFile << pair.first << " " << pair.second << std::endl;
  }
  outFile.close();
}
