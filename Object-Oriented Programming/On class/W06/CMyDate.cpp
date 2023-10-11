#include "CMyDate.h"

using namespace std;

CMyDate::CMyDate()
{
    day = 1;
    month = 1;
    year = 1900;
}

CMyDate::CMyDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

CMyDate::CMyDate(const CMyDate &other)
{
    this->day = other.day;
    this->month = other.month;
    this->year = other.year;
}

bool CMyDate::operator<(const CMyDate &other) const
{
    if (year < other.year)
    {
        return true;
    }
    else if (year == other.year)
    {
        if (month < other.month)
        {
            return true;
        }
        else if (month == other.month)
        {
            if (day < other.day)
            {
                return true;
            }
        }
    }
    return false;
}

std::istream &operator>>(std::istream &is, CMyDate &date)
{
    cout << "\n\tDay: ";
    is >> date.day;
    cout << "\tMonth: ";
    is >> date.month;
    cout << "\tYear: ";
    is >> date.year;
    return is;
}

std::ostream &operator<<(std::ostream &os, const CMyDate &date)
{
    os << date.day << "/" << date.month << "/" << date.year;
    return os;
}