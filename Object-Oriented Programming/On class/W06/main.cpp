#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <string>

#include "CEbookList.cpp"

using namespace std;

int main()
{
    CEbookList list;

    while (true)
    {
        cout << "1. Read from console" << endl;
        cout << "2. Print to console" << endl;
        cout << "3. Read from file" << endl;
        cout << "4. Sort by price and print to file" << endl;
        cout << "5. Sort by pub. date and print to file" << endl;
        cout << "6. Print books with ISBN ending with 730" << endl;
        cout << "0. Exit" << endl;

        int choice;
        cout << "Your choice: ";
        cin.clear();
        cin >> choice;

        switch (choice)
        {
        case 1:
            int n;
            cout << "Number of books: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                cout << "\nBOOK " << i + 1 << endl;
                CEbook book;
                cin >> book;
                list.addBook(book);
            }
            break;
        case 2:
            list.printToConsole();
            break;

        case 3:
            list.readFromFile("input.txt");
            break;

        case 4:
            list.sortByPrice();
            cout << "Sorted by price" << endl;
            list.printToFile("output.txt");
            break;

        case 5:
            list.sortByPubDate();
            list.printToFile("output.txt");
            break;

        case 6:
            list.endsWith730();
            break;

        case 0:
            return 0;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}
