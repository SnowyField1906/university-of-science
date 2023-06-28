#include "Course.h"

Course::Course()
{
    strcpy(id, "");
    strcpy(name, "");
    strcpy(schedule, "");
    numStudents = 0;
    students = new char *[40];
    for (int i = 0; i < 40; i++)
    {
        students[i] = nullptr;
    }
}

Course::Course(const char *id, const char *name, const char *schedule)
{
    strcpy(this->id, id);
    strcpy(this->name, name);
    strcpy(this->schedule, schedule);
    numStudents = 0;
    students = new char *[40];
    for (int i = 0; i < 40; i++)
    {
        students[i] = nullptr;
    }
}

Course::~Course()
{
    for (int i = 0; i < numStudents; i++)
    {
        delete[] students[i];
    }
    delete[] students;
}

const char *Course::getId()
{
    return id;
}

const char *Course::getName()
{
    return name;
}

const char *Course::getSchedule()
{
    return schedule;
}

int Course::getNumStudents()
{
    return numStudents;
}

void Course::addStudent(const char *studentName)
{
    if (isFull())
    {
        return;
    }
    students[numStudents] = new char[strlen(studentName) + 1];
    strcpy(students[numStudents], studentName);
    numStudents++;
}

void Course::removeStudent(const char *studentName)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (strcmp(students[i], studentName) == 0)
        {
            delete[] students[i];
            students[i] = nullptr;
            numStudents--;
            for (int j = i; j < numStudents; j++)
            {
                students[j] = students[j + 1];
            }
            students[numStudents] = nullptr;
            break;
        }
    }
}

bool Course::isFull()
{
    return numStudents >= 40;
}

bool Course::isEnrolled(const char *studentName)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (strcmp(students[i], studentName) == 0)
        {
            return true;
        }
    }
    return false;
}
