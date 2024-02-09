// How many 1's bits in a number.
#include <bits/stdc++.h>
using namespace std;

short CountBits(unsigned int n) // TC = O(n)
{
    short num_bits = 0;
    while(n)
    {
        num_bits += n & 1;
        n >>= 1;
    }

    return num_bits;
}

int main()
{
    unsigned int n;
    cin >> n;

    cout << CountBits(n) << endl;

    return 0;
}  
