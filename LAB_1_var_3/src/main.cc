#include <iostream>
#include <vector>
#include "../include/Tree.h"
#include "../include/Random.h"
#include "../include/Time.h"

int main() {
    Tree tree;
    tree.insert(3);
    tree.insert(2);
    tree.insert(2);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(8);

    std::cout << "Tree elements: ";
    tree.print();

    std::cout << "Is 3 in the tree? " << (tree.contains(3) ? "Yes" : "No") << std::endl;
    std::cout << "Is 10 in the tree? " << (tree.contains(10) ? "Yes" : "No") << std::endl;

    tree.erase(3);
    std::cout << "After erasing 3: ";
    tree.print();

    // Генерация случайного дерева и вектора
    Tree randomTree = generate_random_tree(10);
    std::vector<int> randomVector;
    std::vector<int> randomVectorInt = generate_random_vector(10);

    // Поиск дубликатов в векторе
    std::vector<int> duplicates = findDuplicates({ 3, 2, 2, 4, 5, 7, 9, 0, 1, 8 });
    std::cout << "Duplicates in the vector: ";
    for (int num : duplicates) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Измерение времени операций
    Time timer;
    timer.fillContainerAverageTime(tree, 1000);
    timer.fillContainerAverageTime(tree, 10000);
    timer.fillContainerAverageTime(tree, 100000);
    timer.fillVectorAverageTime(randomVectorInt, 1000);
    timer.fillVectorAverageTime(randomVectorInt, 10000);
    timer.fillVectorAverageTime(randomVectorInt, 100000);
    timer.searchAverageTime(tree, 1000);
    timer.searchAverageTime(tree, 10000);
    timer.searchAverageTime(tree, 100000);
    timer.addAndRemoveAverageTime(tree, 1000);
    timer.addAndRemoveAverageTime(tree, 10000);
    timer.addAndRemoveAverageTime(tree, 100000);
    timer.searchVectorAverageTime(randomVectorInt, 1000);
    timer.searchVectorAverageTime(randomVectorInt, 10000);
    timer.searchVectorAverageTime(randomVectorInt, 100000);
    timer.addAndRemoveVectorAverageTime(randomVectorInt, 1000);
    timer.addAndRemoveVectorAverageTime(randomVectorInt, 10000);
    timer.addAndRemoveVectorAverageTime(randomVectorInt, 100000);

    return 0;
}