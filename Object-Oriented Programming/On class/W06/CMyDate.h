#ifndef CMyDate_H
#define CMyDate_H

class CMyDate
{
private:
    int day, month, year;

public:
    CMyDate();
    CMyDate(int, int, int);
    CMyDate(const CMyDate &other);

    bool operator<(const CMyDate &) const;

    friend std::istream &operator>>(std::istream &, CMyDate &);

    friend std::ostream &operator<<(std::ostream &, const CMyDate &);
};

#endif // CMyDate_H
