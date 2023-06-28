#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
class Student : public Person
{
private:
    double gpa; // Ex. 6.5
public:
    // Constructors
    Student();
    Student(long identity, double gpa);
    ~Student();
    Student(const Student &student);
    // getter(); setter()
    double getGpa() const;
    void setGpa(double gpa);
    // Other methods
    void print();

    Student &operator=(const Student &other);
};
#endif