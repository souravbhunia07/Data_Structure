#include <bits/stdc++.h>
using namespace std;

double Power(double x, int y)
{
    // Initialize the result to 1.0
    double result = 1.0;

    // Convert 'y' to a long long variable 'power'
    long long power = y;

    // If 'y' is negative, invert 'x' and make 'power' positive
    if(y < 0)
    {
        power = -power; // Make 'power' positive
        x = 1.0 / x;    // Invert 'x'
    }

    // Loop until 'power' becomes 0
    while(power)
    {
        // If the least significant bit of 'power' is set (i.e., 'power' is odd)
        if(power & 1)
        {
            result *= x; // Multiply 'result' by 'x'
        }

        // Square 'x' and right shift 'power' by 1
        x *= x;
        power >>= 1;
    }

    // Return the final result
    return result;
}

int main()
{
    // Declare variables to store input values
    double x;
    int y;

    // Read input values for 'x' and 'y'
    cin >> x >> y;

    // Call the Power function and output the result
    cout << Power(x, y) << endl;

    return 0;
}
