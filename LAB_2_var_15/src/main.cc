#include <iostream>
#include "../include/Hash.h"

int main() {
    const int numberOfPeople = 20;
    const int experiments = 100;

    HashTable<int, int> hashTable(25);
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < experiments; ++i) {
        for (int j = 0; j < numberOfPeople; ++j) {
            int key = rand() % numberOfPeople;
            int value = rand() % 100;
            hashTable.insert(key, value);
        }
    }

    for (int size = 25; size <= 475; size += 50) {
        HashTable<int, int> tempTable(size);
        int collisions = 0;

        for (int i = 0; i < experiments; ++i) {
            for (int j = 0; j < numberOfPeople; ++j) {
                int key = rand() % size; 
                if (tempTable.contains(key)) {
                    collisions++;
                }
                tempTable.insert(key, rand() % 100);
            }
        }


        std::cout << "Size: " << size << ", Collisions: " << collisions << std::endl;
        if (collisions < experiments / 2) {
            std::cout << "Size at which collision probability is less than 50%: " << size << std::endl;
            break;
        }
    }

    return 0;
}