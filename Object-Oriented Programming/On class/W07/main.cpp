#include <iostream>

using namespace std;

class ATM
{
private:
    int balance;
    int num500k;
    int num200k;
    int num100k;
    int num50k;

public:
    ATM()
    {
        balance = 10100000;
        num500k = 10;
        num200k = 20;
        num100k = 10;
        num50k = 2;
    }

    void withdraw(int amount)
    {
        if (amount % 50000 != 0)
        {
            throw "Withdrawal amount must be a multiple of 50,000 VND";
        }

        if (amount > balance)
        {
            throw "Insufficient funds";
        }

        int num500k_needed = amount / 500000;
        int num200k_needed = (amount % 500000) / 200000;
        int num100k_needed = ((amount % 500000) % 200000) / 100000;
        int num50k_needed = (((amount % 500000) % 200000) % 100000) / 50000;

        if (num500k_needed > num500k)
        {
            throw "500,000 VND notes not available";
        }

        if (num200k_needed > num200k)
        {
            throw "200,000 VND notes not available";
        }

        if (num100k_needed > num100k)
        {
            throw "100,000 VND notes not available";
        }

        if (num50k_needed > num50k)
        {
            throw "50,000 VND notes not available";
        }

        balance -= amount;
        num500k -= num500k_needed;
        num200k -= num200k_needed;
        num100k -= num100k_needed;
        num50k -= num50k_needed;

        cout << "Withdrawal successful. New balance is " << balance << " VND" << endl;
    }
};

int main()
{
    ATM atm;

    try
    {
        atm.withdraw(500000);
        atm.withdraw(4500000);
        atm.withdraw(100000);
        atm.withdraw(2000000);
        atm.withdraw(1000000);
        atm.withdraw(50000);
        atm.withdraw(2500000);
    }
    catch (const char *message)
    {
        cout << "Error: " << message << endl;
    }

    return 0;
}
