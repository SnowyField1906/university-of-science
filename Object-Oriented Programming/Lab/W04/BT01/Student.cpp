/*****************************************************
 * File hiện thực của lớp Student - student.cpp
 *****************************************************/
#include "Student.h"

// Default constructor
Student::Student() : Person(), gpa(0.0)
{
}

// Parameter constructor
Student::Student(long id, double gp) : Person(id), gpa(gp)
{
    assert(gpa >= 0.0 && gpa <= 10.0);
}

// Destructor
Student::~Student()
{
}

// Copy constructor
Student::Student(const Student &student)
    : Person(student),
      gpa(student.gpa)
{
}

// Getter and setter for GPA
double Student::getGpa() const
{
    return gpa;
}

void Student::setGpa(double gpa)
{
    assert(gpa >= 0.0 && gpa <= 10.0);
    this->gpa = gpa;
}

// Print method
void Student::print()
{
    Person::print();
    cout << "\tGPA: " << fixed << setprecision(2) << gpa << endl;
}

// Compound assignment operators
Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        Person::operator=(other);
        gpa = other.gpa;
    }
    return *this;
}