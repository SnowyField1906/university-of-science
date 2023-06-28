#include <iostream>
#include <fstream>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 0;
        month = 0;
        year = 0;
    }
    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }
}

class KhachHang
{
protected:
    string id;
    string name;
    Date billDate;
    int amount;
    int price;

public:
    long virtual getBill() = 0;
}

class KhachHangVietNam : public KhachHang
{
private:
    int type;

public:
    long getBill()
    {
        if (type == 1)
        {
            return amount * price;
        }
        else if (type == 2)
        {
            return amount * price * 0.9;
        }
        else if (type == 3)
        {
            return amount * price * 0.8;
        }
    }
}

class KhachHangNuocNgoai : public KhachHang
{
private:
    int country;

public:
    long getBill()
    {
        return amount * price;
    }
}

class List
{
private:
    vector<KhachHang *> list;

public:
