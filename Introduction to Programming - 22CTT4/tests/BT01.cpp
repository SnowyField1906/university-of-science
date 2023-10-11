#include <iostream>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};

struct Injection
{
    int no;
    string type;
    Date date;
    string place;
};

struct Vaccine
{
    int id;
    string name;
    Date dob;
};

Injection inputInjection

    Vaccine
    inputVaccine()
{
    Vaccine vaccine;
    cout << "\tInput id: ";
    cin >> vaccine.id;
    cout << "\tInput name: ";
    cin.ignore();
    getline(cin, vaccine.name);
    cout << "\tInput date of birth: " << endl;
    cout << "\t\tDay: ";
    cin >> vaccine.dob.day;
    cout << "\t\tMonth: ";
    cin >> vaccine.dob.month;
    cout << "\t\tYear: ";
    cin >> vaccine.dob.year;

    return vaccine;
}

void inputVaccineList(Vaccine vaccine[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Vaccine " << i + 1 << ": " << endl;
        vaccine[i] = inputVaccine();
    }
}

void outputVaccine(Vaccine vaccine)
{
    cout << "\tID: " << vaccine.id << endl;
    cout << "\tName: " << vaccine.name << endl;
    cout << "\tDate of birth:" << endl;
    cout << "\t\tDay: " << vaccine.dob.day << endl;
    cout << "\t\tMonth: " << vaccine.dob.month << endl;
    cout << "\t\tYear: " << vaccine.dob.year << endl;
}

void outputVaccineList(Vaccine vaccine[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Vaccine " << i + 1 << ": " << endl;
        outputVaccine(vaccine[i]);
    }
}

void sortVaccines(Vaccine vaccine[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vaccine[j].id > vaccine[j + 1].id)
                swap(vaccine[j], vaccine[j + 1]);
        }
    }
}

void filterVaccines(Vaccine vaccine[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (vaccine[i].)
    }
}

int main()
{
    Vaccine vaccines[100];
    int n;
    cout << "Input n: ";
    cin >> n;
    inputVaccineList(vaccines, n);
    outputVaccineList(vaccines, n);

    sortVaccines(vaccines, n);
    outputVaccineList(vaccines, n);
    return 0;
}