#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <random>
#include <complex>
#include <ctime>

using namespace std;

// Self-implemented biguint class
class biguint
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

    string reverse_endian(string s) const // Reverse endian of hex string
    {
        string res = s;

        reverse(res.begin(), res.end());

        return res;
    }
    // ------------------------------------------------------------------- PROTECTED METHODS

public:
    // CONSTRUCTORS ------------------------------------------------------------------------
    biguint()
    {
        data = vector<int>();
    }

    biguint(int x)
    {
        data = vector<int>();
        data.push_back(x % MODULO);
        data.push_back(x / MODULO);
        cleanup_zeroes();
    }

    biguint(const string &s)
    {
        auto pos = s.begin();
        int cur_num = 0, cur_pow = 1;
        for (auto it = s.end() - 1; it >= pos; it--)
        {
            if (cur_pow == MODULO)
            {
                data.push_back(cur_num);
                cur_num = 0;
                cur_pow = 1;
            }
            cur_num += cur_pow * int(*it - '0');
            cur_pow *= 10;
        }
        if (cur_num > 0)
        {
            data.push_back(cur_num);
        }
    }
    // ------------------------------------------------------------------------ CONSTRUCTORS

    //

    // I/0 OPERATORS -----------------------------------------------------------------------
    friend ostream &operator<<(ostream &os, const biguint &rhs)
    {
        if (rhs.data.empty())
        {
            os << 0;
        }
        for (auto it = rhs.data.end() - 1; it >= rhs.data.begin(); it--)
        {
            string cur_str = std::to_string(*it);
            if (it != rhs.data.end() - 1)
            {
                while (cur_str.length() < CELL_LENGTH)
                {
                    cur_str = '0' + cur_str; // NOLINT(performance-inefficient-string-concatenation)
                }
            }
            os << cur_str;
        }
        return os;
    }

    friend istream &operator>>(istream &is, biguint &rhs)
    {
        string s;
        is >> s;
        rhs = biguint(s);
        return is;
    }
    // ----------------------------------------------------------------------- I/0 OPERATORS

    //

    // COMPARISION OPERATORS ---------------------------------------------------------------
    bool operator==(const biguint &rhs) const
    {
        return (data == rhs.data);
    }

    bool operator!=(const biguint &rhs) const
    {
        return !((*this) == rhs);
    }

    bool operator<(const biguint &rhs) const
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

    bool operator>(const biguint &rhs) const
    {
        return !((*this) == rhs) && !((*this) < rhs);
    }

    bool operator<=(const biguint &rhs) const
    {
        return ((*this) == rhs || (*this) < rhs);
    }

    bool operator>=(const biguint &rhs) const
    {
        return ((*this) == rhs || (*this) > rhs);
    }
    // --------------------------------------------------------------- COMPARISION OPERATORS

    //

    // ARITHMETIC OPERATORS ----------------------------------------------------------------
    biguint operator+(const biguint &rhs) const
    {
        biguint res;
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
            {
                pos1++;
            }

            if (pos2 != rhs.data.end())
            {
                pos2++;
            }
        }
        res.cleanup_zeroes();
        return res;
    }

    biguint operator-(const biguint &rhs) const
    {
        biguint res;
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
            {
                pos1++;
            }

            if (pos2 != rhs.data.end())
            {
                pos2++;
            }
        }
        res.cleanup_zeroes();
        return res;
    }

    biguint operator*(const biguint &rhs) const
    {
        biguint res;
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
            {
                pos++;
            }
        }

        res.cleanup_zeroes();
        return res;
    }

    biguint operator/(const biguint &rhs) const
    {
        vector<int> res_vec;

        if (this->data.size() < rhs.data.size())
        {
            res_vec = vector<int>(0, 1);
        }
        else
        {
            biguint cur_pow = power_of_10(this->data.size() - rhs.data.size() + 1);
            biguint cur_sum = biguint(0);

            while (cur_pow != biguint(0))
            {
                int lower_bound = 0, upper_bound = MODULO - 1;

                while (upper_bound != lower_bound)
                {
                    int mid = (lower_bound + upper_bound + 1) / 2;
                    biguint mid_mul = cur_pow.scalar_mult(mid);
                    if (mid_mul * rhs + cur_sum <= *this)
                    {
                        lower_bound = mid;
                    }
                    else
                    {
                        upper_bound = mid - 1;
                    }
                }

                res_vec.push_back(lower_bound);
                cur_sum += cur_pow.scalar_mult(lower_bound) * rhs;
                cur_pow = cur_pow.scale(-1);
            }
            reverse(res_vec.begin(), res_vec.end());
        }
        biguint res;
        res.data = res_vec;

        res.cleanup_zeroes();
        return res;
    }

    biguint operator%(const biguint &rhs) const
    {
        biguint res;
        return (*this) - rhs * (*this / rhs);
    }
    // ---------------------------------------------------------------- ARITHMETIC OPERATORS

    //

    // ASSIGNMENT OPERATORS ----------------------------------------------------------------
    biguint &operator=(const biguint &rhs)
    {
        this->data = rhs.data;
        return *this;
    }

    biguint &operator+=(const biguint &rhs)
    {
        *this = *this + rhs;
        return *this;
    }

    biguint &operator-=(const biguint &rhs)
    {
        *this = *this - rhs;
        return *this;
    }

    biguint &operator*=(const biguint &rhs)
    {
        biguint res = (*this) * rhs;
        this->data = res.data;
        return *this;
    }

    biguint &operator/=(const biguint &rhs)
    {
        *this = *this / rhs;
        return *this;
    }

    biguint &operator%=(const biguint &rhs)
    {
        return *this = *this % rhs;
    }

    biguint operator++(int)
    {
        return *this = *this + biguint(1);
    }

    biguint operator--(int)
    {
        return *this = *this - biguint(1);
    }

    // ---------------------------------------------------------------- ASSIGNMENT OPERATORS

    //

    // ADVANCED CALCULATIONS ---------------------------------------------------------------
    biguint pow(biguint exp, const biguint &modulo) const // Modular exponentiation
    {
        biguint mult = *this;
        biguint res = biguint(1);
        while (exp != biguint(0))
        {
            if (exp.data[0] % 2 == 1)
            {
                res *= mult;
                if (modulo != biguint(0))
                {
                    res %= modulo;
                }
            }
            mult *= mult;
            if (modulo != biguint(0))
            {
                mult %= modulo;
            }
            exp /= biguint(2);
        }
        return res;
    }

    biguint scale(int n) const // Multiply by 10^n
    {
        biguint res = *this;

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

    biguint scalar_mult(int n) const // Scalar multiplication
    {
        biguint res = *this;

        for (auto &x : res.data)
        {
            x *= n;
        }

        return res;
    }

    biguint sqrt() const // Square root
    {
        biguint res = power_of_10(this->data.size() / 2);
        bool revert = false;

        while (true)
        {
            biguint next_res = (*this / res + res) / biguint(2);
            if (res == next_res || (res < next_res && revert))
            {
                break;
            }
            revert = next_res < res;
            res = next_res;
        }

        return res;
    }

    biguint gcd(const biguint &rsh) const // Greatest common divisor
    {
        biguint x1 = biguint(1);
        biguint y1 = biguint(0);
        biguint x2 = biguint(0);
        biguint y2 = biguint(1);
        biguint a = *this;
        biguint b = rsh;

        while (b != biguint(0))
        {
            biguint q = a / b;
            biguint r = a % b;
            x1 = x2;
            y1 = y2;
            x2 = x1 - q * x2;
            y2 = y1 - q * y2;
            a = b;
            b = r;
        }

        return a;
    }

    biguint mod_inverse(const biguint &modulo) const // Modular multiplicative inverse
    {
        biguint x1 = biguint(1);
        biguint x2 = *this;
        biguint y1 = biguint(0);
        biguint t2 = modulo;

        biguint res, q, t1, t3;
        int iter = 1;

        while (t2 != 0)
        {
            q = x2 / t2;
            t3 = x2 % t2;
            t1 = x1 + q * y1;

            // swap
            x1 = y1;
            y1 = t1;
            x2 = t2;
            t2 = t3;
            iter = -iter;
        }

        if (x2 != 1)
        {
            return 0; // no inverse
        }

        if (iter < 0)
        {
            res = modulo - x1;
        }
        else
        {
            res = x1;
        }

        return res;
    }
    // --------------------------------------------------------------- ADVANCED CALCULATIONS

    //

    // INDEPENDENT METHODS ------------------------------------------------------------------
    biguint power_of_10(int n) const // Get 10^n
    {
        biguint res(1);
        return res.scale(n - 1);
    }

    biguint rand_of_num_len(int len) const // Generate random with given number length
    {
        biguint res = power_of_10(len);
        uniform_int_distribution<int> distribution(0, MODULO - 1);
        static random_device rand;

        for (int i = 0; i < len; i++)
        {
            res.data[i] = distribution(rand);
        }

        return res;
    }

    biguint rand_of_bit_len(int len) const // Generate random with given bit length
    {
        biguint res(0);
        biguint cur_pow(1);
        static random_device rand;
        uniform_int_distribution<int> distribution(0, 1);

        for (int i = 0; i < len; i++)
        {
            if (distribution(rand))
            {
                res += cur_pow;
            }
            cur_pow *= biguint(2);
        }

        return res;
    }

    biguint rand(biguint max) const // Generate random under a maximum value
    {
        biguint res = rand_of_num_len(max.data.size());
        return res % max;
    }

    // ------------------------------------------------------------------ INDEPENDENT METHODS

    //

    // HELPER METHODS ----------------------------------------------------------------------
    int to_int() const // Convert to int
    {
        int res = 0;

        if (this->data.empty())
        {
            return res;
        }

        int cur_mul = 1;

        for (auto digit : this->data)
        {
            res += cur_mul * digit;
            cur_mul *= MODULO;
        }

        return res;
    }

    string to_string() const // Convert to string
    {
        stringstream res;
        res << *this;

        return res.str();
    }

    string to_hex(bool is_big_endian = true) const // Convert to hex string
    {
        string res = "";
        biguint temp = *this;
        biguint base = biguint(16);

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

        if (is_big_endian)
        {
            res = reverse_endian(res);
        }

        return res;
    }

    void from_hex(string s, bool is_big_endian = true) // Convert from hex string
    {
        if (!is_big_endian)
        {
            s = reverse_endian(s);
        }

        int len = s.length();
        biguint base(1);
        *this = biguint(0);

        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {

                *this += (biguint(s[i] - '0') * base);
                base *= 16;
            }
            else if (s[i] >= 'A' && s[i] <= 'F')
            {

                *this += (biguint(s[i] - 'A' + 10) * base);
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
        {
            return false;
        }

        return data[0] % 2;
    }

    bool is_prime(int times = 3) const // Check if prime using Miller-Rabin algorithm
    {
        if (*this == biguint(0) || *this == biguint(1))
        {
            return false;
        }

        biguint n_minus_one = *this - biguint(1);
        biguint d = n_minus_one;
        int r = 0;

        // Write n-1 as d*2^r
        while ((d.data[0] & 1) == 0)
        {
            d /= biguint(2);
            r++;
        }

        for (int i = 0; i < times; ++i)
        {
            biguint a = rand(*this - biguint(2)) + biguint(1);
            biguint x = a.pow(d, *this);

            if (x == biguint(1) || x == n_minus_one)
                continue;

            bool witness = true;
            for (int j = 0; j < r; ++j)
            {
                x = x.pow(biguint(2), *this);
                if (x == biguint(1))
                    return false;
                if (x == n_minus_one)
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

// Process file
void file_processing(string input, string output)
{
    // set timeout
    clock_t begin = clock();

    ifstream fin(input);
    cout << "Processing file: " << input << endl;
    if (!fin.is_open())
    {
        cout << "Failed to open input file." << endl;
        exit(1);
    }

    string hex_value;
    fin >> hex_value;
    fin.close();

    biguint num;
    num.from_hex(hex_value, false);
    cout << "Value (decimal): " << num << endl;

    stringstream buffer;
    if (num.is_prime())
    {
        buffer << "1"; // is a prime number
    }
    else
    {
        buffer << "0"; // is not a prime number
    }

    // Compare to output file if it exists
    ifstream fiout(output);
    if (fiout.is_open())
    {
        string actualOutput;
        fiout >> actualOutput;

        if (actualOutput == buffer.str())
        {
            cout << "Output file is found, computations are correct." << endl;
        }
        else
        {
            cout << "Output file is found, computations are incorrect." << endl;
        }
        fiout.close();
    }
    else
    {
        cout << "Output file is not found for comparison, created new one." << endl;
        ofstream fout(output);
        fout << buffer.str() << endl;
        fout.close();
    }

    cout << "Took " << double(clock() - begin) / CLOCKS_PER_SEC << " seconds." << endl;
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
    // test();

    if (argc != 3)
    {
        cout << "Usage: " << argv[0] << " input_file output_file" << endl;
        return 1;
    }
    else
    {
        file_processing(argv[1], argv[2]);
    }

    return 0;
}
