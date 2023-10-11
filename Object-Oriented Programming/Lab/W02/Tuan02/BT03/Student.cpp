#include "Student.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Student::Student()
    : name(nullptr), id(nullptr), dob(nullptr)
{
    marks[0] = 0.0;
    marks[1] = 0.0;
    marks[2] = 0.0;
}

// Constructor with parameters
Student::Student(const char *name, const char *id, const char *dob, double homework, double midterm, double final)
    : name(nullptr), id(nullptr), dob(nullptr)
{
    setName(name);
    setId(id);
    setDob(dob);
    setMarks(homework, midterm, final);
}

// Copy constructor
Student::Student(const Student &other)
    : name(nullptr), id(nullptr), dob(nullptr)
{
    setName(other.name);
    setId(other.id);
    setDob(other.dob);
    marks[0] = other.marks[0];
    marks[1] = other.marks[1];
    marks[2] = other.marks[2];
}

// Destructor
Student::~Student()
{
    delete[] name;
    delete[] id;
    delete[] dob;
}

// Copy assignment operator
Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        setName(other.name);
        setId(other.id);
        setDob(other.dob);
        marks[0] = other.marks[0];
        marks[1] = other.marks[1];
        marks[2] = other.marks[2];
    }
    return *this;
}

// Getter for name
const char *Student::getName() const
{
    return name;
}

// Getter for id
const char *Student::getId() const
{
    return id;
}

// Getter for dob
const char *Student::getDob() const
{
    return dob;
}

// Getter for homework
double Student::getHomework() const
{
    return marks[0];
}

// Getter for midterm
double Student::getMidterm() const
{
    return marks[1];
}

// Getter for final
double Student::getFinal() const
{
    return marks[2];
}

// Getter for standard average
double Student::getStdAvg() const
{
    return marks[0] * 0.25 + marks[1] * 0.25 + marks[2] * 0.5;
}

// Setter for name
void Student::setName(const char *name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

// Setter for id
void Student::setId(const char *id)
{
    delete[] this->id;
    this->id = new char[strlen(id) + 1];
    strcpy(this->id, id);
}

// Setter for dob
void Student::setDob(const char *dob)
{
    delete[] this->dob;
    this->dob = new char[strlen(dob) + 1];
    strcpy(this->dob, dob);
}

// Setter for marks
void Student::setMarks(double homework, double midterm, double final)
{
    marks[0] = homework;
    marks[1] = midterm;
    marks[2] = final;
}

void Student::outputInfo() const
{
    cout << setw(15) << left << "Name:" << setw(15) << left << name << endl
         << setw(15) << left << "ID:" << setw(15) << left << id << endl
         << setw(15) << left << "DOB:" << setw(15) << left << dob << endl
         << setw(15) << left << "Homework:" << setw(15) << left << marks[0] << endl
         << setw(15) << left << "Midterm:" << setw(15) << left << marks[1] << endl
         << setw(15) << left << "Final:" << setw(15) << left << marks[2] << endl
         << setw(15) << left << "StdAvg:" << setw(15) << left << getStdAvg() << endl;
}