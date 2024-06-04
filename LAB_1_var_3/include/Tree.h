#pragma once
#include <iostream>

using namespace std;

class Tree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        Node(int k) : key(k), left(nullptr), right(nullptr) {}

    };

    Node* root;

    void destroyTree(Node* current) {
        if (current != nullptr) {
            destroyTree(current->left);
            destroyTree(current->right);
            delete current;
        }
    }

    void copyHelper(Node*& current, Node* other) {
        if (other == nullptr) {
            current = nullptr;
        }
        else {
            current = new Node(other->key);
            copyHelper(current->left, other->left);
            copyHelper(current->right, other->right);
        }
    }

    void printHelper(Node* current) {
        if (current != nullptr) {
            printHelper(current->left);
            cout << current->key << " ";
            printHelper(current->right);
        }
    }

    bool insertHelper(Node*& current, int key) {
        if (current == nullptr) {
            current = new Node(key);
            return true;
        }

        if (key < current->key) {
            return insertHelper(current->left, key);
        }
        else if (key > current->key) {
            return insertHelper(current->right, key);
        }
        else {
            return false; // элемент уже существует
        }
    }

    bool containsHelper(Node* current, int key) {
        if (current == nullptr) {
            return false;
        }

        if (key < current->key) {
            return containsHelper(current->left, key);
        }
        else if (key > current->key) {
            return containsHelper(current->right, key);
        }
        else {
            return true;
        }
    }

    bool eraseHelper(Node*& current, int key) {
        if (current == nullptr) {
            return false; // элемент не найден
        }

        if (key < current->key) {
            return eraseHelper(current->left, key);
        }
        else if (key > current->key) {
            return eraseHelper(current->right, key);
        }
        else {
            if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                current = temp;
            }
            else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                current = temp;
            }
            else {
                Node* temp = current->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                current->key = temp->key;
                eraseHelper(current->right, temp->key);
            }
            return true;
        }
    }

public:
    Tree() : root(nullptr) {}

    Tree(const Tree& other) : root(nullptr) {
        copyHelper(root, other.root);
    }

    ~Tree() {
        destroyTree(root);
    }

    Tree& operator=(const Tree& other) {
        if (this != &other) {
            destroyTree(root);
            copyHelper(root, other.root);
        }
        return *this;
    }

    void print() {
        printHelper(root);
        cout << std::endl;
    }

    bool insert(int key) {
        return insertHelper(root, key);
    }

    bool contains(int key) {
        return containsHelper(root, key);
    }

    bool erase(int key) {
        return eraseHelper(root, key);
    }
};