// 4. Find the closest integer with same weight.
/* Write a progrma which takes as input a non negative integer x and returns a number y which is not equal to x, but has the same weight as x and their 
diference is |y - x|, as small as possible. 
example, if x = 6, you should return 5. 
*/
#include <bits/stdc++.h>
using namespace std;

const int kNumUnsignBits = 64;

unsigned long ClosestIntSameBitCount(unsigned long x) // TC = O(n)
{
    for(int i = 0; i < kNumUnsignBits - 1; i++)
    {
        if(((x >> i) & 1) != ((x >> (i + 1)) & 1))
        {
            x ^= (1ul << i) | (1ul << (i + 1));  // Bit masking
            return x;
        }
    }

    // Throw error if all bits of x are 0 or 1.
    throw invalid_argument("All bits are 0 or 1");
}

int main()
{
    unsigned long n;
    cin >> n;

    cout << ClosestIntSameBitCount(n) << endl;
    return 0;
}
