#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <complex>
#include <ctime>

using namespace std;

// Self-implemented BigInteger class
class BigInteger
{
private:
    // ATTRIBUTES --------------------------------------------------------------------------
    static const int CELL_LENGTH = 6;  // Chunk length
    static const int MODULO = 1000000; // For computing chunks

    vector<int> data;                 // Chunked number
    typedef complex<double> fft_base; // Fast Fourier Transform base
    // -------------------------------------------------------------------------- ATTRIBUTES

protected:
    // PROTECTED METHODS -------------------------------------------------------------------
    void fft(vector<fft_base> &arg, bool invert) const // Fast Fourier Transform algorithm
    {
        int n = arg.size();
        if (n == 1)
        {
            return;
        }
        vector<fft_base> a0(n / 2), a1(n / 2);
        for (int i = 0, j = 0; i < n; i += 2, j++)
        {
            a0[j] = arg[i];
            a1[j] = arg[i + 1];
        }
        fft(a0, invert);
        fft(a1, invert);

        double angle = 2 * M_PI / n * (invert ? -1 : 1);
        fft_base w(1), wn(cos(angle), sin(angle));
        for (int i = 0; i < n / 2; i++)
        {
            arg[i] = a0[i] + w * a1[i];
            arg[i + n / 2] = a0[i] - w * a1[i];
            if (invert)
            {
                arg[i] /= 2;
                arg[i + n / 2] /= 2;
            }
            w *= wn;
        }
    }

    void cleanup_zeroes() // Remove leading zeroes from chunk
    {
        while (!data.empty() && data.back() == 0)
        {
            data.pop_back();
        }
    }

    string little_to_big_endian(string s) const // Convert little endian hex to big endian
    {
        string res = s;

        reverse(res.begin(), res.end());

        return res;
    }
    // ------------------------------------------------------------------- PROTECTED METHODS

public:
    // CONSTRUCTORS ------------------------------------------------------------------------
    BigInteger()
    {
        data = vector<int>();
    }

    BigInteger(int x)
    {
        data = vector<int>();
        data.push_back(x % MODULO);
        data.push_back(x / MODULO);
        cleanup_zeroes();
    }

    BigInteger(const string &s)
    {
        auto pos = s.begin();
        int current_num = 0, current_pow = 1;
        for (auto it = s.end() - 1; it >= pos; it--)
        {
            if (current_pow == MODULO)
            {
                data.push_back(current_num);
                current_num = 0;
                current_pow = 1;
            }
            current_num += current_pow * int(*it - '0');
            current_pow *= 10;
        }
        if (current_num > 0)
        {
            data.push_back(current_num);
        }
    }
    // ------------------------------------------------------------------------ CONSTRUCTORS

    //

    // I/0 OPERATORS -----------------------------------------------------------------------
    friend ostream &operator<<(ostream &os, const BigInteger &rhs)
    {
        if (rhs.data.empty())
        {
            os << 0;
        }
        for (auto it = rhs.data.end() - 1; it >= rhs.data.begin(); it--)
        {
            string current_str = std::to_string(*it);
            if (it != rhs.data.end() - 1)
            {
                while (current_str.length() < CELL_LENGTH)
                {
                    current_str = '0' + current_str; // NOLINT(performance-inefficient-string-concatenation)
                }
            }
            os << current_str;
        }
        return os;
    }

    friend istream &operator>>(istream &is, BigInteger &rhs)
    {
        string s;
        is >> s;
        rhs = BigInteger(s);
        return is;
    }
    // ----------------------------------------------------------------------- I/0 OPERATORS

    //

    // COMPARISION OPERATORS ---------------------------------------------------------------
    bool operator==(const BigInteger &rhs) const
    {
        return (data == rhs.data);
    }

    bool operator!=(const BigInteger &rhs) const
    {
        return !((*this) == rhs);
    }

    bool operator<(const BigInteger &rhs) const
    {
        int len1 = data.size();
        int len2 = rhs.data.size();
        if (len1 != len2)
        {
            return len1 < len2;
        }
        for (auto pos1 = data.end() - 1, pos2 = rhs.data.end() - 1; pos1 >= data.begin(); pos1--, pos2--)
        {
            if (*pos1 != *pos2)
            {
                return *pos1 < *pos2;
            }
        }
        return false;
    }

    bool operator>(const BigInteger &rhs) const
    {
        return !((*this) == rhs) && !((*this) < rhs);
    }

    bool operator<=(const BigInteger &rhs) const
    {
        return ((*this) == rhs || (*this) < rhs);
    }

    bool operator>=(const BigInteger &rhs) const
    {
        return ((*this) == rhs || (*this) > rhs);
    }
    // --------------------------------------------------------------- COMPARISION OPERATORS

    //

    // ARITHMETIC OPERATORS ----------------------------------------------------------------
    BigInteger operator+(const BigInteger &rhs) const
    {
        BigInteger res;
        auto pos1 = this->data.begin();
        auto pos2 = rhs.data.begin();
        int rem = 0;
        while (pos1 != this->data.end() || pos2 != rhs.data.end() || rem > 0)
        {
            int left_add = pos1 != this->data.end() ? *pos1 : 0;
            int right_add = pos2 != rhs.data.end() ? *pos2 : 0;
            int cur_res = left_add + right_add + rem;

            rem = cur_res / MODULO;
            res.data.push_back(cur_res % MODULO);

            if (pos1 != this->data.end())
                pos1++;
            if (pos2 != rhs.data.end())
                pos2++;
        }
        res.cleanup_zeroes();
        return res;
    }

    BigInteger operator-(const BigInteger &rhs) const
    {
        BigInteger res;
        auto pos1 = this->data.begin();
        auto pos2 = rhs.data.begin();
        int rem = 0;
        while (pos1 != this->data.end() || pos2 != rhs.data.end() || rem > 0)
        {
            int left_add = pos1 != this->data.end() ? *pos1 : 0;
            int right_add = pos2 != rhs.data.end() ? *pos2 : 0;
            int cur_res = left_add - right_add - rem;

            rem = 0;
            if (cur_res < 0)
            {
                rem = 1;
                cur_res += MODULO;
            }
            res.data.push_back(cur_res);

            if (pos1 != this->data.end())
                pos1++;
            if (pos2 != rhs.data.end())
                pos2++;
        }
        res.cleanup_zeroes();
        return res;
    }

    BigInteger operator*(const BigInteger &rhs) const
    {
        BigInteger res;

        vector<long long> res_vec;
        vector<fft_base> left_arg(data.begin(), data.end()), right_arg(rhs.data.begin(), rhs.data.end());
        size_t n = 1;
        while (n < max(data.size(), rhs.data.size()))
        {
            n *= 2;
        }
        n *= 2;
        left_arg.resize(n);
        right_arg.resize(n);
        fft(left_arg, false);
        fft(right_arg, false);
        for (size_t i = 0; i < n; i++)
        {
            left_arg[i] *= right_arg[i];
        }
        fft(left_arg, true);
        res_vec.resize(n);
        for (size_t i = 0; i < n; i++)
        {
            res_vec[i] = (long long)(floor(left_arg[i].real() + 0.5));
        }
        int rem = 0;
        auto pos = res_vec.begin();
        while (rem > 0 || pos != res_vec.end())
        {
            long long add = (pos != res_vec.end() ? *pos : 0);
            long long cur_res = add + rem;

            res.data.push_back(cur_res % MODULO);
            rem = cur_res / MODULO;

            if (pos != res_vec.end())
                pos++;
        }

        res.cleanup_zeroes();
        return res;
    }

    BigInteger operator/(const BigInteger &rhs) const
    {
        vector<int> resVec;

        if (this->data.size() < rhs.data.size())
            resVec = vector<int>(0, 1);
        else
        {
            BigInteger curPow = power_of_10(this->data.size() - rhs.data.size() + 1);
            BigInteger currentSum = BigInteger(0);

            while (curPow != BigInteger(0))
            {
                int lower_bound = 0, upper_bound = MODULO - 1;
                while (upper_bound != lower_bound)
                {
                    int middle = (lower_bound + upper_bound + 1) / 2;
                    BigInteger middleMultiplier = curPow.scalar_mult(middle);
                    if (middleMultiplier * rhs + currentSum <= *this)
                        lower_bound = middle;
                    else
                        upper_bound = middle - 1;
                }
                resVec.push_back(lower_bound);
                currentSum += curPow.scalar_mult(lower_bound) * rhs;
                curPow = curPow.scale(-1);
            }
            reverse(resVec.begin(), resVec.end());
        }
        BigInteger res;
        res.data = resVec;

        res.cleanup_zeroes();
        return res;
    }

    BigInteger operator%(const BigInteger &rhs) const
    {
        BigInteger res;
        return (*this) - rhs * (*this / rhs);
    }
    // ---------------------------------------------------------------- ARITHMETIC OPERATORS

    //

    // ASSIGNMENT OPERATORS ----------------------------------------------------------------
    BigInteger &operator=(const BigInteger &rhs)
    {
        this->data = rhs.data;
        return *this;
    }

    BigInteger &operator+=(const BigInteger &rhs)
    {
        *this = *this + rhs;
        return *this;
    }

    BigInteger &operator-=(const BigInteger &rhs)
    {
        *this = *this - rhs;
        return *this;
    }

    BigInteger &operator*=(const BigInteger &rhs)
    {
        BigInteger res = (*this) * rhs;
        this->data = res.data;
        return *this;
    }

    BigInteger &operator/=(const BigInteger &rhs)
    {
        *this = *this / rhs;
        return *this;
    }

    BigInteger &operator%=(const BigInteger &rhs)
    {
        return *this = *this % rhs;
    }

    BigInteger operator++(int)
    {
        return *this = *this + BigInteger(1);
    }

    BigInteger operator--(int)
    {
        return *this = *this - BigInteger(1);
    }

    // ---------------------------------------------------------------- ASSIGNMENT OPERATORS

    //

    // ADVANCED CALCULATIONS ---------------------------------------------------------------
    BigInteger pow(BigInteger exp, const BigInteger &modulo) const // Modular exponentiation
    {
        BigInteger mult = *this;
        BigInteger res = BigInteger(1);
        while (exp != BigInteger(0))
        {
            if (exp.data[0] % 2 == 1)
            {
                res *= mult;
                if (modulo != BigInteger(0))
                {
                    res %= modulo;
                }
            }
            mult *= mult;
            if (modulo != BigInteger(0))
            {
                mult %= modulo;
            }
            exp /= BigInteger(2);
        }
        return res;
    }

    BigInteger scale(int n) const // Multiply by 10^n
    {
        BigInteger res = *this;
        if (n >= 0)
        {
            vector<int> zeroes(n, 0);
            res.data.reserve(res.data.size() + zeroes.size());
            res.data.insert(res.data.begin(), zeroes.begin(), zeroes.end());
        }
        else
        {
            res.data = vector<int>(res.data.begin() - n, res.data.end());
        }
        return res;
    }

    BigInteger scalar_mult(int n) const // Scalar multiplication
    {
        BigInteger res = *this;
        for (auto &x : res.data)
        {
            x *= n;
        }
        return res;
    }

    BigInteger sqrt() const // Square root
    {
        BigInteger res = power_of_10(this->data.size() / 2);
        bool revert = false;
        while (true)
        {
            BigInteger nextResult = (*this / res + res) / BigInteger(2);
            if (res == nextResult || (res < nextResult && revert))
            {
                break;
            }
            revert = nextResult < res;
            res = nextResult;
        }
        return res;
    }
    // --------------------------------------------------------------- ADVANCED CALCULATIONS

    //

    // INDEPENDENT METHODS ------------------------------------------------------------------
    BigInteger power_of_10(int n) const // Get 10^n
    {
        BigInteger res(1);
        return res.scale(n - 1);
    }

    BigInteger rand_of_num_len(int len) const // Generate random with given number length
    {
        BigInteger ans = power_of_10(len);
        uniform_int_distribution<int> distribution(0, MODULO - 1);
        static random_device randomDevice;
        for (int i = 0; i < len; i++)
        {
            ans.data[i] = distribution(randomDevice);
        }
        return ans;
    }

    BigInteger rand_of_bit_len(int len) const // Generate random with given bit length
    {
        BigInteger ans(0);
        uniform_int_distribution<int> distribution(0, 1);
        static random_device randomDevice;
        BigInteger currentPower(1);
        for (int i = 0; i < len; i++)
        {
            if (distribution(randomDevice))
            {
                ans += currentPower;
            }
            currentPower *= BigInteger(2);
        }
        return ans;
    }

    BigInteger rand(BigInteger max) const // Generate random under a maximum value
    {
        BigInteger ans = rand_of_num_len(max.data.size());
        return ans % max;
    }

    // ------------------------------------------------------------------ INDEPENDENT METHODS

    //

    // HELPER METHODS ----------------------------------------------------------------------
    int to_int() const // Convert to int
    {
        int res = 0;
        if (this->data.empty())
            return res;

        int curMultiplier = 1;
        for (auto digit : this->data)
        {
            res += curMultiplier * digit;
            curMultiplier *= MODULO;
        }

        return res;
    }

    string to_string() const // Convert to string
    {
        stringstream ss;
        ss << *this;
        return ss.str();
    }

    string to_hex(bool is_big_endian = true) const // Convert to hex string
    {
        string res = "";
        BigInteger temp = *this;
        BigInteger base = BigInteger(16);

        while (temp != 0)
        {
            int r = (temp % base).to_int();
            if (r < 10)
            {
                res += (char)(r + '0');
            }
            else
            {
                res += (char)(r - 10 + 'A');
            }
            temp = temp / 16;
        }

        if (!is_big_endian)
        {
            res = little_to_big_endian(res);
        }

        return res;
    }

    void from_hex(string s, bool is_big_endian = true) // Convert from hex string
    {
        if (!is_big_endian)
        {
            s = little_to_big_endian(s);
        }

        int len = s.length();
        BigInteger base(1);
        *this = BigInteger(0);

        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {

                *this += (BigInteger(s[i] - '0') * base);
                base *= 16;
            }
            else if (s[i] >= 'A' && s[i] <= 'F')
            {

                *this += (BigInteger(s[i] - 'A' + 10) * base);
                base *= 16;
            }
            else
            {
                cout << "Invalid hex value." << endl;
                exit(1);
            }
        }
    }

    bool is_odd() const // Check if odd
    {
        if (data.empty())
            return false;
        return data[0] % 2;
    }

    bool is_prime(int times = 3) const // Check if prime using Miller-Rabin algorithm
    {
        if (*this == BigInteger(0) || *this == BigInteger(1))
            return false;

        BigInteger nMinus1 = *this - BigInteger(1);
        BigInteger d = nMinus1;
        int r = 0;

        // Write n-1 as d*2^r
        while ((d.data[0] & 1) == 0)
        {
            d /= BigInteger(2);
            r++;
        }

        for (int i = 0; i < times; ++i)
        {
            BigInteger a = rand(*this - BigInteger(2)) + BigInteger(1);
            BigInteger x = a.pow(d, *this);

            if (x == BigInteger(1) || x == nMinus1)
                continue;

            bool witness = true;
            for (int j = 0; j < r; ++j)
            {
                x = x.pow(BigInteger(2), *this);
                if (x == BigInteger(1))
                    return false;
                if (x == nMinus1)
                {
                    witness = false;
                    break;
                }
            }

            if (witness)
                return false;
        }

        return true;
    }
    // ---------------------------------------------------------------------- HELPER METHODS
};

class RSA
{
private:
    // ATTRIBUTES --------------------------------------------------------------------------
    BigInteger p, q;
    // -------------------------------------------------------------------------- ATTRIBUTES

public:
    // CONSTRUCTORS ------------------------------------------------------------------------
    RSA()
    {
        p = BigInteger(0);
        q = BigInteger(0);
    }

    RSA(BigInteger p, BigInteger q)
    {
        this->p = p;
        this->q = q;
    }
    // ------------------------------------------------------------------------ CONSTRUCTORS

    // HELPER METHODS ----------------------------------------------------------------------
    string d(BigInteger e) const // Check if e is valid
    {
        // return d in hex if valid, "-1" if invalid

        BigInteger phi = (p - BigInteger(1)) * (q - BigInteger(1));
        BigInteger k = BigInteger(1);
        BigInteger d;
        bool found = false;

        while (true) // Find k
        {
            BigInteger temp = (k * phi + BigInteger(1)) / e;
            if (temp * e == k * phi + BigInteger(1))
            {
                d = temp;
                found = true;
                break;
            }
            k++;
            if (k > phi)
                break;
        }

        if (found)
        {
            return d.to_hex();
        }
        else
        {
            return "-1";
        }
    }
};

// Process file
void file_processing(string input, string output)
{
    // set timeout
    clock_t begin = clock();

    ifstream inputFile(input);
    cout << "Processing file: " << input << endl;
    if (!inputFile.is_open())
    {
        cout << "Failed to open input file." << endl;
        exit(1);
    }

    string p_hex;
    string q_hex;
    string e_hex;
    inputFile >> p_hex;
    inputFile >> q_hex;
    inputFile >> e_hex;
    BigInteger p;
    BigInteger q;
    BigInteger e;
    p.from_hex(p_hex, false);
    q.from_hex(q_hex, false);
    e.from_hex(e_hex, false);
    cout << "p-value: " << p << endl;
    cout << "q-value: " << q << endl;
    cout << "e-value: " << e << endl;

    stringstream buffer;
    RSA num = RSA(p, q);
    buffer << num.d(e);

    // Compare to output file if it exists
    ifstream actualOutputFile(output);
    if (actualOutputFile.is_open())
    {
        string actualOutput;
        actualOutputFile >> actualOutput;

        cout << "d-value (computed): " << buffer.str() << endl;
        cout << "d-value (actual): " << actualOutput << endl;

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
        ofstream outputFile(output);
        outputFile << buffer.str() << endl;
        outputFile.close();
    }

    cout << "Time elapsed: " << double(clock() - begin) / CLOCKS_PER_SEC << " seconds." << endl;
    cout << endl;
}

// Test all files
void test()
{
    for (int i = 0; i < 20; i++)
    {
        string name = "test_" + (i < 10 ? "0" + to_string(i) : to_string(i));
        file_processing(name + ".inp", name + ".out");
    }
}

int main(int argc, char *argv[])
{
    test();

    // if (argc != 3)
    // {
    //     cout << "Usage: " << argv[0] << " input_file output_file" << endl;
    //     return 1;
    // }
    // else
    // {
    //     file_processing(argv[1], argv[2]);
    // }

    return 0;
}
