#include "CEbookList.h"
#include "CEbook.cpp"

using namespace std;

CEbookList::CEbookList() {}

void CEbookList::addBook(const CEbook &book)
{
    books.push_back(book);
}

void CEbookList::sortByPrice()
{
    sort(books.begin(), books.end(), [](const CEbook &lhs, const CEbook &rhs)
         { return lhs.getPrice() < rhs.getPrice(); });
}

void CEbookList::sortByPubDate()
{
    sort(books.begin(), books.end(), [](const CEbook &lhs, const CEbook &rhs)
         { return lhs.getPubDate() < rhs.getPubDate(); });
}

void CEbookList::endsWith730() const
{
    for (const CEbook &book : books)
    {
        if (book.getISBN().substr(book.getISBN().length() - 3) == "730")
        {
            cout << book << endl;
        }
    }
}

void CEbookList::readFromFile(const char *filename)
{
    ifstream fin(filename);
    while (true)
    {
        CEbook book;
        book.inputFile(fin);
        books.push_back(book);
        if (fin.eof())
            break;
    }
    fin.close();
}

void CEbookList::printToFile(const char *filename)
{
    ofstream fout(filename);
    for (const CEbook &book : books)
    {
        book.outputFile(fout);
    }
    fout.close();
}

void CEbookList::printToConsole()
{
    for (const CEbook &book : books)
    {
        cout << book << endl;
    }
}