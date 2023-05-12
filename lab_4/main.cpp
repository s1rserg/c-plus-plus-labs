#include "my_module.h"


int main() {
    int industrial, food;
    while (true) {
        cout << "Amount of industrial product types: ";
        cin >> industrial;
        if (cin.fail() || industrial < 1) {
            cout << "Invalid input. Please try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    cin.ignore();

    IndustrialProduct indProducts[industrial];
    for (int i = 0; i < industrial; i++) indProducts[i].input(i);
    cout << endl;

    while (true) {
        cout << "Amount of food product types: ";
        cin >> food;
        if (cin.fail() || food < 1) {
            cout << "Invalid input. Please try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    cin.ignore();

    FoodProduct foodProducts[food];
    for (int i = 0; i < food; i++) foodProducts[i].input(i);
    cout << endl;

    IndustrialProduct::warehouseIndValue(indProducts, industrial);
    FoodProduct::expiredFoodValue(foodProducts, food);
    return 0;
}