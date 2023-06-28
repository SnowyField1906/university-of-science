#ifndef REGISTRAR_H
#define REGISTRAR_H

#include "Student.h"
#include "Course.h"

class Registrar
{
private:
    Student *students[1000];
    Course *courses[100];
    int numStudents;
    int numCourses;

public:
    Registrar();
    ~Registrar();

    void addStudent(const char *id, const char *name, const char *birthDate, const char *address);
    void addCourse(const char *id, const char *name, const char *schedule);
    Student *findStudent(const char *id);
    Course *findCourse(const char *id);
    void enroll(Student *student, Course *course);
    void drop(Student *student, Course *course);
    void printStudentList();
    void printCourseList();
    void printEnrollmentList();
};

#endif
