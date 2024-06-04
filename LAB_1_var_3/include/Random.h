#ifndef TREE_INCLUDE_RAND_H
#define TREE_INCLUDE_RAND_H

#pragma once
#include "../include/Tree.h"
#include <vector>
#include <iostream>

size_t lcg();

size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

Tree generate_random_tree(size_t size) {
    Tree tree;
    for (size_t i = 0; i < size; ++i) {
        tree.insert(lcg());
    }
    return tree;
}

std::vector<int> generate_random_vector(size_t size) {
    std::vector<int> vec;
    for (size_t i = 0; i < size; ++i) {
        vec.push_back(lcg());
    }
    return vec;
}

std::vector<int> findDuplicates(const std::vector<int>& v) {
    Tree tree;
    std::vector<int> duplicates;

    for (int num : v) {
        if (!tree.insert(num)) {
            duplicates.push_back(num);
        }
    }

    return duplicates;
}

#endif