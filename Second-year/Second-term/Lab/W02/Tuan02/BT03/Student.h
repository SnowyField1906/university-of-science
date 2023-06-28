#ifndef STUDENT_H
#define STUDENT_H

class Student
{
private:
    char *name;
    char *id;
    char *dob;
    double marks[3];

public:
    Student();
    Student(const char *name, const char *id, const char *dob, double homework, double midterm, double final);
    Student(const Student &other);
    ~Student();
    Student &operator=(const Student &other);
    const char *getName() const;
    const char *getId() const;
    const char *getDob() const;
    double getHomework() const;
    double getMidterm() const;
    double getFinal() const;
    double getStdAvg() const;
    void setName(const char *name);
    void setId(const char *id);
    void setDob(const char *dob);
    void setMarks(double homework, double midterm, double final);
    void outputInfo() const;
};

#endif
