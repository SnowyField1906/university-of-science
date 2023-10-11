#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student
{
protected:
    string name;
    int age;

public:
    Student(const string &n, int a) : name(n), age(a) {}

    virtual void display()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual ~Student() {}
};

class UndergraduateStudent : public Student
{
private:
    string major;

public:
    UndergraduateStudent(const string &n, int a, const string &m) : Student(n, a), major(m) {}

    void display() override
    {
        cout << "Undergraduate Student - ";
        Student::display();
        cout << "Major: " << major << endl;
    }

    friend ofstream &operator<<(ofstream &ofs, const UndergraduateStudent &student)
    {
        ofs << "Undergraduate " << student.name << " " << student.age << " " << student.major << endl;
        return ofs;
    }
};

class GraduateStudent : public Student
{
private:
    string researchTopic;

public:
    GraduateStudent(const string &n, int a, const string &r) : Student(n, a), researchTopic(r) {}

    void display() override
    {
        cout << "Graduate Student - ";
        Student::display();
        cout << "Research Topic: " << researchTopic << endl;
    }

    friend ofstream &operator<<(ofstream &ofs, const GraduateStudent &student)
    {
        ofs << "Graduate " << student.name << " " << student.age << " " << student.researchTopic << endl;
        return ofs;
    }
};

template <class T>
class StudentDatabase
{
private:
    vector<T *> students;

public:
    void addStudent(T *student)
    {
        students.push_back(student);
    }

    void displayAllStudents()
    {
        for (T *student : students)
        {
            student->display();
        }
    }

    typename vector<T *>::iterator begin()
    {
        return students.begin();
    }

    typename vector<T *>::iterator end()
    {
        return students.end();
    }

    ~StudentDatabase()
    {
        for (T *student : students)
        {
            delete student;
        }
    }
};

int main()
{
    StudentDatabase<Student> database;

    // Thêm sinh viên vào cơ sở dữ liệu
    database.addStudent(new UndergraduateStudent("John Doe", 20, "Computer Science"));
    database.addStudent(new GraduateStudent("Jane Smith", 25, "Machine Learning"));

    // Ghi dữ liệu vào file sử dụng freopen
    FILE *file = freopen("students.txt", "w", stdout);
    if (file)
    {
        for (Student *student : database)
        {
            student->display();
        }
        fclose(stdout);
    }
    else
    {
        cout << "Failed to open file!" << endl;
    }

    // Đọc dữ liệu từ file và hiển thị thông tin sinh viên
    file = freopen("students.txt", "r", stdin);
    string line;
    while (getline(cin, line))
    {
        cout << line << endl;
    }
    fclose(stdin);

    return 0;
}
