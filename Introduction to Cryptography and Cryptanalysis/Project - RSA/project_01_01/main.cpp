#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <sstream>
#include <cstring>

using namespace std;

// Convert little-endian hex string to decimal
int hexToDecimal(string hex)
{
    int result = 0;
    int base = 1;
    for (char digit : hex)
    {
        int value;
        if (isdigit(digit))
            value = digit - '0';
        else
            value = 10 + (digit - 'A');

        result += value * base;
        base *= 16;
    }
    return result;
}

// Factorize n into prime factors
vector<int> primeFactorization(int n)
{
    vector<int> factors;
    for (int i = 2; i * i <= n; ++i)
    {
        while (n % i == 0)
        {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        factors.push_back(n);
    return factors;
}

// Check if n is a power of a prime number
bool isPowerOfPrime(int n)
{
    vector<int> factors = primeFactorization(n);
    if (factors.size() == 1 && factors[0] == n)
        return true;
    return false;
}

// Calculate a^b mod n
long long power(long long a, unsigned long long b, unsigned long long n)
{
    long long result = 1;
    a %= n;
    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % n;
        b /= 2;
        a = (a * a) % n;
    }
    return result;
}

// Read file
// Read file
void readFile(string input, string output)
{
    ifstream inputFile(input);

    cout << "READING FILE: " << input << endl;

    if (!inputFile.is_open())
    {
        cout << "Failed to open input file." << endl;
        exit(1);
    }

    string hexValue;
    inputFile >> hexValue;
    inputFile.close();

    cout << "Hex value: " << hexValue << endl;
    int num = hexToDecimal(hexValue);

    stringstream buffer;
    if (isPowerOfPrime(num))
    {
        buffer << "1"; // is a prime number
    }
    else
    {
        buffer << "0"; // is not a prime number
    }

    // Compare to output file if it exists
    ifstream actualOutputFile(output);
    if (actualOutputFile.is_open())
    {
        string actualOutput;
        actualOutputFile >> actualOutput;

        if (actualOutput == buffer.str())
        {
            cout << "Output file is found, computations are correct." << endl;
        }
        else
        {
            cout << "Output file is found, computations are incorrect." << endl;
        }
        actualOutputFile.close();
    }
    else
    {
        cout << "Output file is not found for comparison, created new one." << endl;
    }
    ofstream outputFile(output);
    outputFile << buffer.str() << endl;
    outputFile.close();

    cout << endl;
}

// int main(int argc, char *argv[])
// {
// if (argc != 3)
// {
//     cout << "Usage: " << argv[0] << " input_file output_file" << endl;
//     return 1;
// }
// else
// {
//     readFile(argv[1], argv[2]);
// }

int main()
{
    for (int i = 0; i < 20; i++)
    {
        string name = "test_" + (i < 10 ? "0" + to_string(i) : to_string(i));
        readFile(name + ".inp", name + ".out");
    }

    return 0;
}
