#include "my_module.h"

Product::Product() {
    name = "";
    productionDate = "";
    price = 0;
    quantity = 0;
}

bool Product::isLater(string &date1, string &date2) {
    long int time1 = stoi(date1.substr(0, 2)) + stoi(date1.substr(3, 2)) * 30 +
                     stoi(date1.substr(6, 4)) * 365;
    long int time2 = stoi(date2.substr(0, 2)) + stoi(date2.substr(3, 2)) * 30 +
                     stoi(date2.substr(6, 4)) * 365;

    if (time1 > time2) return true;
    else return false;
}

double Product::totalValue() const {
    return price * quantity;
}

string Product::getName() const {
    return name;
}

string Product::getProductionDate() const {
    return productionDate;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

bool Product::isValidDate(string &date) {
    int day, month, year;
    if (date.length() != 10) {
        cout << "You entered date in incorrect format. Please, try again" << endl;
        return false;
    }
    string dateAllowed = "0123456789/";
    const char *datePartAllowed = "0123456789";
    if (date.find_first_not_of(dateAllowed) != string::npos ||
        date.substr(0, 2).find_first_not_of(datePartAllowed, 0) != string::npos ||
        date.substr(3, 2).find_first_not_of(datePartAllowed, 3) != string::npos ||
        date.substr(6).find_first_not_of(datePartAllowed, 6) != string::npos) {
        cout << "You should not enter inappropriate symbols. Please, try again" << endl;
        return false;
    }
    day = stoi(date.substr(0, 2));
    month = stoi(date.substr(3, 2));
    year = stoi(date.substr(6));

    if (date[2] != '/' || date[5] != '/') {
        cout << "Incorrect format (DD/MM/YYYY). Please, try again" << endl;
        return false;
    }
    if (year < 0 || year > 9999) {
        cout << "Incorrect year (< 0 or > 9999). Please, try again" << endl;
        return false;
    }
    if (month < 1 || month > 12) {
        cout << "Incorrect month (< 1 or > 12). Please, try again" << endl;
        return false;
    }
    if (day < 1 || day > 31) {
        cout << "Incorrect day (< 1 or > 31). Please, try again" << endl;
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
        cout << "Incorrect day (there are less than 31 days in this month). Please, try again" << endl;
        return false;
    }
    if (month == 2) {
        if (day > 29) {
            cout << "There are less than 30 days in February. Please, try again" << endl;
            return false;
        }
        if ((year % 4 != 0 && (year % 100 != 0 || year % 400 == 0)) && day > 28) {
            cout << "There are less than 29 days in February in a non-leap year. Please, try again" << endl;
            return false;
        }
    }
    return true;
}

void Product::output() {
    cout << "Name: " << name << endl;
    cout << "Production date: " << productionDate << endl;
    cout << "Price: " << price << endl;
    cout << "Quantity: " << quantity << endl;
}

void Product::input() {
    string inName, inDate;
    double inPrice;
    int inQuantity;

    while (true) {
        cout << "Name: ";
        getline(cin, inName);
        if (inName.length() == 0) {
            cout << "You entered empty string. Please, try again." << endl;
        } else break;
    }
    name = inName;

    while (true) {
        cout << "Production date (DD/MM/YYYY): ";
        getline(cin, inDate);
        if (isValidDate(inDate)) break;
    }
    productionDate = inDate;

    while (true) {
        cout << "Price: ";
        cin >> inPrice;
        if (cin.fail() || inPrice < 0) {
            cout << "Invalid input. Please try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    cin.ignore();
    price = inPrice;

    while (true) {
        cout << "Quantity: ";
        cin >> inQuantity;
        if (cin.fail() || inQuantity < 0) {
            cout << "Invalid input. Please try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    cin.ignore();
    quantity = inQuantity;
}

IndustrialProduct::IndustrialProduct() {
    transport = "";
    location = "";
}

void IndustrialProduct::warehouseIndValue(IndustrialProduct *products, int count) {
    string searchLocation;
    while (true) {
        cout << "Search location: ";
        getline(cin, searchLocation);
        if (searchLocation.length() == 0) {
            cout << "You entered empty string. Please, try again." << endl;
        } else break;
    }

    double totalValue = 0;
    cout << "Industrial products in " << searchLocation << " :" << endl;
    for (int i = 0; i < count; i++) {
        if (searchLocation == products[i].location) {
            totalValue += products[i].totalValue();
            products[i].output();
            cout << endl;
        }
    }
    cout << "Total value of industrial products in " << searchLocation << " is: " << totalValue << endl << endl;
}

void IndustrialProduct::input(int counter) {
    cout << "Data about industrial product N" << counter + 1 << endl;
    Product product;
    product.input();
    set(product);

    string inTransport, inLocation;
    while (true) {
        cout << "Transport Conditions: ";
        getline(cin, inTransport);
        if (inTransport.length() == 0) {
            cout << "You entered empty string. Please, try again." << endl;
        } else break;
    }
    transport = inTransport;

    while (true) {
        cout << "Storage location: ";
        getline(cin, inLocation);
        if (inLocation.length() == 0) {
            cout << "You entered empty string. Please, try again." << endl;
        } else break;
    }
    location = inLocation;
}

void IndustrialProduct::output() {
    this->Product::output();
    cout << "Transportation conditions: " << transport << endl;
    cout << "Storage location: " << location << endl;
}

void IndustrialProduct::set(Product &product){
    name = product.getName();
    productionDate = product.getProductionDate();
    price = product.getPrice();
    quantity = product.getQuantity();
}

FoodProduct::FoodProduct() {
    expirationDate = "";
}

void FoodProduct::expiredFoodValue(FoodProduct *products, int count) {
    string searchDate;
    while (true) {
        cout << "Date for search (DD/MM/YYYY): ";
        getline(cin, searchDate);
        if (isValidDate(searchDate)) break;
    }

    double totalValue = 0;
    cout << "Expired products:" << endl;
    for (int i = 0; i < count; i++) {
        if (isLater(searchDate, products[i].expirationDate)) {
            totalValue += products[i].totalValue();
            products[i].output();
            cout << endl;
        }
    }
    cout << "Total value of expired food products is: " << totalValue << endl;
}

void FoodProduct::output() {
    this->Product::output();
    cout << "Expiration date: " << expirationDate << endl;
}

void FoodProduct::input(int counter) {
    cout << "Data about food product N" << counter + 1 << endl;
    Product product;
    product.input();
    set(product);

    string inDate;
    while(true) {
        while (true) {
            cout << "Expiration date (DD/MM/YYYY): ";
            getline(cin, inDate);
            if (isValidDate(inDate)) break;
        }
        if (isLater(productionDate, inDate)) {
            cout << "Production date cannot be later than expiration date. Please, try again" << endl;
        } else break;
    }
    expirationDate = inDate;
}

void FoodProduct::set(Product &product){
    name = product.getName();
    productionDate = product.getProductionDate();
    price = product.getPrice();
    quantity = product.getQuantity();
}