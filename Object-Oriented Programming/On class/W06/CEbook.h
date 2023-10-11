#ifndef CEBOOK_H
#define CEBOOK_H

#include <string>
#include "CMyDate.h"

class CEbook
{
private:
    std::string isbn;
    std::string title;
    std::string author;
    CMyDate pubDate;
    std::string category;
    std::string publisher;
    double price;

public:
    CEbook();
    CEbook(std::string isbn, std::string title, std::string author, CMyDate pubDate, std::string category, std::string publisher, double price);
    CEbook(const CEbook &);

    double getPrice() const;
    std::string getISBN() const;
    CMyDate getPubDate() const;

    bool operator>(const CEbook &other);
    bool operator>=(const CEbook &other);
    bool operator<(const CEbook &other);
    bool operator<=(const CEbook &other);

    // I have to separate the input/output file from the operator overloading because I want console input/output to be formatted by `std::cout`
    void inputFile(std::istream &);
    void outputFile(std::ostream &) const;

    friend std::istream &operator>>(std::istream &, CEbook &);
    friend std::ostream &operator<<(std::ostream &, const CEbook &);
};

#endif // CEBOOK_H
