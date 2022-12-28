#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int s, int e) 
{
    int pivot = arr[e];
    int i = s - 1;

    for(int j = s; j < e; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[e]);
    return i + 1;
}

void quickSort(vector<int> &arr, int s, int e)
{
    // Base Condition
    if(s >= e)
    {
        return;
    }

    // Recursive case
    int p = partition(arr, s, e);    // Helps to partion the arr acc. to pivot
    quickSort(arr, s, p - 1);   // Left Side
    quickSort(arr, p + 1, e);    // Right side
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    cout << arr.size() << endl;
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for(auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
