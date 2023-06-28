/*****************************************************
 * File hiện thưc lớp Person – person.cpp
 *****************************************************/
#include "Person.h"

// Default constructor
Person::Person() : identity(0) {}

// Parameter constructor
Person::Person(long id) : identity(id)
{
    assert(identity >= 100000000 && identity <= 999999999);
}

// Destructor
Person::~Person() {}

// Copy constructor
Person::Person(const Person &person) : identity(person.identity) {}

// Getter and setter for identity
long Person::getId() const
{
    return identity;
}

void Person::setId(long id)
{
    assert(id >= 100000000 && id <= 999999999);
    identity = id;
}

// Print method
void Person::print()
{
    cout << "\n\tIdentity: " << identity << endl;
}
