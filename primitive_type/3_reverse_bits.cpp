#include <bits/stdc++.h>
using namespace std;
#include <cstdint> // Include for uint64_t

class Solution {
public:
    uint64_t reverseBits(uint64_t n) {
        uint64_t ans = 0;
        for(int i = 0; i < 64; i++) {
            ans <<= 1;
            ans |= (n & 1);
            n >>= 1;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    uint64_t n;
    cin >> n;
    cout << solution.reverseBits(n) << endl;
    return 0;
}
