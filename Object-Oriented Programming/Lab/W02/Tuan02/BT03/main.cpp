#include <iostream>
#include "Management.cpp"

using namespace std;

void menu(Management &management)
{
    int choice;
    do
    {
        cout << "Student Management System Menu" << endl;
        cout << "1. Read student data from file" << endl;
        cout << "2. Write student data to file" << endl;
        cout << "3. Add a new student" << endl;
        cout << "4. Find students with lower than average grade" << endl;
        cout << "5. Rank students" << endl;
        cout << "6. Output ranked list" << endl;
        cout << "7. Find students by birthday" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice (0-7): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            char filename[100];
            cout << "Enter filename: ";
            cin >> filename;
            management.readFromFile(filename);
            break;
        }
        case 2:
        {
            char filename[100];
            cout << "Enter filename: ";
            cin >> filename;
            management.writeToFile(filename);
            break;
        }
        case 3:
        {
            char fileName[100];
            char name[100], id[20], dob[11];
            double homework, midterm, final;
            cout << "Enter filename: ";
            cin >> fileName;

            cout << "Enter name: ";
            cin.ignore();
            cin.getline(name, 100);
            cout << "Enter ID: ";
            cin.getline(id, 20);
            cout << "Enter date of birth (dd/mm/yyyy): ";
            cin.getline(dob, 11);
            cout << "Enter homework grade: ";
            cin >> homework;
            cout << "Enter midterm grade: ";
            cin >> midterm;
            cout << "Enter final grade: ";
            cin >> final;
            Student newStudent(name, id, dob, homework, midterm, final);
            management.addStudent(newStudent, fileName);
            cout << "New student added successfully!" << endl;
            break;
        }
        case 4:
        {
            char filename[100];
            cout << "Enter filename: ";
            cin >> filename;
            management.findLowerAvgStudents(filename);
            break;
        }
        case 5:
        {
            management.rankStudents();
            break;
        }
        case 6:
        {
            management.outputRankedList();
            break;
        }
        case 7:
        {
            management.findStudentsByBirthday();
            break;
        }
        case 0:
        {
            cout << "Goodbye!" << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl
             << endl;

    } while (choice != 0);
}

int main()
{
    Management management;
    menu(management);
    return 0;
}
