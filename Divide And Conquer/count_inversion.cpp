#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int s, int e)
{
    vector<int> temp;
    int i = s;
    int m = (s + e) / 2;
    int j = m + 1;
    int cnt = 0;

    while(i <= m && j <= e)
    {
        if(arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else 
        {
            cnt += (m - i + 1);
            temp.push_back(arr[j]);
            j++;
        }
    }
    // Copy remaining element form the 1st array
    while(i <= m)
    {
        temp.push_back(arr[i++]);
    }
    // Copy remaining element form the 2nd array
    while(j <= e)
    {
        temp.push_back(arr[j++]);
    }
    // Copy back all element from the temp array to original array
    int k = 0;
    for(i = s; i <= e; i++)
    {
        arr[i] = temp[k++];
    }
    return cnt;
}

// Inversion Count function

int inversion_Count(vector<int> &arr, int s, int e)
{
    // Base case
    if(s >= e)
    {
        return 0;
    }
    int mid = (s + e) / 2;
    int c1 = inversion_Count(arr, s, mid);
    int c2 = inversion_Count(arr, mid + 1, e);
    int ci = merge(arr, s, e);
    return c1 + c2 + ci;
}

int main()
{
    vector<int> arr = {0, 5, 2, 3, 1};
    int s = 0;
    int e = arr.size() - 1;
    cout << inversion_Count(arr, s, e);
    cout << endl;
    return 0;
}
