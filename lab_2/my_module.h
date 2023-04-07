#ifndef MY_MODULE_H
#define MY_MODULE_H

#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Student {
    string name; // ПІБ студента
    string group; // номер групи
    string date_of_birth; // дата народження

public:
    Student(string &name1, string &group1, string &date_of_birth1) {
        name = name1;
        group = group1;
        date_of_birth = date_of_birth1;
    }

    Student() {
        name = "";
        group = "";
        date_of_birth = "";
    }

    string getName() {
        return name;
    }

    string getGroup() {
        return group;
    }

    string getDate_of_birth() {
        return date_of_birth;
    }

    void input(Student &student, int counter);

    void output();

    void findOldestStudent(Student* students, int count);
};

bool isValidDate(string &date);

#endif //MY_MODULE_H
