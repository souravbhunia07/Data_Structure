// 5. Compute x X y without arithmetical operators
#include <bits/stdc++.h>
using namespace std;

// TC=O(n^2)

unsigned Add(unsigned a, unsigned b)
{
    // Initialize variables for sum, carry, and bit mask.
    unsigned sum = 0, carryin = 0, k = 1, temp_a = a, temp_b = b;
    
    // Iterate through each bit of a and b.
    while(temp_a || temp_b)
    {
        // Extract the kth bit of a and b.
        unsigned ak = a & k, bk = b & k;
        
        // Calculate carryout for the kth bit.
        unsigned carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
        
        // Calculate sum for the kth bit.
        sum |= (ak ^ bk ^ carryin);
        
        // Update carry for the next iteration.
        carryin = carryout << 1;
        
        // Update bit mask for the next iteration.
        k <<= 1;
        
        // Shift a and b to the right.
        temp_a >>= 1,
        temp_b >>= 1;
    }
    // Return the final sum.
    return sum | carryin;
}

// Function to compute multiplication of two unsigned integers without using arithmetic operators.
unsigned Multiply(unsigned x, unsigned y)
{
    // Initialize the result to 0.
    unsigned sum = 0;
    
    // Iterate through each bit of x.
    while(x)
    {
        // If the current bit of x is 1, add y to the result.
        if(x & 1)
        {
            sum = Add(sum, y);
        }
        // Shift y to the left by 1 bit for the next iteration.
        y <<= 1;
        // Shift x to the right by 1 bit for the next iteration.
        x >>= 1;
    }
    // Return the final result.
    return sum;
}

int main()
{
    // Declare variables for input.
    unsigned x, y;
    // Read input values from standard input.
    cin >> x >> y;
    // Compute the product of x and y using bitwise multiplication.
    cout << Multiply(x, y) << endl;
    
    return 0;
}
