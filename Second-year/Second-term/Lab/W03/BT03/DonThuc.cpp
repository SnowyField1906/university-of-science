#include "DonThuc.h"

using namespace std;

DonThuc::DonThuc() {
    coeff = 0;
    degree = 0;
}

DonThuc::DonThuc(double coeff, int degree) {
    this->coeff = coeff;
    this->degree = degree;
}

double DonThuc::getCoeff() const {
    return coeff;
}

int DonThuc::getDegree() const {
    return degree;
}

double DonThuc::value(double x) const {
    return coeff * pow(x, degree);
}

DonThuc DonThuc::operator+(const DonThuc& other) const {
    if (degree != other.degree) {
        cout << "The degree must not be different." << endl;
        exit(1);
    }
    return DonThuc(coeff + other.coeff, degree);
}

DonThuc DonThuc::operator-(const DonThuc& other) const {
    if (degree != other.degree) {
        cout << "The degree must not be different." << endl;
        exit(1);
    }
    return DonThuc(coeff - other.coeff, degree);
}

DonThuc DonThuc::operator*(const DonThuc& other) const {
    return DonThuc(coeff * other.coeff, degree + other.degree);
}

DonThuc DonThuc::operator/(const DonThuc& other) const {
    if (other.coeff == 0) {
        cout << "The denominator must not be zero." << endl;
        exit(1);
    }
    return DonThuc(coeff / other.coeff, degree - other.degree);
}

std::istream& operator>>(std::istream& is, DonThuc& other) {
    cout << "\tCoeff: ";
    is >> other.coeff;
    cout << "\tDegree: ";
    is >> other.degree;
    return is;
}

std::ostream& operator<<(std::ostream& os, const DonThuc& other) {
    os << other.coeff << "x^" << other.degree;
    return os;
}