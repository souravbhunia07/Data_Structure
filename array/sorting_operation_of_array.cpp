#include <iostream>
using namespace std;

int display(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
}

// Function to check if the array is sorted or not.

auto isSortedArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

// bubble sort algorithm.

auto bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;

    for (i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped = false)
        {
            break;
        }
        
    }
}

// Inserting in a sorted array.

auto insertingElement(int arr[], int n, int key)
{
    int i = n - 1;
    while (arr[i] > key)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = key;
}

// -ve on left side.

auto negativeOnLeftSide(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        while (arr[i] < 0)
        {
            i++;
        }
        while (arr[j] >= 0)
        {
            j--;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
}

auto mergeArray(int arr1[], int arr2[], int arr3[], int n1, int n2)
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr3[k++] = arr1[i++];
        }
        else
        {
            arr3[k++] = arr2[j++];
        }
    }
    for(; i < n1; i++)
    {
        arr3[k++] = arr1[i];
    }
    for (; j < n2; j++)
    {
        arr3[k++] = arr2[j];
    }
}

// Single missing element in sorted array.

// First method:-

auto missingElementFirstMethod(int arr[], int n)
{
    int sum = 0;
    int last = arr[n - 1];
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s = (last*(last + 1))/ 2;

    return s - sum;
}

// Second method:-

auto missingElementSecondMethod(int arr[], int n)
{
    int diff = arr[0] - 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            cout << i + diff << endl;
            break;
        }
    }
}

// Multiple missing element in sorted array.

auto missingMultipleElement(int arr[], int n)
{
    int diff = arr[0] - 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                cout << i + diff << endl;
                diff++;
            }
        }
    }
}

// Maximum element of the array.

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

// Missing element in unsorted array.

auto missingElementUnsorted(int arr[], int n)
{
    int max = maxElement(arr, n);
    int h[max] = {0};
    for (int i = 0; i < n; i++)
    {
        h[arr[i]]++;
    }
    for (int i = 0; i < max; i++)
    {
        if (h[i] == 0)
        {
            cout << i << " ";
        }
        
    }
}

// Finding duplicate in sorted array.

auto duplicateInSortedArray(int arr[], int n)
{
    int lastDuplicate = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
        {
            cout << arr[i] <<" ";
            lastDuplicate = arr[i];
        }
    }
}

// Counting number of duplicate in sorted array.

auto numberOfDuplicateElement(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            j = i + 1;
            while (arr[j] == arr[i])
            {
                j++;
            }
            cout << arr[i] << " is appearing " << j - i << " times " << endl;
        }
    }
}

auto countingUsingHashTable(int arr[], int n)
{
    int max = maxElement(arr, n);
    int h[max] = {0};
    for (int i = 0; i < n; i++)
    {
        h[arr[i]]++;
    }
    for (int i = 1; i <= max; i++)
    {
        if (h[i] > 1)
        {
            cout << i << " " <<  h[i] << endl;
        }
    }
}

// Finding duplicate in unsorted array.

auto duplicateInUnsortedArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        if (arr[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                    arr[j] = -1;
                }
            }
        }
        if (count > 1)
        {
            cout << arr[i] << " " << count << endl;
        }
    }
}

// Find a pair with sum k(a + b = k)

auto sumK(int arr[], int n, int key)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == key)
            {
                cout << arr[i] << " + " << arr[j] << " = " << key << endl;
            }
        }
    }
}

// Find a pair with sum k(a + b = k) for SORTED array.

auto sumKofSortedArray(int arr[], int n, int key)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == key)
        {
            cout << arr[i] << " + " << arr[j] << " = " << key << endl;
            i++;
            j--;
        }
        else if ((arr[i] + arr[j]) < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}

// MAX and MIN in a single scan:-

auto maxAndMin(int arr[], int n)
{
    int max = arr[0], min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        else if(arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "max = " << max << " && " << "min = " << min << endl;
}

int main()
{
    // int n = 10;
    // int arr[100] = {37, 52, 12, 89, 34, 56, 73, 68, 90, 14};

    // bubbleSort(arr, n);

    // display(arr, n);
    // cout << endl;

    // cout << isSortedArray(arr, n) << endl;

    // insertingElement(arr, n, 23);

    // display(arr, n + 1);
    // cout << endl;

    // negativeOnLeftSide(arr, n);

    // display(arr, n);
    // cout << endl;

// Merging array.

    // int arr1[] = {35, 27, 1, 6, 5};

    // int n1 = sizeof(arr1)/sizeof(arr1[0]);

    // int arr2[] = {5, 7, 8, 23, 1, 56, 34, 90};

    // int n2 = sizeof(arr2)/sizeof(arr2[0]);

    // int n = n1 + n2;

    // int arr3[n];

    // mergeArray(arr1, arr2, arr3, n1, n2);

    // display(arr3, n);
    // cout << endl;

// Finding missing number

    // int arr[] = {1,2,3,4,5,7,8,9,10};
    // int n = sizeof(arr)/sizeof(arr[0]);   
    // display(arr, n);
    // cout << endl;

    // cout << missingElementFirstMethod(arr, n) << endl;

    // int arr[] = {4,5,7,8,9,10,11,12,13,14};
    // int n = sizeof(arr)/sizeof(arr[0]);   
    // display(arr, n);
    // cout << endl;

    // missingElementSecondMethod(arr, n);

    // int arr[] = {4,5,7,8,10,13,14,15,16,17};
    // int n = sizeof(arr)/sizeof(arr[0]);   
    // display(arr, n);
    // cout << endl;

    // missingMultipleElement(arr, n);

    int arr[] = {45,25,67,17,10,13,14,15,15,15,16,17};
    int n = sizeof(arr)/sizeof(arr[0]);   
    display(arr, n);
    cout << endl;

    // missingElementUnsorted(arr, n);

    // duplicateInSortedArray(arr, n);

    // numberOfDuplicateElement(arr, n);

    // countingUsingHashTable(arr, n);

    // duplicateInUnsortedArray(arr, n);

    // sumK(arr, n, 30);

    // sumKofSortedArray(arr, n, 30);

    maxAndMin(arr, n);

    return 0;
}