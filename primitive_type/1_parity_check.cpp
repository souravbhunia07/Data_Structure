// 1. How to compute the parity of a very large number of 64-bit words?
#include <bits/stdc++.h>
using namespace std;

short Parity(unsigned long x)  // TC = O(k)
{
    short result = 0;
    while(x)
    {
        result ^= 1;
        x &= (x - 1);
    }

    return result;
}

int main()
{
    unsigned long n;
    cin >> n;

    cout << Parity(n) << endl;

    return 0;
}
