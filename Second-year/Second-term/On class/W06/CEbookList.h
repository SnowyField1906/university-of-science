#ifndef CEBOOKLIST_H
#define CEBOOKLIST_H

#include "CEbook.h"
#include <vector>

class CEbookList
{
private:
    std::vector<CEbook> books;

public:
    CEbookList();

    void addBook(const CEbook &);
    void sortByPrice();
    void sortByPubDate();
    void endsWith730() const;
    void readFromFile(const char *);
    void printToFile(const char *filename);
    void printToConsole();
};

#endif // CEBOOKLIST_H