#ifndef COURSE_H
#define COURSE_H

#include <cstring>

class Course
{
private:
    char id[20];
    char name[50];
    char schedule[20];
    char **students;
    int numStudents;

public:
    Course();
    Course(const char *id, const char *name, const char *schedule);
    ~Course();

    const char *getId();
    const char *getName();
    const char *getSchedule();
    int getNumStudents();

    void addStudent(const char *studentName);
    void removeStudent(const char *studentName);
    bool isFull();
    bool isEnrolled(const char *studentName);
};

#endif
