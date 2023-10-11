#include "DaThuc.h"

using namespace std;

DaThuc::DaThuc() {
    size = 0;
    list = nullptr;
}

DaThuc::DaThuc(int s) {
    size = s;
    list = new DonThuc[size];
}

DaThuc::DaThuc(const DaThuc& other) {
    size = other.size;
    list = new DonThuc[size];
    for (int i = 0; i < size; i++) {
        list[i] = other.list[i];
    }
}

DaThuc::~DaThuc() {
    delete[] list;
}

double DaThuc::value(double x) const {
    double result = 0;
    for (int i = 0; i < size; i++) {
        result += list[i].value(x);
    }
    return result;
}

DaThuc DaThuc::simplify() const {
    DaThuc result(size);
    for (int i = 0; i < size; i++) {
        result.list[i] = list[i];
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (result.list[i].getDegree() == result.list[j].getDegree()) {
                result.list[i] = result.list[i] + result.list[j];
                result.list[j] = DonThuc(0, 0);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (result.list[i].getCoeff() != 0) {
            count++;
        }
    }
    DaThuc result2(count);
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (result.list[i].getCoeff() != 0) {
            result2.list[j] = result.list[i];
            j++;
        }
    }
    return result2;
}

DaThuc DaThuc::operator+(const DaThuc& other) const {
    DaThuc result(size + other.size);
    for (int i = 0; i < size; i++) {
        result.list[i] = list[i];
    }
    for (int i = 0; i < other.size; i++) {
        result.list[size + i] = other.list[i];
    }
    return result.simplify();
}

DaThuc DaThuc::operator-(const DaThuc& other) const {
    DaThuc result(size + other.size);
    for (int i = 0; i < size; i++) {
        result.list[i] = list[i];
    }
    for (int i = 0; i < other.size; i++) {
        result.list[size + i] = other.list[i] * DonThuc(-1, 0);
    }
    return result.simplify();
}

DaThuc DaThuc::operator*(const DaThuc& other) const {
    DaThuc result(size * other.size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < other.size; j++) {
            result.list[i * other.size + j] = list[i] * other.list[j];
        }
    }
    return result.simplify();
}

DaThuc DaThuc::operator/(const DaThuc& other) const {
    if (other.size == 0) {
        cout << "The denominator must not be zero." << endl;
        exit(1);
    }
    // make sure the remainder is zero
    DaThuc result(size - other.size + 1);
    DaThuc remainder(*this);
    for (int i = 0; i < size - other.size + 1; i++) {
        result.list[i] = DonThuc(remainder.list[0].getCoeff() / other.list[0].getCoeff(), remainder.list[0].getDegree() - other.list[0].getDegree());
        for (int j = 0; j < other.size; j++) {
            remainder.list[j] = remainder.list[j] - other.list[j] * result.list[i];
        }
        for (int j = 0; j < remainder.size - 1; j++) {
            remainder.list[j] = remainder.list[j + 1];
        }
        remainder.size--;
    }
    return result.simplify();
}

std::istream& operator>>(std::istream& is, DaThuc& other) {
    cout << "Size: ";
    is >> other.size;
    other.list = new DonThuc[other.size];
    for (int i = 0; i < other.size; i++) {
        cout << "Don thuc " << i + 1 << endl;
        is >> other.list[i];
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const DaThuc& other) {
    for (int i = 0; i < other.size; i++) {
        os << other.list[i];
        if (i != other.size - 1) {
            os << " + ";
        }
    }
    return os;
}