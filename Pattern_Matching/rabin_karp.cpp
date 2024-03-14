#include <iostream>
using namespace std;

#define MOD 1000000007

int p = 31;

long long int powr(int a, int b)
{
    // (a^b) % mod
    long long int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long int inv(int x)
{
    return powr(x, MOD - 2);
}

int poly_hash(string s)
{
    long long int hash = 0, p_power = 1;

    for (int i = 0; i < s.size(); i++)
    {
        hash = (hash + (s[i] - 'a' + 1) * p_power) % MOD;
        p_power = (p_power * p) % MOD;
    }

    return hash;
}

int main()
{
    string text = "abababa";
    string pattern = "aba";
    int n = text.length(), m = pattern.length();
    int pat_hash = poly_hash(pattern);
    int text_hash = poly_hash(text.substr(0, m));

    if (pat_hash == text_hash)
    {
        cout << 0 << endl;
    }

    for (int i = 1; i + m - 1 <= n; i++)
    {
        // remove first character and add next character
        text_hash = (text_hash - (text[i - 1] - 'a' + 1) * powr(p, m - 1)) % MOD;
        text_hash = (text_hash + (text[i + m - 1] - 'a' + 1) * powr(p, m - 1)) % MOD;
        text_hash = (text_hash + MOD) % MOD; // Ensure positive value

        if (text_hash == pat_hash)
        {
            cout << i << endl;
        }
    }
    return 0;
}
