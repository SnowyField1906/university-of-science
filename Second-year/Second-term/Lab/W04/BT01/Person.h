/*****************************************************
 * Tệp giao diện của lớp Person – person.h
 *****************************************************/
#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;
class Person
{
private:
    long identity; // Ex. 211276111
public:
    // Constructors
    Person();
    Person(long identity);
    ~Person();
    Person(const Person &person);
    // getter, setter
    long getId() const;
    void setId(long id);
    // other methods
    void print();
};
#endif