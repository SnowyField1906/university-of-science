#include "CEbook.h"
#include "CMyDate.cpp"

using namespace std;

CEbook::CEbook() {}

CEbook::CEbook(string isbn, string title, string author, CMyDate pubDate, string category, string publisher, double price)
{
    this->isbn = isbn;
    this->title = title;
    this->author = author;
    this->pubDate = pubDate;
    this->category = category;
    this->publisher = publisher;
    this->price = price;
}

CEbook::CEbook(const CEbook &other)
{
    this->isbn = other.isbn;
    this->title = other.title;
    this->author = other.author;
    this->pubDate = other.pubDate;
    this->category = other.category;
    this->publisher = other.publisher;
    this->price = other.price;
}

double CEbook::getPrice() const
{
    return price;
}

string CEbook::getISBN() const
{
    return isbn;
}

CMyDate CEbook::getPubDate() const
{
    return pubDate;
}

bool CEbook::operator>(const CEbook &other)
{
    return price > other.price;
}

bool CEbook::operator>=(const CEbook &other)
{
    return price >= other.price;
}

bool CEbook::operator<(const CEbook &other)
{
    return price < other.price;
}

bool CEbook::operator<=(const CEbook &other)
{
    return price <= other.price;
}

// I have to separate the input/output file from the operator overloading because I want console input/output to be formatted by `std::cout`
void CEbook::inputFile(istream &fin)
{
    fin >> isbn;
    fin.ignore();
    getline(fin, title, '\n');
    getline(fin, author, '\n');
    string day, month, year;
    getline(fin, day, '/');
    getline(fin, month, '/');
    getline(fin, year, '\n');
    pubDate = CMyDate(stoi(day), stoi(month), stoi(year));
    getline(fin, category);
    getline(fin, publisher);
    fin >> price;
}

void CEbook::outputFile(ostream &fout) const
{
    fout << isbn << endl;
    fout << title << endl;
    fout << author << endl;
    fout << pubDate << endl;
    fout << category << endl;
    fout << publisher << endl;
    fout << price << endl;
}

istream &operator>>(istream &is, CEbook &other)
{
    cout << "Enter ISBN: ";
    is >> other.isbn;
    is.ignore();
    cout << "Enter title: ";
    getline(is, other.title, '\n');
    cout << "Enter author: ";
    getline(is, other.author, '\n');
    cout << "Enter publish date: ";
    is >> other.pubDate;
    getline(is, other.category);
    cout << "Enter category: ";
    getline(is, other.publisher);
    cout << "Enter publisher: ";
    is >> other.price;
    return is;
}

ostream &operator<<(ostream &os, const CEbook &other)
{
    os << "ISBN: " << other.isbn << endl;
    os << "Title: " << other.title << endl;
    os << "Author: " << other.author << endl;
    os << "Publish date: " << other.pubDate << endl;
    os << "Category: " << other.category << endl;
    os << "Publisher: " << other.publisher << endl;
    os << "Price: " << other.price << endl;

    return os;
}