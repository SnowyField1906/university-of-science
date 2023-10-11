#ifndef DATHUC_H
#define DATHUC_H

#include "DonThuc.h"

class DaThuc {
private:
    DonThuc* list;
    int size;

public:
    DaThuc();
    DaThuc(int);
    DaThuc(const DaThuc&);
    ~DaThuc();

    DaThuc simplify() const;
    double value(double) const;

    DaThuc operator+(const DaThuc&) const;
    DaThuc operator-(const DaThuc&) const;
    DaThuc operator*(const DaThuc&) const;
    DaThuc operator/(const DaThuc&) const;

    friend std::istream &operator>>(std::istream&, DaThuc&);
    friend std::ostream &operator<<(std::ostream&, const DaThuc&);
};

#endif // DATHUC_H