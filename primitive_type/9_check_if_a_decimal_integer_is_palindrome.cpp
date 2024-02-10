#include <bits/stdc++.h>
using namespace std;

// TC = O(n)

// Function to check if an integer is a palindrome
bool IsPalindrome(int x) {
    // If x is negative, it cannot be a palindrome
    if(x < 0)
    {
        return false;
    }

    // Calculate the number of digits in x
    const int num_digits = static_cast<int>(floor(log10(x))) + 1;

    // Calculate a mask to extract the most significant digit (MSD)
    int msd_mask = static_cast<int>(pow(10, num_digits - 1));

    // Iterate through the digits of x
    for(int i = 0; i < (num_digits / 2); i++)
    {
        // Compare the most significant digit (MSD) and the least significant digit (LSD)
        if(x / msd_mask != x % 10)
        {
            return false; // If they are not equal, x is not a palindrome
        }

        // Remove the most significant digit (MSD) and the least significant digit (LSD) from x
        x %= msd_mask; // Remove the most significant digit of x
        x /= 10; // Remove the least significant digit of x

        // Update the MSD mask to consider the next pair of digits
        msd_mask /= 100; // We remove two digits at a time
    }

    // If the loop completes without returning false, x is a palindrome
    return true;
}

// Main function
int main()
{
    // Declare a variable to store the input integer
    int x;

    // Read the input integer from the user
    cin >> x;

    // Call the IsPalindrome function and output the result
    cout << IsPalindrome(x) << endl;

    return 0;
}
