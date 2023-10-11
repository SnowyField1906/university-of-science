#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<math.h>

using namespace std;

#define M int(pow(10, 9) + 9)
#define P 31
#define SIZE 20000

bool full = false;

struct Company {
    string name;
    string tax_code;
    string address;
};


long long modPow(long long a, long long b) {
    if (b == 0) return 1;

    long long mod = modPow(a, b/2) % M;

    if (b % 2 == 0) return mod;
    else return  a * mod % M;
}


vector<Company> ReadCompanyList(string file_name){
    ifstream fin(file_name);

    vector<Company> companies;
    
    string line;
    getline(fin, line);
    while(getline(fin, line)) {
        stringstream ss(line);

        Company company;
        getline(ss, company.name, '|');
        getline(ss, company.tax_code, '|');
        getline(ss, company.address, '|');

        companies.push_back(company);
    }
    
    fin.close();
    return companies;
}


long long HashString(string company_name) {
    long long hash = 0; 

    string s = company_name.substr(max(0 , int(company_name.length() - 20)));

    for (unsigned int i = 0; i < s.length(); i++)
        hash = (hash + s[i] * modPow(P, i) % M ) % M;

    return hash;
}

Company* CreateHashTable(vector<Company> list_company) {
    Company* hashTable = new Company[SIZE];

    for(unsigned int i = 0; i < list_company.size(); i++){
        long long hash = HashString(list_company[i].name) % SIZE;

        int cnt = 0;
        while (hashTable[hash].name != "") {
            hash = (hash + 1) % SIZE;
            if (++cnt == SIZE) {
                full = true;
                return hashTable;
            }
        }
        hashTable[hash] = list_company[i];
    }

    return hashTable;
}

void Insert(Company* hashTable, Company company) {
    if (full) {
        cout << "Hash table is full!" << endl;
        return;
    }

    long long hash = HashString(company.name) % SIZE;

    while (hashTable[hash].name != "") hash = (hash + 1) % SIZE;
        
    hashTable[hash] = company;
}

Company* Search(Company* hashTable, string company_name) {
    long long hash = HashString(company_name) % SIZE;
    int cnt = 0;

    while (hashTable[hash].name != ""){
        if (hashTable[hash].name == company_name) return &hashTable[hash];
        hash = (hash + 1) % SIZE;
        if (++cnt == SIZE) break;
    }

    return NULL;
}

void menu(Company* hashTable) {
        cout << "1. Add the info of one company into an existed hash table." << endl;
        cout << "2. Search for company information by its name." << endl;
        cout << "0. Exit" << endl << endl;

        int choice; cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: {
                if (full) cout << "Hash table is full!" << endl;
                else {
                    Company company;
                    cout << "Enter company's name: "; getline(cin, company.name);
                    cout << "Enter company's tax code: "; getline(cin, company.tax_code);
                    cout << "Enter company's address: "; getline(cin, company.address);

                    Insert(hashTable, company);

                    cout << "Inserted successfully!" << endl << endl;
                }
                break;
            }
            case 2: {
                string company_name;

                cout << "Enter company name: "; getline(cin, company_name);
                Company* company = Search(hashTable, company_name);

                if (!company) cout << "Company not found" << endl;
                else {
                    cout << "Company's name: " << company->name << endl;
                    cout << "Company's tax code: " << company->tax_code << endl;
                    cout << "Company's address: " << company->address << endl << endl;
                }
                break;
            }
            case 0: {
                delete[] hashTable;
                exit(1);
            }
            default: {
                cout << "Invalid choice!" << endl;
                break;
            }
        }
}

int main() { 
    vector<Company> companies = ReadCompanyList("MST.txt");
    Company* hashTable = CreateHashTable(companies);

    while(true) {
        menu(hashTable);
    }
    
    return 0;
}