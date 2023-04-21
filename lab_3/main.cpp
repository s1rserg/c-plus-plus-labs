#include "my_module.h"

int main() {
    double values[3];
    do{
        string line;
        cout << "Enter coordinates of M1:_";
        getline(cin,line);
        if(!input(line, values)) continue;
        break;
    } while (true);


    Vector M1(values[0], values[1], values[2]);
    Vector M2("rand");
    Vector M3;
    M3 = M1 + M2;

    double lengthM3 = M3.length();
    double scalarProduct = M1 * M3;

    cout << endl;
    M1.output("M1");
    M2.output("M2");
    M3.output("M3");
    cout << endl << "Length of vector M3: " << lengthM3 << endl;
    cout << "Scalar product of vectors M1 and M3: " << scalarProduct << endl;

    return 0;
}
