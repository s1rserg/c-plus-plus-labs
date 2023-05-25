#include <iostream>
#include "my_module.h"


int main() {
    int choice;
    cout << "Select the data type for the Multiset:\n";
    cout << "1. Integer\t2. Float\t3. String\n";
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please try again.\n";
        } else break;
    }

    switch (choice) {
        case 1: {
            Multiset<int> set;
            handleMenuOptions(set);
            break;
        }
        case 2: {
            Multiset<float> set;
            handleMenuOptions(set);
            break;
        }
        case 3: {
            Multiset<string> set;
            handleMenuOptions(set);
            break;
        }
        default: {
            cout << "Invalid choice. Exiting...\n";
            break;
        }
    }

    return 0;
}