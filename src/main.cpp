// Copyright 2021 NNTU-CS
#include "bst.h"
#include <iostream>
#include <chrono>

void makeTree(BST<std::string>& tree, const char* filename);
void printFreq(BST<std::string>& tree);

int main() {
    BST<std::string> tree;
    
    std::cout << "Starting frequency analysis of 'War and Peace'..." << std::endl;
    std::cout << "Loading file: src/war_peace.txt" << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    makeTree(tree, "src/war_peace.txt");
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    if (!tree.isEmpty()) {
        std::cout << "Tree built successfully!" << std::endl;
        std::cout << "Tree depth: " << tree.depth() << std::endl;
        std::cout << "Time taken: " << duration.count() << " ms" << std::endl;
        
        std::cout << "\nTesting search functionality:" << std::endl;
        std::cout << "Search 'the': " << (tree.search("the") ? "Found" : "Not found") << std::endl;
        std::cout << "Search 'war': " << (tree.search("war") ? "Found" : "Not found") << std::endl;
        std::cout << "Search 'peace': " << (tree.search("peace") ? "Found" : "Not found") << std::endl;
        std::cout << "Search 'nonexistent': " << (tree.search("nonexistent") ? "Found" : "Not found") << std::endl;
        
        printFreq(tree);
    } else {
        std::cout << "Failed to build tree. File may not exist or is empty." << std::endl;
    }
    
    return 0;
}
