#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e) 
{
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;

    vector<int> temp;

    while(i <= m && j <= e)
    {
        if(arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    // copy remaining elements from first array 
    while(i <= m)
    {
        temp.push_back(arr[i++]);
    }

    // copy remaining elements from second array 
    while(j <= e) {
        temp.push_back(arr[j++]);
    }

    int k = 0;
    for(int idx = s; idx <= e; idx++)
    {
        arr[idx] = temp[k++];
    }
    return;
}

void mergeSort(vector<int> &arr, int s, int e)
{
    // Base Condition
    if(s >= e)
    {
        return;
    }

    // Recursive case
    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    return merge(arr, s, e);
}

int main()
{
    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    int s = 0;
    int e = arr.size() - 1;
    mergeSort(arr, s, e);
    for(int x : arr)
    {
        cout << x << ", ";
    }
    cout << endl;
    return 0;
}
