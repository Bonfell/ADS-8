// Copyright 2021 NNTU-CS
#include "bst.h"

#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void MakeTree(BST<std::string>& tree, const char* filename) {
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
        tree.Insert(word);
        word.clear();
      }
    }
  }
  if (!word.empty()) {
    tree.Insert(word);
  }

  file.close();
}

void PrintFreq(BST<std::string>& tree) {
  auto sorted_data = tree.GetSortedByFreq();

  std::ofstream out_file("result/freq.txt");
  if (!out_file) {
    std::cerr << "Ошибка создания файла результата!" << std::endl;
    return;
  }

  for (const auto& item : sorted_data) {
    std::cout << item.first << ": " << item.second << std::endl;
    out_file << item.first << ": " << item.second << std::endl;
  }

  out_file.close();
}









