#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Student.cpp"
#include "Management.h"

using namespace std;

Management::Management() : students(nullptr), numStudents(0) {}

Management::~Management()
{
    delete[] students;
}

void Management::addStudent(const Student &newStudent, const char *filename)
{
    Student *temp = new Student[numStudents + 1];
    for (int i = 0; i < numStudents; i++)
    {
        temp[i] = students[i];
    }
    temp[numStudents] = newStudent;
    numStudents++;

    delete[] students;
    students = temp;

    writeToFile(filename);
}

void Management::writeToFile(const char *filename) const
{
    ofstream fout(filename);
    if (!fout.is_open())
    {
        cout << "Error opening file " << filename << endl;
        return;
    }
    fout << numStudents << endl;
    for (int i = 0; i < numStudents; i++)
    {
        fout << students[i].getName() << endl;
        fout << students[i].getId() << endl;
        fout << students[i].getDob() << endl;
        fout << students[i].getHomework() << ' ' << students[i].getMidterm() << ' ' << students[i].getFinal() << endl;
    }
    fout.close();
}

void Management::readFromFile(const char *filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
        cout << "Error opening file " << filename << endl;
        return;
    }
    delete[] students;
    fin >> numStudents;
    students = new Student[numStudents];
    char name[100], id[20], dob[11];
    double homework, midterm, final;
    for (int i = 0; i < numStudents; i++)
    {
        fin.ignore(1);
        fin.getline(name, 100);
        fin.getline(id, 20);
        fin.getline(dob, 11);
        fin >> homework >> midterm >> final;
        students[i] = Student(name, id, dob, homework, midterm, final);
    }
    fin.close();
}

void Management::findLowerAvgStudents(const char *filename) const
{
    double avg = 0;
    for (int i = 0; i < numStudents; i++)
    {
        avg += students[i].getStdAvg();
    }
    avg /= numStudents;

    ofstream fout(filename);
    if (!fout.is_open())
    {
        cout << "Error opening file " << filename << endl;
        return;
    }

    bool found = false;
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].getStdAvg() < avg)
        {
            if (!found)
            {
                fout << "Students with average grade lower than class average:" << endl;
                found = true;
            }
            fout << students[i].getName() << " (" << students[i].getId() << ")" << endl;
            students[i].outputInfo();
            fout << endl;
        }
    }

    if (!found)
    {
        fout << "No student with average grade lower than class average" << endl;
    }

    fout.close();
}

void Management::rankStudents()
{
    for (int i = 0; i < numStudents; i++)
    {
        double curAvg = students[i].getStdAvg();
        if (curAvg >= 8.5)
        {
            cout << students[i].getName() << " (" << students[i].getId() << ") has excellent grade" << endl;
        }
        else if (curAvg >= 7.0)
        {
            cout << students[i].getName() << " (" << students[i].getId() << ") has good grade" << endl;
        }
        else if (curAvg >= 5.5)
        {
            cout << students[i].getName() << " (" << students[i].getId() << ") has fair grade" << endl;
        }
        else
        {
            cout << students[i].getName() << " (" << students[i].getId() << ") has poor grade" << endl;
        }
    }
}

void Management::outputRankedList() const
{
    cout << left << setw(10) << "Rank"
         << setw(20) << "Name"
         << setw(10) << "ID"
         << setw(10) << "Avg"
         << "Ranking\n";

    for (int i = 0; i < numStudents; i++)
    {
        double curAvg = students[i].getStdAvg();
        string ranking;
        if (curAvg >= 8.5)
        {
            ranking = "Excellent";
        }
        else if (curAvg >= 7.0)
        {
            ranking = "Good";
        }
        else if (curAvg >= 5.5)
        {
            ranking = "Fair";
        }
        else
        {
            ranking = "Poor";
        }
        cout << left << setw(10) << i + 1
             << setw(20) << students[i].getName()
             << setw(10) << students[i].getId()
             << setw(10) << fixed << setprecision(2) << curAvg
             << ranking << endl;
    }
}

void Management::findStudentsByBirthday() const
{
    // prompt user to enter current date in format "dd/mm/yyyy"
    string currentDate;
    cout << "Enter current date (dd/mm/yyyy): ";
    cin >> currentDate;

    // extract day, month, and year from current date
    string currentDay = currentDate.substr(0, 2);
    string currentMonth = currentDate.substr(3, 2);
    string currentYear = currentDate.substr(6, 4);

    // search for students with matching date of birth
    bool foundMatch = false;
    for (int i = 0; i < numStudents; i++)
    {
        const char *dob = students[i].getDob();
        string dobDay = string(dob, 2);
        string dobMonth = string(dob + 3, 2);
        string dobYear = string(dob + 6, 4);

        if (dobDay == currentDay && dobMonth == currentMonth)
        {
            if (!foundMatch)
            {
                cout << "Students with same birthday as current date:\n";
                foundMatch = true;
            }
            cout << students[i].getName() << " (" << students[i].getId() << ")\n";
        }
    }

    if (!foundMatch)
    {
        cout << "No students found with same birthday as current date.\n";
    }
}