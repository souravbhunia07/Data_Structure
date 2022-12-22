#include <bits/stdc++.h>
using namespace std;

bool divideAmongK(int arr[], int n, int k, int min_coins)
{
    int friends = 0;
    int current_friends = 0;
    int partitions = 0;
    for (int i = 0; i < n; ++i)
    {
        if(current_friends + arr[i] >= min_coins)
        {
            partitions += 1;
            current_friends = 0;
        }
        else
        {
            current_friends += arr[i];
        }
    }
    return partitions >= k;
}

int k_partition(int arr[], int n, int k)
{
    int s = 0, e = 0;
    for (int i = 0; i < n; ++i)
    {
        e += arr[i];
    }
    int ans;
    while(s <= e)
    {
        int mid = (s + e) / 2;
        bool isPossible = divideAmongK(arr, n, k, mid);
        if(isPossible)
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter Number of Element: ";
    cin >> n;
    cout << "Enter array: ";
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "Enter Number of friends: ";
    cin >> k;
    cout << k_partition(arr, n, k) << endl;
    return 0;
}
