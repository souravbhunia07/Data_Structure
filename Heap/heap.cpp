#include <iostream>
using namespace std;

// Function for inserting value in heap.

void InsertHeap(int h[], int n)
{
    int temp, i = n;
    temp = h[i];

    while (i > 1 && temp > h[i/2])
    {
        h[i] = h[i/2];
        i = i/2;
    }
    h[i] = temp;
}

// Function for deleting element in heap.

int deleteHeap(int a[], int n)
{
    int i, j, x, val;
    val = a[1];
    x = a[n];
    a[1] = a[n];
    a[n] = val;
    i = 1;
    j = i * 2;

    while (j < n - 1)
    {
        if (a[j + 1] > a[j])
        {
            j += 1;
        }
        if (a[i] < a[j])
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i = j;
            j = 2 * j;
        }
        else
        {
            break;
        }
    }
    return val;
}

int main()
{
    int h[] = {0, 10, 20, 30, 25, 5, 40, 35};
    int i;

    for (i = 2; i <= 7; i++)
    {
        InsertHeap(h, i);
    }

    // cout << "Deleted value is " << deleteHeap(h, 7) << endl; //(root, heap size)
    // cout << "Deleted value is " << deleteHeap(h, 6) << endl; 
    
    for (i = 1; i <= 7; i++)
    {
        cout << h[i] << " ";
    }
    cout << endl;
    
    for (i = 7; i >= 1; i--)
    {
        cout << deleteHeap(h, i) << " ";
    }
    cout << endl;
    
    return 0;
}