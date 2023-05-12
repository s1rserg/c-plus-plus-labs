#ifndef LAB_4_MY_MODULE_H
#define LAB_4_MY_MODULE_H

#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Product {
protected:
    string name;
    string productionDate;
    double price;
    int quantity;

public:
    Product();

    string getName() const;

    string getProductionDate() const;

    double getPrice() const;

    int getQuantity() const;

    static bool isLater(string &date1, string &date2);  // дата 1 пізніша за дату 2
    static bool isValidDate(string &date);

    void input();

    double totalValue() const;

    void output();
};

class IndustrialProduct : public Product {
    string transport;
    string location;

public:
    IndustrialProduct();

    static void warehouseIndValue(IndustrialProduct *products, int count);

    void input(int counter);

    void set(Product &product);

    void output();
};

class FoodProduct : public Product {
    string expirationDate;

public:
    FoodProduct();

    static void expiredFoodValue(FoodProduct *products, int count);

    void input(int counter);

    void set(Product &product);

    void output();
};

#endif //LAB_4_MY_MODULE_H