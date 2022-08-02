#include <bits/stdc++.h>
using namespace std;

// Inserting element in the array.

int insertElement(int n, int arr[], int pos, int x)
{
    // n++;
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    n++;
}

// Displaying element of the array.

int display(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}

// Deletion of element in the array.

int deleteElement(int arr[], int index, int n)
{
    int x = arr[index];
    for (int i = index; i < n; ++i)
    {
        arr[i] = arr[i + 1];
    }
    n--;
}

// Linear search in array.

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

// Transposition in linear search.

int linearSearchTransposition(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            swap(arr[i], arr[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

// Move to head in linear search.

int linearSearchMoveToHead(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            swap(arr[i], arr[0]);
            return 0;
        }
    }
    return -1;
}

// Binary search in array.

int binarySearch(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            return mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

// Binary search using recursion.

int RbinarySearch(int arr[], int s, int e, int key)
{
    int mid = (s + e)/2;
    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid + 1;
        }
        else if (arr[mid] > key)
        {
            return RbinarySearch(arr, s, mid - 1, key);
        }
        else
        {
            return RbinarySearch(arr, mid + 1, e, key);
        }
    }
    return -1;
}

// Get function for getting value at given index.

int getElement(int arr[], int index, int n)
{
    if (index >= 0 && index < n)
    {
        return arr[index];
    }
    return -1;
}

// Maximum number of the array.

int maxElement(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Minimum number of the array.

int minElement(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

// Sum of all the element of the array.

int sumOfElement(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total;
}

// sum of all the element of the array using recurssion.

int sumUsingRecursion(int arr[], int n)
{
    if (n < 0)
    {
        return 0;
    }
    else
    {
        return sumUsingRecursion(arr, n - 1) + arr[n];
    }
}

// Average sum of the element of array.

int averageSum(int arr[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total/n;
}

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
    // pos = 6;
    // x = 50;
    // insertElement(n, arr, pos, x);
    // display(arr, n + 1);
    // cout << endl;

    // deleteElement(arr, 3, n);
    // display(arr, n);
    // cout << endl;

// Linear search.

    // cout << linearSearch(arr, n, 5) << endl;
    // cout << linearSearchTransposition(arr, n, 50) << endl;
    // cout << linearSearchMoveToHead(arr, n, 9) << endl;

// Binary search.

    // cout << binarySearch(arr, n, 6) << endl;
    // cout << RbinarySearch(arr, 0, 10, 69) << endl;

// Get function.

    // cout << getElement(arr, 5, n) << endl;

// Max function

    // cout << maxElement(arr, n) << endl;

// Min function

    // cout << minElement(arr, n) << endl;

// Total sum of the element

    // cout << sumOfElement(arr, n) << endl;
    // cout << sumUsingRecursion(arr, n) << endl;
    cout << averageSum(arr, n) << endl;

    return 0;
}