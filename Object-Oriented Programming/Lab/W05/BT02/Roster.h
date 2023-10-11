#ifndef ROSTER_H
#define ROSTER_H

#include <string>

class Roster
{
private:
    std::string *studentList;
    int studentCount;
    int maxStudent;

public:
    Roster();
    Roster(int maxStudent);
    ~Roster();

    std::string *getStudentList();
    int getStudentCount();
    int getMaxStudent();
    void setMaxStudent(int maxStudent);

    bool addStudent(std::string studentName);
    bool removeStudent(std::string studentName);

    bool isEnrolled(std::string studentName);

    void printRoster();
};

#endif
