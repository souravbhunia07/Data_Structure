#include<iostream>
using namespace std;
 
struct Node 
{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = nullptr;

// Creating doubly linked list:-

void Create(int a[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->prev = first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    } 
}

// Displaying doubly linked list:-

void Display(struct Node *p)
{
    while (p)
    {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

// Length of doubly linked list:-

int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}

// Inserting in a doubly linked list:-

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > Length(p))
    {
        return;
    }
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
            t->data = x;
            t->prev = p;
            t->next = p->next;
            if (p->next)
            {
                p->next->prev = t;
            }
            p->next = t;
    }
}

// Deleting from doubly linked list:-

int Delete(struct Node *p, int index)
{
    int x = -1;
    if (index < 0 || index > Length(p))
    {
        return -1;
    }
    if (index == 1)
    {
        first = first->next;
        if (first)
        {
            first->prev = NULL;
        }
        x = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}

// Reversing a doubly linked list:-

void Reverse(struct Node *p) 
{
    struct Node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if (p != NULL && p->next == NULL)
        {
            first = p;
        }
    }
    
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    Create(a, 5);
    Reverse(first);
    Display(first);
    return 0;
}