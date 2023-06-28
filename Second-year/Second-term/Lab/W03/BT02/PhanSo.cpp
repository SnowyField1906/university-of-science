#include "PhanSo.h"

using namespace std;

PhanSo::PhanSo() {
    num = 0;
    den = 1;
}

PhanSo::PhanSo(int num, int den) {
    this->num = num;
    this->den = den;
}

PhanSo::PhanSo(const PhanSo& other) {
    num = other.num;
    den = other.den;
}

PhanSo::~PhanSo() {}

int PhanSo::_gcd(int a, int b) const {
    if (b == 0) {
        return a;
    }
    return _gcd(b, a % b);
}

PhanSo PhanSo::simplify() {
    int gcd = _gcd(num, den);
    num /= gcd;
    den /= gcd;
    return *this;
}

PhanSo PhanSo::operator+(const PhanSo& other) const {
    PhanSo result(num * other.den + den * other.num, den * other.den);
    return result.simplify();
}

PhanSo PhanSo::operator-(const PhanSo& other) const {
    PhanSo result(num * other.den - den * other.num, den * other.den);
    return result.simplify();
}

PhanSo PhanSo::operator*(const PhanSo& other) const {
    PhanSo result(num * other.num, den * other.den);
    return result.simplify();
}

PhanSo PhanSo::operator/(const PhanSo& other) const {
    PhanSo result(num * other.den, den * other.num);
    return result.simplify();
}

PhanSo& PhanSo::operator=(const PhanSo& other) {
    num = other.num;
    den = other.den;
    return *this;
}

PhanSo& PhanSo::operator+=(const PhanSo& other) {
    *this = *this + other;
    return *this;
}

bool PhanSo::operator>(const PhanSo& other) const {
    return num * other.den > den * other.num;
}

std::istream& operator>>(std::istream& is, PhanSo& other) {
    std::cout << "\tNumerator: ";
    is >> other.num;
    std::cout << "\tDenominator: ";
    is >> other.den;
    other.simplify();
    return is;
}

std::ostream& operator<<(std::ostream& os, const PhanSo& other) {
    os << other.num;
    if (other.den != 1) {
        os << "/" << other.den;
    }
    return os;
}