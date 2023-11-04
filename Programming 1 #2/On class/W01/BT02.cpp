#include <iostream>

using namespace std;

int main() {
    int price;
    cout << "Input price: ";
    cin >> price;
    cout << "Total price after including VAT: " << price * 1.1 << endl;

    return 0;
}