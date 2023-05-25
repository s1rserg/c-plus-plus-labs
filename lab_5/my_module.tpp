#include "my_module.h"

template<typename T>
Multiset<T>::~Multiset() {
    clear();
}

template<typename T>
Multiset<T> &Multiset<T>::operator=(const Multiset<T> &other) {
    if (this != &other) {
        clear();
        copyTree(other.root);
    }
    return *this;
}

template<typename T>
void Multiset<T>::insert(const T &element) {
    Node *newNode = new Node(element);
    Node *x = root;
    Node *y = nullptr;

    while (x != nullptr) {
        y = x;
        if (element < x->data) {
            x = x->left;
        } else if (element > x->data) {
            x = x->right;
        } else {
            x->count++;
            delete newNode;
            size++;
            return;
        }
    }

    newNode->parent = y;
    if (y == nullptr) {
        root = newNode;
    } else if (element < y->data) {
        y->left = newNode;
    } else {
        y->right = newNode;
    }
    fixInsert(newNode);
    size++;
}

template<typename T>
void Multiset<T>::fixInsert(Node *newNode) {
    while (newNode != root && newNode->parent->isRed) {
        if (newNode->parent == newNode->parent->parent->left) {
            Node *uncle = newNode->parent->parent->right;
            if (uncle != nullptr && uncle->isRed) {
                newNode->parent->isRed = false;
                uncle->isRed = false;
                newNode->parent->parent->isRed = true;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    rotateLeft(newNode);
                }
                newNode->parent->isRed = false;
                newNode->parent->parent->isRed = true;
                rotateRight(newNode->parent->parent);
            }
        } else {
            Node *uncle = newNode->parent->parent->left;
            if (uncle != nullptr && uncle->isRed) {
                newNode->parent->isRed = false;
                uncle->isRed = false;
                newNode->parent->parent->isRed = true;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rotateRight(newNode);
                }
                newNode->parent->isRed = false;
                newNode->parent->parent->isRed = true;
                rotateLeft(newNode->parent->parent);
            }
        }
    }
    root->isRed = false;
}

template<typename T>
bool Multiset<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
bool Multiset<T>::remove(const T &element) {
    Node *node = root;
    while (node != nullptr) {
        if (element < node->data) {
            node = node->left;
        } else if (element > node->data) {
            node = node->right;
        } else {
            if (node->count > 1) {
                node->count--;
            } else {
                deleteNode(node);
            }
            size--;
            return true;
        }
    }
    return false;
}

template<typename T>
void Multiset<T>::clear() {
    deleteTree(root);
    size = 0;
}

template<typename T>
void Multiset<T>::outputSet() const {
    Multiset<T>::Iterator it = getIterator();
    for (it.begin(); !it.end(); it.next()) {
        if (it.count() == 1) {
            cout << it.value() << ", ";
        } else {
            cout << it.value() << "(" << it.count() << ")" << ", ";
        }
    }
}

template<typename T>
void Multiset<T>::Iterator::begin() {
    if (current != nullptr) {
        while (current->left != nullptr) {
            current = current->left;
        }
    }
}

template<typename T>
bool Multiset<T>::Iterator::end() const {
    return current == nullptr;
}

template<typename T>
const T &Multiset<T>::Iterator::value() const {
    return current->data;
}

template<typename T>
int Multiset<T>::Iterator::count() const {
    return current->count;
}

template<typename T>
void Multiset<T>::Iterator::next() {
    if (current == nullptr) {
        return;
    }

    if (current->right != nullptr) {
        current = current->right;
        while (current->left != nullptr) {
            current = current->left;
        }
    } else {
        Node *parent = current->parent;
        while (parent != nullptr && current == parent->right) {
            current = parent;
            parent = parent->parent;
        }
        current = parent;
    }
}

template<typename T>
typename Multiset<T>::Iterator Multiset<T>::getIterator() const {
    return Iterator(root);
}

template<typename T>
void Multiset<T>::copyTree(Node *node) {
    if (node != nullptr) {
        insert(node->data);
        copyTree(node->left);
        copyTree(node->right);
    }
}

template<typename T>
void Multiset<T>::deleteNode(Node *node) {
    Node *x;
    Node *y = node;
    bool yOriginalColor = y->isRed;

    if (node->left == nullptr) {
        x = node->right;
        transplant(node, node->right);
    } else if (node->right == nullptr) {
        x = node->left;
        transplant(node, node->left);
    } else {
        y = minimum(node->right);
        yOriginalColor = y->isRed;
        x = y->right;
        if (y->parent == node) {
            if (x != nullptr) {
                x->parent = y;
            }
        } else {
            transplant(y, y->right);
            y->right = node->right;
            if (y->right != nullptr) {
                y->right->parent = y;
            }
        }
        transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
        y->isRed = node->isRed;
    }

    delete node;
    size--;

    if (!yOriginalColor) fixDelete(x);
}

template<typename T>
void Multiset<T>::fixDelete(Node *node) {
    while (node != nullptr && node != root && (!node->isRed)) {
        if (node == node->parent->left) {
            Node *sibling = node->parent->right;
            if (sibling->isRed) {
                sibling->isRed = false;
                node->parent->isRed = true;
                rotateLeft(node->parent);
                sibling = node->parent->right;
            }
            if ((sibling->left == nullptr || !sibling->left->isRed) &&
                (sibling->right == nullptr || !sibling->right->isRed)) {
                sibling->isRed = true;
                node = node->parent;
            } else {
                if (sibling->right == nullptr || !sibling->right->isRed) {
                    if (sibling->left != nullptr) {
                        sibling->left->isRed = false;
                    }
                    sibling->isRed = true;
                    rotateRight(sibling);
                    sibling = node->parent->right;
                }
                sibling->isRed = node->parent->isRed;
                node->parent->isRed = false;
                if (sibling->right != nullptr) {
                    sibling->right->isRed = false;
                }
                rotateLeft(node->parent);
                node = root;
            }
        } else {
            Node *sibling = node->parent->left;
            if (sibling->isRed) {
                sibling->isRed = false;
                node->parent->isRed = true;
                rotateRight(node->parent);
                sibling = node->parent->left;
            }
            if ((sibling->left == nullptr || !sibling->left->isRed) &&
                (sibling->right == nullptr || !sibling->right->isRed)) {
                sibling->isRed = true;
                node = node->parent;
            } else {
                if (sibling->left == nullptr || !sibling->left->isRed) {
                    if (sibling->right != nullptr) {
                        sibling->right->isRed = false;
                    }
                    sibling->isRed = true;
                    rotateLeft(sibling);
                    sibling = node->parent->left;
                }
                sibling->isRed = node->parent->isRed;
                node->parent->isRed = false;
                if (sibling->left != nullptr) {
                    sibling->left->isRed = false;
                }
                rotateRight(node->parent);
                node = root;
            }
        }
    }
    if (node != nullptr) node->isRed = false;
}

template<typename T>
void Multiset<T>::transplant(Node *u, Node *v) {
    if (u->parent == nullptr) root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    if (v != nullptr) v->parent = u->parent;
}

template<typename T>
void Multiset<T>::rotateLeft(Node *node) {
    Node *rightChild = node->right;
    node->right = rightChild->left;
    if (rightChild->left != nullptr) rightChild->left->parent = node;
    rightChild->parent = node->parent;
    if (node->parent == nullptr) root = rightChild;
    else if (node == node->parent->left) node->parent->left = rightChild;
    else node->parent->right = rightChild;
    rightChild->left = node;
    node->parent = rightChild;
}

template<typename T>
void Multiset<T>::rotateRight(Node *node) {
    Node *leftChild = node->left;
    node->left = leftChild->right;
    if (leftChild->right != nullptr) leftChild->right->parent = node;
    leftChild->parent = node->parent;
    if (node->parent == nullptr) root = leftChild;
    else if (node == node->parent->right) node->parent->right = leftChild;
    else node->parent->left = leftChild;
    leftChild->right = node;
    node->parent = leftChild;
}

template<typename T>
typename Multiset<T>::Node *Multiset<T>::minimum(Node *node) const {
    while (node->left != nullptr) node = node->left;
    return node;
}

template<typename T>
void Multiset<T>::deleteTree(Node *node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

template<typename T>
Multiset<T> Multiset<T>::intersect(const Multiset<T> &other) const {
    Multiset<T> result;

    Iterator it = getIterator();
    for (it.begin(); !it.end(); it.next()) {
        if (other.contains(it.value()) ) {
            for (int i = 0; i < min(other.contains(it.value())->count, it.count()); i++){
                result.insert(it.value());
            }
        }
    }
    return result;
}

template<typename T>
typename Multiset<T>::Node* Multiset<T>::contains(const T& value) const {
    Node* current = root;

    while (current != nullptr) {
        if (value < current->data) current = current->left;
        else if (value > current->data) current = current->right;
        else return current;
    }
    return nullptr;
}

template<typename T>
void handleMenuOptions(Multiset<T> &set) {
    int option;
    T element;

    int n;
    while (true) {
        cout << "Amount of elements to enter: ";
        cin >> n;
        cin.ignore();
        if (cin.fail() || n < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
        } else break;
    }
    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "Element " << i + 1 << ": ";
            cin >> element;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please try again.\n";
            } else {
                set.insert(element);
                break;
            }
        }
    }

    do {
        cout << "1. Insert element ";
        cout << "2. Check if set is empty ";
        cout << "3. Check if element belongs to set ";
        cout << "4. Remove element" << endl;
        cout << "5. Intersection of two sets ";
        cout << "6. Display set " << endl;
        cout << "Enter your choice: ";
        cin >> option;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
            continue;
        }

        switch (option) {
            case 1: {
                cout << "Enter element to insert: ";
                cin >> element;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again.\n";
                } else {
                    set.insert(element);
                    cout << "Element inserted." << endl << endl;
                }
                break;
            }
            case 2: {
                if (set.isEmpty()) cout << "Set is empty." << endl << endl;
                else cout << "Set is not empty." << endl << endl;
                break;
            }
            case 3: {
                cout << "Enter element to check: ";
                cin >> element;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again.\n";
                } else {
                    if (set.contains(element)) cout << "Element is present in the set." << endl << endl;
                    else cout << "Element is not present in the set." << endl << endl;
                }
                break;
            }
            case 4: {
                cout << "Enter element to remove: ";
                cin >> element;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please try again.\n";
                } else {
                    if(set.remove(element)) cout << "Element removed." << endl << endl;
                    else cout << "Element is not in set." << endl << endl;
                    break;
                }
            }
            case 5: {
                Multiset<T> set2;
                int amount;
                cout << "Enter amount of elements in second set:\n";
                while (true) {
                    cin >> amount;
                    if (cin.fail() || amount < 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid input. Please try again.\n";
                    } else break;
                }
                for (int i = 0; i < amount; i++) {
                    cout << "Enter element " << i + 1 << " : ";
                    while (true) {
                        cin >> element;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please try again.\n";
                        } else {
                            set2.insert(element);
                            break;
                        }
                    }
                }
                Multiset<T> intersectionSet = set.intersect(set2);
                cout << "Intersection of the sets: ";
                intersectionSet.outputSet();
                cout << endl << endl;
                break;
            }
            case 6: {
                cout << "Set: ";
                set.outputSet();
                cout << endl << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (true);
}
