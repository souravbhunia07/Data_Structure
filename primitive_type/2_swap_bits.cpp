// 2. Swap Bits
// x & (x - 1) = clears the lowest set bit in x
// x & ~(x - 1) = Extracts the lowest set bit of x
#include <bits/stdc++.h>
using namespace std;

long SwapBits(long x, int i, int j)  // TC = O(1)
{
    // Extract the ith and jth bits, and see if they differ.
    if(((x >> i) & 1) != ((x >> j) & 1))
    {
        // ith and jth bits are differ.
        // flip the bits with bit masking. Since x^1 = 0 when x = 1 and x^1 = 1 when x = 0
        unsigned long bit_mask = (1l << i) | (1l << j);
        x ^= bit_mask; 
    }
    return x;
}

int main()
{
    long n;
    int i, j;
    cin >> n >> i >> j;

    cout << SwapBits(n, i, j) << endl;
    return 0;
}
