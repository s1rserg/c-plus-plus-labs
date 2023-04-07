#include "my_module.h"

int main() {
    int n;
    while(true) {
        cout << "Enter the number of students: ";
        cin >> n;
        if (cin.fail() || n < 1) {
            cout << "Invalid input. Please try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }
    cin.ignore();
    Student students[n];
    for(int i = 0; i < n; i++) students[i].input(i);
    students[0].findOldestStudent(students, n);
    return 0;
}
