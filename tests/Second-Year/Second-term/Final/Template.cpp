#include <iostream>
#include <string>
using namespace std;

template <class T>
class DynamicArray
{
private:
    T *arr;
    int size;
    int capacity;

public:
    DynamicArray() : arr(nullptr), size(0), capacity(0) {}

    void push_back(const T &element)
    {
        if (size == capacity)
        {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            T *newArr = new T[newCapacity];
            for (int i = 0; i < size; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
        }
        arr[size++] = element;
    }

    T &operator[](int index)
    {
        return arr[index];
    }

    int getSize() const
    {
        return size;
    }

    ~DynamicArray()
    {
        delete[] arr;
    }
};

class Student
{
private:
    string name;
    int age;

public:
    Student() : name(""), age(0) {}

    Student(const string &n, int a) : name(n), age(a) {}

    string getName() const
    {
        return name;
    }

    int getAge() const
    {
        return age;
    }
};

int main()
{
    DynamicArray<Student> studentList;

    studentList.push_back(Student("John Doe", 20));
    studentList.push_back(Student("Jane Smith", 21));
    studentList.push_back(Student("David Johnson", 19));

    for (int i = 0; i < studentList.getSize(); i++)
    {
        cout << "Name: " << studentList[i].getName() << ", Age: " << studentList[i].getAge() << endl;
    }

    return 0;
}
