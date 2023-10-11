#ifndef DONTHUC_H
#define DONTHUC_H

#include <iostream>

class DonThuc {
private:
    double coeff;
    int degree;

public:
    DonThuc();
    DonThuc(double, int);

    double getCoeff() const;
    int getDegree() const;
    
    double value(double) const;

    DonThuc operator+(const DonThuc&) const;
    DonThuc operator-(const DonThuc&) const;
    DonThuc operator*(const DonThuc&) const;
    DonThuc operator/(const DonThuc&) const;

    friend std::istream &operator>>(std::istream&, DonThuc&);
    friend std::ostream &operator<<(std::ostream&, const DonThuc&);
};

#endif //DONTHUC_H