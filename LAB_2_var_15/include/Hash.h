#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename K, typename T>
class HashTable {
private:
    struct Node {
        K key;
        T value;
        bool filled;

        Node() : key(), value(), filled(false) {}
    };

    std::vector<Node> table;
    size_t size;

    size_t hash(const K& key) const {
        // Реализация хеш-функции методом многократного сдвига
        // (The multiply-shift method)
        size_t ka = std::hash<K>{}(key);
        size_t w = sizeof(size_t) * 8;
        size_t l = 8;
        return ((ka * 2654435761u) % (1ull << w)) >> (w - l);
    }

    size_t findIndex(const K& key) const {
        size_t index = hash(key) % size;
        size_t initialIndex = index;
        while (table[index].filled && table[index].key != key) {
            index = (index + 1) % size;
            if (index == initialIndex) {
                throw std::runtime_error("Table is full");
            }
        }
        return index;
    }

public:
    HashTable(size_t initialSize) : size(initialSize), table(initialSize) {}

    HashTable(const HashTable& other) : size(other.size), table(other.table) {}

    ~HashTable() {}

    HashTable& operator=(const HashTable& other) {
        if (this != &other) {
            size = other.size;
            table = other.table;
        }
        return *this;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            if (table[i].filled) {
                std::cout << "Key: " << table[i].key << ", Value: " << table[i].value << std::endl;
            }
            else {
                std::cout << "Empty" << std::endl;
            }
        }
    }

    void insert(const K& key, const T& value) {
        size_t index = findIndex(key);
        table[index].key = key;
        table[index].value = value;
        table[index].filled = true;
    }

    void insert_or_assign(const K& key, const T& value) {
        size_t index = findIndex(key);
        if (table[index].filled && table[index].key == key) {
            table[index].value = value; // Если ключ уже существует, заменяем значение
        }
        else {
            table[index].key = key;
            table[index].value = value;
            table[index].filled = true;
        }
    }

    bool contains(const K& key) const {
        size_t index = findIndex(key);
        return table[index].filled;
    }

    T* search(const K& key) {
        size_t index = findIndex(key);
        if (table[index].filled) {
            return &table[index].value;
        }
        else {
            return nullptr;
        }
    }

    bool erase(const K& key) {
        size_t index = findIndex(key);
        if (table[index].filled) {
            table[index].filled = false;
            return true;
        }
        return false;
    }

    int count(const K& key) {
        size_t count = 0;
        for (size_t i = 0; i < size; ++i) {
            if (table[i].filled && table[i].key == key) {
                count++;
            }
        }
        return count;
    }
};

#endif