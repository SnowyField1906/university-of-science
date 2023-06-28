#include <iostream>
#include "Person.cpp"
#include "Student.cpp"

int main()
{

    Person person1;
    Person person2(123456789);
    person1.setId(123456788);

    Student student1;
    Student student2(123456789, 10);
    student1.setId(123456788);
    student1.setGpa(8);

    Person person3(person2);

    Student student3(student2);

    cout << "Person 1: ";
    person1.print();
    cout << "Person 2: ";
    person2.print();
    cout << "Person 3: ";
    person3.print();

    cout << "\nStudent 1: ";
    student1.print();
    cout << "Student 2: ";
    student2.print();
    cout << "Student 3: ";
    student3.print();

    cout << "\nAssign Person 2 to Person 1:" << endl;
    person1 = person2;
    cout << "Person 1: ";
    person1.print();

    cout << "\nAssign Student 2 to Student 1:" << endl;
    student1 = student2;
    cout << "Student 1: ";
    student1.print();

    return 0;
}