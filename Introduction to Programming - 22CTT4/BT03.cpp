// 21120566 - Nguyen Huu Thuan
// Bai 3

#include <iostream>
#include <string.h>
#include <sstream>

using namespace std;

struct Laptop {
    string id;
    string date;
    int price;
};

void inputLaptop(Laptop& l) {
    cout << "\tEnter id: "; cin >> l.id;
    cout << "\tEnter date: "; cin >> l.date;
    cout << "\tEnter price: "; cin >> l.price;
}


int compareDate(string date1, string date2) {
    stringstream ss1(date1);
    stringstream ss2(date2);

    int day1, month1, year1;
    int day2, month2, year2;

    ss1 >> day1;
    ss1.ignore(1);
    ss1 >> month1;
    ss1.ignore(1);
    ss1 >> year1;

    ss2 >> day2;
    ss2.ignore(1);
    ss2 >> month2;
    ss2.ignore(1);
    ss2 >> year2;

    if (year1 > year2) return 1;
    else if (year1 < year2) return 0;
    else {
        if (month1 > month2) return 1;
        else if (month1 < month2) return 0;
        else {
            if (day1 > day2) return 1;
            else if (day1 < day2) return 0;
            else return 1;
        }
    }
}

Laptop lastestLaptop(Laptop laptops[], int n) {
    Laptop lastest = laptops[0];
    for (int i = 1; i < n; i++) {
        if (compareDate(laptops[i].date, lastest.date)) lastest = laptops[i];
    }
    return lastest;
}

int main() {
    Laptop laptops[100];
    int n;
    cout << "Enter number of laptops: "; cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter laptop " << i + 1 << endl;
        inputLaptop(laptops[i]);
    }

    Laptop lastest = lastestLaptop(laptops, n);
    cout << "Lastest laptop: " << lastest.id << endl;

    return 0;
}