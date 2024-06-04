#include <iostream>
#include <vector>
#include <chrono>
#include "../include/Tree.h"
#include "../include/Random.h"

class Time {
public:
    void fillContainerAverageTime(Tree& container, int numElements) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 100; ++i) {
            // Заполнение контейнера уникальными случайными числами
            for (int j = 0; j < numElements; ++j) {
                container.insert(lcg());
            }
            container = Tree(); // Очистка контейнера
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Average fill time for " << numElements << " elements: " << elapsed_seconds.count() / 100 << " seconds\n";
    }


    void fillVectorAverageTime(std::vector<int>& vec, int numElements) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 100; ++i) {
            // Заполнение вектора случайными числами
            for (int j = 0; j < numElements; ++j) {
                vec.push_back(lcg());
            }
            vec.clear(); // Очистка вектора
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Average fill time for " << numElements << " elements using vector: " << elapsed_seconds.count() / 100 << " seconds\n";
    }

    void searchAverageTime(Tree& container, int numElements) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; ++i) {
            // Заполнение контейнера уникальными случайными числами
            for (int j = 0; j < numElements; ++j) {
                container.insert(lcg());
            }

            // Поиск случайного числа в заполненном контейнере
            for (int j = 0; j < 1000; ++j) {
                container.contains(lcg());
            }

            container = Tree(); // Очистка контейнера
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Average search time for " << numElements << " elements: " << elapsed_seconds.count() / 1000 << " seconds\n";
    }

    void addAndRemoveAverageTime(Tree& container, int numElements) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; ++i) {
            // Заполнение контейнера уникальными случайными числами
            for (int j = 0; j < numElements; ++j) {
                container.insert(lcg());
            }

            // Добавление и удаление случайного числа в заполненном контейнере
            for (int j = 0; j < 1000; ++j) {
                int key = lcg();
                container.insert(key);
                container.erase(key);
            }

            container = Tree(); // Очистка контейнера
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Average add and remove time for " << numElements << " elements: " << elapsed_seconds.count() / 1000 << " seconds\n";
    }

    void searchVectorAverageTime(std::vector<int>& vec, int numElements) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; ++i) {
            // Заполнение вектора случайными числами
            for (int j = 0; j < numElements; ++j) {
                vec.push_back(lcg());
            }

            // Поиск случайного числа в заполненном векторе
            for (int j = 0; j < 1000; ++j) {
                int key = lcg();
                auto result = std::find(vec.begin(), vec.end(), key);
                if (result != vec.end()) {
                    // Используйте результат поиска, если необходимо
                }
            }

            vec.clear(); // Очистка вектора
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Average search time for " << numElements << " elements in vector: " << elapsed_seconds.count() / 1000 << " seconds\n";
    }

    void addAndRemoveVectorAverageTime(std::vector<int>& vec, int numElements) {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1000; ++i) {
            // Заполнение вектора случайными числами
            for (int j = 0; j < numElements; ++j) {
                vec.push_back(lcg());
            }

            // Добавление и удаление случайного числа в заполненном векторе
            for (int j = 0; j < 1000; ++j) {
                int key = lcg();
                vec.push_back(key);
                vec.erase(std::find(vec.begin(), vec.end(), key));
            }

            vec.clear(); // Очистка вектора
        }
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed_seconds = end - start;
        std::cout << "Average add and remove time for " << numElements << " elements in vector: " << elapsed_seconds.count() / 1000 << " seconds\n";
    }
};