#include<bits/stdc++.h>
using namespace std;

int main () {
    string date;
    cout << "Enter date in format DD/MM/YYYY: ";
    cin >> date;
    int day = stoi(date.substr(0,2));
    int month = stoi(date.substr(3,2));
    int year = stoi(date.substr(6,4));

    int age;

    if (month > 11) {
        age = 2022 - year;
    } else if (month == 11) {
        if (day > 3) {
            age = 2022 - year - 1;
        } else {
            age = 2022 - year;
        }
    } else {
        age = 2022 - year;
    }
    int countdown = 0;
    if(month < 11 || (month == 11 && day < 3)) {
        for(int i = 1; i <= month ; i++) {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10) {
                countdown += 31;
            } else if (i == 4 || i == 6 || i == 9 || i == 11) {
                countdown += 30;
            } else {
                countdown += 28;
            }
        }
        countdown += 58  - day;
    }
    else if(month == 11 && day == 3) {
        countdown = 0;
    }
    else {
        countdown = (month - 11) * 30 + (day - 3) ;
    }


    cout << "Con " << countdown << " ngay nua toi ngay sinh nhat " << age + 1 << " tuoi cua ban" << endl;
    cout << endl;
    char heart = 3;
    cout << "        i i i i i        " << endl;
    cout << "        i i i i i        " << endl;
    cout << "      __i_i_i_i_i__      " << endl;
    cout << "      |" << heart << "    " << age + 1 << "    " << heart << "|      " << endl;
    cout << "    __| " << heart << "        " << heart << " |__    " << endl;
    cout << "   | " << heart << "    "  << heart <<"    "  << heart << "    "  << heart << " |   " << endl;
    cout << " __|" << heart << " HAPPY "  << heart <<"    "  << heart << "    "  << heart << "|__  " << endl;
    cout <<"| " << heart << "     "  <<  heart  << " BIRTHDAY      " << heart << " |" << endl;
    cout << "|" << heart << "  " << heart << "  " << heart << "  " << heart << "  " << heart << "  " << heart << "  " << heart << "  " << heart << "  " << heart << "|" << endl;
    cout << "| " << heart << "    " << heart << "           " << heart << "    " << heart << " |" << endl;
    cout << "|_________________________|" << endl;

    return 0;
}