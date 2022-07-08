#include<iostream>
using namespace std;

// Structuring stack using Linked List.

struct node
{
    int data;
    struct node *next;
}*top = nullptr;

// Push function for pushing element in linked list.

void push(int x)
{
    node *t = new node;
    if (t == NULL)
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// popping or deleting element from linked list.

int pop()
{
    node *p;
    int x = -1;
    if (top == NULL)
    {
        cout << "stack is empty." << endl;
    }
    else
    {
        p = top;
        top = top->next;
        x = p->data;
        delete p;
    }
    return x;
}

// Displaying the elements of linked list stack.

void display()
{
    node *p;
    p = top;
    while (p != NULL)
    {
        cout << p->data <<" ";
        p = p->next;
    }
    cout << endl;
}
 
int main()
{
    
    int n, m;
    cout << "enter size of the element : ";
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> n;
        push(n);
    }
    
    display();

    cout << pop() << endl;

    display();
    
    return 0;
}