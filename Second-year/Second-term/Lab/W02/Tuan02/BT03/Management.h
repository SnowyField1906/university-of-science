#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#include "Student.h"

class Management
{
private:
    Student *students;
    int numStudents;

public:
    Management();
    ~Management();
    void writeToFile(const char *filename) const;
    void readFromFile(const char *filename);
    void findLowerAvgStudents(const char *filename) const;
    void addStudent(const Student &newStudent, const char *filename);
    void rankStudents();
    void outputRankedList() const;
    void findStudentsByBirthday() const;
};

#endif
