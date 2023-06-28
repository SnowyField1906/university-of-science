#include "Student.h"

Student::Student()
{
    strcpy(id, "");
    strcpy(name, "");
    strcpy(birthDate, "");
    strcpy(address, "");
    numCourses = 0;
    courses = new char *[5];
    for (int i = 0; i < 5; i++)
    {
        courses[i] = new char[50];
        strcpy(courses[i], "");
    }
}

Student::Student(const char *id, const char *name, const char *birthDate, const char *address)
{
    strcpy(this->id, id);
    strcpy(this->name, name);
    strcpy(this->birthDate, birthDate);
    strcpy(this->address, address);
    numCourses = 0;
    courses = new char *[5];
    for (int i = 0; i < 5; i++)
    {
        courses[i] = new char[50];
        strcpy(courses[i], "");
    }
}

Student::~Student()
{
    for (int i = 0; i < 5; i++)
    {
        delete[] courses[i];
    }
    delete[] courses;
}

const char *Student::getId()
{
    return id;
}

const char *Student::getName()
{
    return name;
}

const char *Student::getBirthDate()
{
    return birthDate;
}

const char *Student::getAddress()
{
    return address;
}

Schedule Student::getSchedule()
{
    return schedule;
}

int Student::getNumCourses()
{
    return numCourses;
}

void Student::addCourse(const char *courseName)
{
    if (numCourses >= 5)
    {
        return;
    }
    for (int i = 0; i < numCourses; i++)
    {
        if (strcmp(courses[i], courseName) == 0)
        {
            return;
        }
    }
    strcpy(courses[numCourses], courseName);
    numCourses++;
}

void Student::removeCourse(const char *courseName)
{
    for (int i = 0; i < numCourses; i++)
    {
        if (strcmp(courses[i], courseName) == 0)
        {
            for (int j = i; j < numCourses - 1; j++)
            {
                strcpy(courses[j], courses[j + 1]);
            }
            strcpy(courses[numCourses - 1], "");
            numCourses--;
            return;
        }
    }
}

bool Student::isEnrolled(const char *courseName)
{
    for (int i = 0; i < numCourses; i++)
    {
        if (strcmp(courses[i], courseName) == 0)
        {
            return true;
        }
    }
    return false;
}
