#include <bits/stdc++.h>
using namespace std;

unsigned Divide(unsigned x, unsigned y)
{
    // Initialize the result to store the quotient
    unsigned result = 0;

    // Initialize the power to 32 (assuming 32-bit integers)
    int power = 32;

    // Convert 'y' to an unsigned long long and left shift it by 'power'
    // to prepare for comparison with 'x'.
    unsigned long long y_power = static_cast<unsigned long long>(y) << power;

    // Loop until 'x' is greater than or equal to 'y'
    while(x >= y)
    {
        // While the power of 'y' is greater than 'x',
        // right shift 'y_power' and decrement 'power'.
        while(y_power > x)
        {
            y_power >>= 1;
            --power;
        }

        // Add 2^power to the result.
        result += 1u << power;

        // Subtract 'y_power' from 'x'.
        x -= y_power;
    }

    // Return the quotient.
    return result;
}

int main()
{
    // Declare variables to store input values.
    unsigned x, y;

    // Read input values for 'x' and 'y'.
    cin >> x >> y;

    // Call the Divide function and output the result.
    cout << Divide(x, y) << endl;

    return 0;
}
