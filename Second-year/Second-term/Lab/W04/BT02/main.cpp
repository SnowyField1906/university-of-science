#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 1900;
    }

    Date(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    Date(const Date &other)
    {
        this->day = other.day;
        this->month = other.month;
        this->year = other.year;
    }

    int getDay()
    {
        return day;
    }

    int getMonth()
    {
        return month;
    }

    int getYear()
    {
        return year;
    }

    friend std::istream &operator>>(std::istream &is, Date &date)
    {
        cout << "\n\t\tDay: ";
        is >> date.day;
        cout << "\t\tMonth: ";
        is >> date.month;
        cout << "\t\tYear: ";
        is >> date.year;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const Date &date)
    {
        os << date.day << "/" << date.month << "/" << date.year;
        return os;
    }
};

class NhanVien
{
protected:
    string id;
    string name;
    Date dob;
    string address;

public:
    NhanVien() {}
    NhanVien(string id, string name, Date dob, string address)
        : id(id), name(name), dob(dob), address(address) {}
    virtual ~NhanVien() {}

    friend istream &operator>>(istream &is, NhanVien &employee)
    {
        cout << "\tID: ";
        is >> employee.id;
        cout << "\tName: ";
        is.ignore();
        getline(is, employee.name);
        cout << "\tDate of birth: ";
        is >> employee.dob;
        cout << "\tAddress: ";
        is.ignore();
        getline(is, employee.address);
        return is;
    }

    friend ostream &operator<<(ostream &os, NhanVien &employee)
    {
        os << "\tID: " << employee.id << endl;
        os << "\tName: " << employee.name << endl;
        os << "\tDate of birth: " << employee.dob << endl;
        os << "\tAddress: " << employee.address << endl;
        return os;
    }

    virtual long getSalary() = 0;

    string getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    Date getDob()
    {
        return dob;
    }
};

class NVSanXuat : public NhanVien
{
private:
    int nProduct;

public:
    NVSanXuat() : NhanVien() {}
    NVSanXuat(string id, string name, Date dob, string address, int nProduct)
        : NhanVien(id, name, dob, address), nProduct(nProduct) {}

    friend istream &operator>>(istream &is, NVSanXuat &employee)
    {
        NhanVien &temp = employee;
        is >> temp;
        cout << "\tNumber of product: ";
        is >> employee.nProduct;
        return is;
    }

    friend ostream &operator<<(ostream &os, NVSanXuat &employee)
    {
        NhanVien &temp = employee;
        os << temp;
        os << "\tNumber of product: " << employee.nProduct << endl;
        return os;
    }

    long getSalary()
    {
        return nProduct * 20000;
    }
};

class NVCongNhat : public NhanVien
{
private:
    int nDay;

public:
    NVCongNhat() : NhanVien(), nDay(0) {}
    NVCongNhat(string id, string name, Date dob, string address, int nDay) : NhanVien(id, name, dob, address), nDay(nDay) {}
    ~NVCongNhat() {}

    friend istream &operator>>(istream &is, NVCongNhat &employee)
    {
        NhanVien &temp = employee;
        is >> temp;
        cout << "\tNumber of work day: ";
        is >> employee.nDay;
        return is;
    }

    friend ostream &operator<<(ostream &os, NVCongNhat &employee)
    {
        NhanVien &temp = employee;
        os << temp;
        os << "\tNumber of work day: " << employee.nDay << endl;
        return os;
    }

    long getSalary()
    {
        return nDay * 300000;
    }
};

class CongTy
{
private:
    vector<NhanVien *> employees;

public:
    CongTy() {}
    CongTy(int n)
    {
        for (int i = 0; i < n; i++)
        {
            int type;
            cout << "Type of employee (1: NVSanXuat, 2: NVCongNhat): ";
            cin >> type;
            if (type == 1)
            {
                NVSanXuat *employee = new NVSanXuat();
                cin >> *employee;
                add(employee);
            }
            else if (type == 2)
            {
                NVCongNhat *employee = new NVCongNhat();
                cin >> *employee;
                add(employee);
            }
            else
            {
                cout << "Invalid type of employee" << endl;
                i--;
                continue;
            }
        }
    }
    ~CongTy()
    {
        for (NhanVien *employee : employees)
        {
            delete employee;
        }
    }

    void add(NhanVien *employee)
    {
        employees.push_back(employee);
    }

    void remove(string id)
    {
        for (unsigned int i = 0; i < employees.size(); i++)
        {
            if (employees[i]->getId() == id)
            {
                employees.erase(employees.begin() + i);
                return;
            }
        }
    }

    void print()
    {
        for (NhanVien *employee : employees)
        {
            if (NVSanXuat *p = dynamic_cast<NVSanXuat *>(employee))
            {
                cout << *p;
            }
            else if (NVCongNhat *p = dynamic_cast<NVCongNhat *>(employee))
            {
                cout << *p;
            }
            else
            {
                cout << "Unknown Employee Type\n";
            }
        }
    }

    long long totalSalary()
    {
        long total = 0;
        for (NhanVien *employee : employees)
        {
            total += employee->getSalary();
        }
        return total;
    }

    NhanVien *highestSalary()
    {
        NhanVien *highest = employees[0];
        for (NhanVien *employee : employees)
        {
            if (employee->getSalary() > highest->getSalary())
                highest = employee;
        }
        return highest;
    }

    long averageSalary()
    {
        return totalSalary() / employees.size();
    }

    NhanVien *id(string id)
    {
        for (NhanVien *employee : employees)
        {
            if (employee->getId() == id)
                return employee;
        }
        return NULL;
    }

    NhanVien *name(string name)
    {
        for (NhanVien *employee : employees)
        {
            if (employee->getName() == name)
                return employee;
        }
        return NULL;
    }

    int nBirthdayInMay()
    {
        int count = 0;
        for (NhanVien *employee : employees)
        {
            if (employee->getDob().getMonth() == 5)
                count++;
        }
        return count;
    }

    void writeToFile()
    {
        ofstream outfile("emp_LowerAvgSalary.dat");
        if (!outfile.is_open())
        {
            cerr << "Error: could not open output file." << endl;
            return;
        }

        for (NhanVien *employee : employees)
        {
            if (employee->getSalary() < averageSalary())
                outfile << *employee << endl;
        }

        outfile.close();
    }
};

int main()
{
    // create a company with n employees
    int n;
    cout << "Enter number of employees: ";
    cin >> n;
    CongTy company(n);

    // print employee list
    cout << "Employee List:" << endl;
    company.print();

    // calculate total salary
    cout << "Total Salary: " << company.totalSalary() << endl;

    // find employee with highest salary
    NhanVien *highestSalary = company.highestSalary();
    cout << "Employee with highest salary:" << endl;
    cout << *highestSalary << endl;

    // calculate average salary
    cout << "Average Salary: " << company.averageSalary() << endl;

    // find employee by id
    string id;
    cout << "Enter employee id to search: ";
    cin >> id;
    NhanVien *foundEmployeeById = company.id(id);
    if (foundEmployeeById != NULL)
    {
        cout << "Employee found:" << endl;
        cout << *foundEmployeeById << endl;
    }
    else
    {
        cout << "Employee with id " << id << " not found." << endl;
    }

    // find employee by name
    string name;
    cout << "Enter employee name to search: ";
    cin >> name;
    NhanVien *foundEmployeeByName = company.name(name);
    if (foundEmployeeByName != NULL)
    {
        cout << "Employee found:" << endl;
        cout << *foundEmployeeByName << endl;
    }
    else
    {
        cout << "Employee with name " << name << " not found." << endl;
    }

    // count number of employees with birthday in May
    cout << "Number of employees with birthday in May: " << company.nBirthdayInMay() << endl;

    // add a new employee
    NhanVien *newEmployee = new NVSanXuat();
    cout << "Enter information for new employee:" << endl;
    cin >> *newEmployee;
    company.add(newEmployee);
    cout << "Employee added." << endl;

    // remove an employee
    string employeeId;
    cout << "Enter id of employee to remove: ";
    cin >> employeeId;
    company.remove(employeeId);
    cout << "Employee removed." << endl;

    // write employees with salary lower than average to file
    company.writeToFile();
    cout << "Employees with salary lower than average written to file emp_LowerAvgSalary.dat." << endl;

    return 0;
}
