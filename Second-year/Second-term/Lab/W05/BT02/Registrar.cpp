#include "Registrar.h"
#include <iostream>

using namespace std;

Registrar::Registrar()
{
    numStudents = 0;
    numCourses = 0;
}

Registrar::~Registrar()
{
    // Xoá các đối tượng Student và Course trong mảng students và courses
    for (int i = 0; i < numStudents; i++)
    {
        delete students[i];
    }
    for (int i = 0; i < numCourses; i++)
    {
        delete courses[i];
    }
}

void Registrar::addStudent(const char *id, const char *name, const char *birthDate, const char *address)
{
    // Tạo đối tượng Student mới và thêm vào mảng students
    students[numStudents] = new Student(id, name, birthDate, address);
    numStudents++;
}

void Registrar::addCourse(const char *id, const char *name, const char *schedule)
{
    // Tạo đối tượng Course mới và thêm vào mảng courses
    courses[numCourses] = new Course(id, name, schedule);
    numCourses++;
}

Student *Registrar::findStudent(const char *id)
{
    // Tìm kiếm và trả về đối tượng Student với mã sinh viên là id
    for (int i = 0; i < numStudents; i++)
    {
        if (strcmp(students[i]->getId(), id) == 0)
        {
            return students[i];
        }
    }
    return NULL;
}

Course *Registrar::findCourse(const char *id)
{
    // Tìm kiếm và trả về đối tượng Course với mã khóa học là id
    for (int i = 0; i < numCourses; i++)
    {
        if (strcmp(courses[i]->getId(), id) == 0)
        {
            return courses[i];
        }
    }
    return NULL;
}

void Registrar::enroll(Student *student, Course *course)
{
    // Đăng ký đối tượng Student vào đối tượng Course
    if (student != NULL && course != NULL && !course->isFull() && !course->isEnrolled(student->getName()))
    {
        course->addStudent(student->getName());
        student->addCourse(course->getName());
    }
}

void Registrar::drop(Student *student, Course *course)
{
    // Huỷ đăng ký đối tượng Student khỏi đối tượng Course
    if (student != NULL && course != NULL && course->isEnrolled(student->getName()))
    {
        course->removeStudent(student->getName());
        student->removeCourse(course->getName());
    }
}

void Registrar::printStudentList()
{
    // In danh sách các đối tượng Student
    cout << "Student List:" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "ID: " << students[i]->getId() << ", Name: " << students[i]->getName() << endl;
    }
    cout << endl;
}

void Registrar::printCourseList()
{
    // In danh sách các đối tượng Course
    cout << "Course List:" << endl;
    for (int i = 0; i < numCourses; i++)
    {
        cout << "ID: " << courses[i]->getId() << ", Name: " << courses[i]->getName() << endl;
    }
    cout << endl;
}

void Registrar::printEnrollmentList()
{
    // In danh
