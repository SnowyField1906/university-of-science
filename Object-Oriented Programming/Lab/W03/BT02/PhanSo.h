#ifndef PHANSO_H
#define PHANSO_H

class PhanSo {
private:
    int num;
    int den;
    int _gcd(int, int) const;

public:
    PhanSo();
    PhanSo(int, int);
    PhanSo(const PhanSo&);
    ~PhanSo();

    PhanSo simplify();
    PhanSo operator+(const PhanSo&) const;
    PhanSo operator-(const PhanSo&) const;
    PhanSo operator*(const PhanSo&) const;
    PhanSo operator/(const PhanSo&) const;

    PhanSo& operator=(const PhanSo&);
    PhanSo& operator+=(const PhanSo&);
    bool operator>(const PhanSo&) const;

    friend std::istream &operator>>(std::istream&, PhanSo&);
    friend std::ostream &operator<<(std::ostream&, const PhanSo&);
};

#endif // PHANSO_H
