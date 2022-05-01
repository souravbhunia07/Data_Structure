#include<iostream>
#include<stdlib.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node *next;
}*first = nullptr;

void create(int a[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->data = a[0];
    first->next = nullptr;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = a[i];
        t->next = nullptr;
        last->next = t;
        last = t;
    }
}

void RDisplay(struct Node *p)
{
   if (p != NULL)
   {
       cout<<p->data<<" ";
       RDisplay(p->next);
   }
   
}

int count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}

int RCount(struct Node *p)
{
    if (p != NULL)
    {
        return RCount(p->next)+1;
    }
    else
    {
        return 0;
    }
}

int add(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int Rsum(struct Node *p)
{
    if (p != NULL)
    {
        return Rsum(p->next)+p->data;
    }
    else
    {
        return 0;
    }
}

int max(struct Node *p) 
{
    int m = INT32_MIN;
    while (p)
    {
        if (p->data > m)
        {
            m = p->data;
            p = p->next;
        }
    }
    return m;
}

int Rmax(struct Node *p)
{
    int x = 0;
    if (p == 0)
    {
        return INT32_MIN;
    }
    else
    {
        x = Rmax(p->next);
        return x>p->data?x:p->data;
    }
    
}

Node *search(Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

Node *Rsearch(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    else if(key == p->data)
    {
        return p;
    }
    return Rsearch(p->next, key);
}

Node *move_to_head(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
        q->next = p->next;
        p->next = first;
        first = p;
        return p;
        }
        q = p;
        p = p->next;
    } 
    return NULL;
}

// Inserting in a linked list:-

void insert(struct Node *p, int pos, int element)
{
    struct Node *t;
    if (pos == 0)
    {
        t = new Node;
        t->data = element;
        t->next = first;
        first = t;
    }
    else if(pos > 0)
    {
        p = first;
        for (int i = 0; i < pos - 1 && p; i++)
        {
            p = p->next;
        }
        if (p)
        {
            t = new Node;
            t->data = element;
            t->next = p->next;
            p->next = t;
        }
        
    }
}

// creating a linked list by inserting at last:-

void InsertLast(int x)
{
    struct Node *t;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (first->next != NULL)
        {
            first = first->next;
        }
        first->next = t;
    }
}

// Inserting in a sorted linked List:-

void SortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Deleting linked List:-

int Delete(struct Node *p, int pos)
{
    struct Node *q;
    int x = -1;
    if (pos < 1 || pos > count(p))
    {
        return -1;
    }
    if (pos == 1)
    {
        p = first;
        x = first->data;
        first = first->next;
        delete p;
        return x;
    }
    else
    {
        p = first;
        q = NULL;
        for (int i = 0; i < pos - 1; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}

// Check if Linked List is sorted or not:-

int isSorted(struct Node *p)
{
    int x = INT32_MIN;
    while (p != NULL)
    {
        if (p->data < x)
        {
            return false;
        }
        else
        {
            x = p->data;
            p = p->next;
        }
    }
    return true;
}

// Remove duplicate from sorted Linked List:-

void RemoveDuplicate(struct Node *p)
{
    p = first;
    struct Node *q = first->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

// Reversing a Linked List:-

// Reversing element:-

void reversingElement(struct Node *p)
{
    int i = 0;
    int *a;
    struct Node *q = p;
    a = (int *)malloc(sizeof(int)*count(p));
    while (q != NULL)
    {
        a[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while (q != NULL)
    {
        q->data = a[i];
        q = q->next;
        i--;
    }
}

// Reversing by Links:-

void reversingLink(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Reversing a Linked List using recursion:-

void reversingRecursion(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        reversingRecursion(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

int main()
{
    struct Node *temp;
    int a[] = {10, 20, 30, 40, 50};
    create(a, 5);
    reversingRecursion(NULL, first);
    RDisplay(first);
    return 0;
}