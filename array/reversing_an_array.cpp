#include <iostream>
using namespace std;

int display(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}

// First method using auxilary array.

auto reverseArray(int arr[], int n)
{
    int arr1[100];
    int i, j;
    for (i = n - 1, j = 0; i >= 0; i--, j++)
    {
        arr1[j] = arr[i];
    }
    for ( i = 0; i < n; i++)
    {
        arr[i] = arr1[i];
    }
}

// Second method using swaping.

auto reversingArrayUsingSwapping(int arr[], int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Left shift/rotate of an array

auto leftShift(int arr[], int n)
{
    int x = arr[0];
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = x;
}

// Right shift/rotate of an array.

// auto rightShift(int arr[], int n)
// {
//     int x = arr[n - 1];
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = arr[i + 1];
//     }
//     arr[0] = x;
// }

int main()
{
  
    int arr[100] = {0};
    int x, pos, n = 10;
    for (int i = 0; i < n; ++i)
       {
           arr[i] = i + 1;
       }   
    display(arr, n);
    cout << endl;

    // reverseArray(arr, n);

    // display(arr, n);
    // cout << endl;

    // reversingArrayUsingSwapping(arr, n);

    // display(arr, n);
    // cout << endl;

// Left shift of an array.

    // leftShift(arr, n);

    // display(arr, n);
    // cout << endl;

// Right shift of an array.

    // rightShift(arr, n);

    // display(arr, n);
    // cout << endl;

    return 0;
}