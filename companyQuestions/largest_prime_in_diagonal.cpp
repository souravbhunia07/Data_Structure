#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {

    for (int i = 2; i * i <= n; i++) {

        if (n % i == 0)
            return false;
    }
    return true;
}

int getLargestPrime(vector<vector<int>> &nums) {
    int row = nums.size();
    int col = nums[0].size();
    // Compute principal Diagonal.
    int i = 0;
    int j = 0;
    int maxPrime = INT_MIN;

    while (i < row && j < col) {

        int p = nums[i++][j++];
        if (isPrime(p)) {
            maxPrime = max(maxPrime, p);
        }
    }
    i = row - 1;
    j = 0;
    // Compute secondary Diagonal.
    while (i >= 0 && j < col) {

        int p = nums[i--][j++];
        if (isPrime(p)) {
            maxPrime = max(maxPrime, p);
        }
    }

    return maxPrime;

}

int main()
{
    vector<vector<int>> t = {
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {7, 8, 9, 6},
        {5, 5, 4, 3}
    };
    cout << getLargestPrime(t);
    return 0;
}
