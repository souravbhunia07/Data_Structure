#include <iostream>
#include "chains.h"
using namespace std;

int Hash(int key)
{
    return key % 10;
}

void Insert(struct Node *H[], int key)
{
    int index = Hash(key);
    SortedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;

    for (i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    temp = search(HT[Hash(12)], 12);

    cout << temp->data << endl;
    
    return 0;
}