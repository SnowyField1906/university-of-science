#include <iostream>
#include <fstream>
#include "MangPS.cpp"
#include "PhanSo.cpp"

using namespace std;

int main() {
    MangPS mangPS;
    mangPS.input();

    cout << endl << "Fraction array:" << endl;
    mangPS.output();

    cout << endl << "Sum of the array: ";
    cout << mangPS.sum() << endl;

    mangPS.sort();
    cout << endl << "The sorted array:" << endl;
    mangPS.output();

    const char* fileName = "phanso.txt";
    mangPS.write(fileName);
    cout << endl << "Wrote into " << fileName << " successfully." << endl;

    MangPS mangPS2;
    mangPS2.read(fileName);
    cout << endl << "Read " << fileName << " successfully." << endl;
    cout << endl << "Fraction array:" << endl;
    mangPS2.output();

    return 0;
}
