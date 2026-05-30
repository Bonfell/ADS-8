// Copyright 2021 NNTU-CS
#include "../include/bst.h"
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
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
    if (std::isalpha(static_cast<unsigned char>(ch))) {
      word += std::tolower(static_cast<unsigned char>(ch));
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
  auto elements = tree.getSortedByKey();
  std::sort(elements.begin(), elements.end(),
            [](const auto& a, const auto& b) { return a.second > b.second; });

  std::cout << "=== Frequency table (first 20) ===" << std::endl;
  for (size_t i = 0; i < std::min(elements.size(), size_t(20)); ++i) {
    std::cout << elements[i].first << " : " << elements[i].second << std::endl;
  }

  std::ofstream out("result/freq.txt");
  if (!out) return;
  for (const auto& p : elements) {
    out << p.first << " " << p.second << "\n";
  }
  out.close();
}












