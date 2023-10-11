#include "MangPS.h"

using namespace std;

MangPS::MangPS() {
    size = 0;
    list = NULL;
}

MangPS::~MangPS() {
    if (list != NULL) {
        delete[] list;
    }
}

void MangPS::input() {
    cout << "Number of fractions: ";
    cin >> size;
    list = new PhanSo[size];
    for (int i = 0; i < size; i++) {
        cout << "Fraction " << i + 1 << ":" << endl;
        cin >> list[i];
        cout << endl;
    }
}

void MangPS::output() const {
    for (int i = 0; i < size; i++) {
        cout << list[i] << " ";
    }
}

PhanSo MangPS::sum() const {
    PhanSo sum;
    for (int i = 0; i < size; i++) {
        sum += list[i];
    }
    return sum;
}

void MangPS::sort() {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (list[i] > list[j]) {
                swap(list[i], list[j]);
            }
        }
    }
}

void MangPS::write(const char* fileName) const {
    FILE* fp = freopen(fileName, "w", stdout);
    if (fp != NULL) {
        cout << size << endl;
        for (int i = 0; i < size; i++) {
            cout << list[i] << endl;
        }
        fclose(fp);
    } else {
        cout << "Khong the mo file!" << endl;
    }
}

void MangPS::read(const char* fileName) {
    FILE* fp = freopen(fileName, "r", stdin);
    if (fp != NULL) {
        cin >> size;
        if (list != NULL) {
            delete[] list;
        }
        list = new PhanSo[size];
        for (int i = 0; i < size; i++) {
            cin >> list[i];
        }
        fclose(fp);
    } else {
        cout << "Khong the mo file!" << endl;
    }
}
