#include "my_module.h"

bool isValidDate(string &date) {
    int day, month, year;
    if (date.length() < 10) {
        cout << "You entered date in incorrect format. Please, try again" << endl;
        return false;
    }
    try {
        month = stoi(date.substr(0, 2));
        day = stoi(date.substr(3, 2));
        year = stoi(date.substr(6));
    } catch (const std::invalid_argument &e) {
        cout << "You should not enter inappropriate symbols. Please, try again" << endl;
        return false;
    }

    if (date[2] != '-' || date[5] != '-') {
        cout << "Incorrect format (MM-DD-YYYY). Please, try again" << endl;
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

void Student::input(Student &student, int counter) {
    string s_name, s_group, s_dob;

    cout << "Enter data about student N" << counter + 1 << endl;
    while (true) {
        cout << "Name: ";
        getline(cin, s_name);
        if (s_name.length() == 0) {
            cout << "You entered empty string. Please, try again." << endl;
        } else break;
    }

    while (true) {
        cout << "Group: ";
        getline(cin, s_group);
        if (s_group.length() == 0) {
            cout << "You entered empty string. Please, try again." << endl;
        } else break;
    }

    while (true) {
        cout << "Date of birth (MM-DD-YYYY): ";
        getline(cin, s_dob);
        if (isValidDate(s_dob)) break;
    }
    student = Student(s_name, s_group, s_dob);
}

void Student::output() {
    cout << "Name: " << name << endl;
    cout << "Group: " << group << endl;
    cout << "Date of birth: " << date_of_birth << endl;
}

void Student::findOldestStudent(Student *students, int count) {
    string str_search_date;
    while (true) {
        cout << "Enter date for search (MM-DD-YYYY): ";
        getline(cin, str_search_date);
        if (isValidDate(str_search_date)) break;
    }
    int search_day = stoi(str_search_date.substr(3, 2));
    int search_mon = stoi(str_search_date.substr(0, 2));
    int search_year = stoi(str_search_date.substr(6, 4));
    long int search_time = search_year * 365 + search_mon * 30 + search_day;

    string search_group;
    while (true) {
        cout << "Enter group: ";
        getline(cin, search_group);
        if (search_group.length() == 0) {
            cout << "You entered empty string. Please, try again." << endl;
        } else break;
    }


    long int difference = -1;
    int old_sts[count];
    int old_sts_count = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].getGroup() == search_group) {
            string str_st_date = students[i].getDate_of_birth();
            long int st_time = stoi(str_st_date.substr(6, 4)) * 365 + stoi(str_st_date.substr(0, 2)) * 30 +
                               stoi(str_st_date.substr(3, 2));

            if (search_time - st_time > difference) {
                difference = search_time - st_time;
                old_sts_count = 0;
                old_sts[0] = i;
            } else if (search_time - st_time == difference) {
                old_sts_count++;
                old_sts[old_sts_count] = i;
            }
        }
    }

    int age;
    if (old_sts_count == 0 && difference != -1) {
        cout << "The oldest student of the group " << search_group << " is: " << endl;
        students[old_sts[0]].output();
        age = search_year - stoi(students[old_sts[0]].date_of_birth.substr(6, 4));
        if (search_mon < stoi(students[old_sts[0]].date_of_birth.substr(0, 2)) ||
            (search_mon == stoi(students[old_sts[0]].date_of_birth.substr(0, 2)) &&
             search_day < stoi(students[old_sts[0]].date_of_birth.substr(3, 2)))) {
            age--;
        }
        cout << "Student`s age is " << age << " years old" << endl;
    } else if (old_sts_count >= 1) {
        cout << "The oldest student of the group " << search_group << " are: " << endl;
        for (int i = 0; i <= old_sts_count; i++) {
            students[old_sts[i]].output();
            age = search_year - stoi(students[old_sts[i]].date_of_birth.substr(6, 4));
            if (search_mon < stoi(students[old_sts[i]].date_of_birth.substr(0, 2)) ||
                (search_mon == stoi(students[old_sts[i]].date_of_birth.substr(0, 2)) &&
                 search_day < stoi(students[old_sts[i]].date_of_birth.substr(3, 2)))) {
                age--;
            }
            cout << "Student's age is " << age << " years old" << endl << endl;
        }
    } else cout << "There are no students in " << search_group << " group or the date is before their birth" << endl;
}