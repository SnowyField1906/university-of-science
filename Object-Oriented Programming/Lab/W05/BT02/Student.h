#ifndef STUDENT_H
#define STUDENT_H

#include <cstring>
#include "Schedule.h"

class Student
{
private:
    char id[20];
    char name[50];
    char birthDate[15];
    char address[100];
    Schedule schedule;
    char **courses;
    int numCourses;

public:
    Student();
    Student(const char *id, const char *name, const char *birthDate, const char *address);
    ~Student();

    const char *getId();
    const char *getName();
    const char *getBirthDate();
    const char *getAddress();
    Schedule getSchedule();
    int getNumCourses();

    void addCourse(const char *courseName);
    void removeCourse(const char *courseName);
    bool isEnrolled(const char *courseName);
};

#endif
