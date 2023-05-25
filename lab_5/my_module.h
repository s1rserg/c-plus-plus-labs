#ifndef LAB_5_PR_MY_MODULE_H
#define LAB_5_PR_MY_MODULE_H

#include <iostream>
#include <limits>

using namespace std;

template<typename T>
class Multiset {
private:
    struct Node {
        T data;
        Node *parent;
        Node *left;
        Node *right;
        int count;
        bool isRed;

        Node(T value, Node *p = nullptr, Node *l = nullptr, Node *r = nullptr, int c = 1, bool red = true)
                : data(value), parent(p), left(l), right(r), count(c), isRed(red) {}
    };

    Node *root;
    int size;

public:
    Multiset() : root(nullptr), size(0) {}

    ~Multiset();

    Multiset(const Multiset &other) : root(nullptr), size(0) {
        copyTree(other.root);
    }

    Multiset &operator=(const Multiset &other);

    void insert(const T &element);

    bool isEmpty() const;

    Node *contains(const T &value) const;

    bool remove(const T &element);

    Multiset<T> intersect(const Multiset<T> &other) const;

    void clear();

    void outputSet() const;

    class Iterator {
        Node *current;

    public:
        Iterator(Node *node) : current(node) {}

        void begin();

        int count() const;

        bool end() const;

        const T &value() const;

        void next();
    };

    Iterator getIterator() const;

private:
    void copyTree(Node *node);

    void fixInsert(Node *newNode); // for insert

    void deleteNode(Node *node); // for remove

    void fixDelete(Node *node); // for remove

    void transplant(Node *u, Node *v); // for remove

    void rotateLeft(Node *node);

    void rotateRight(Node *node);

    Node *minimum(Node *node) const; // for remove

    void deleteTree(Node *node);

};

template<typename T>
void handleMenuOptions(Multiset<T> &set);

#include "my_module.tpp"

#endif //LAB_5_PR_MY_MODULE_H
