#include<iostream>
using namespace std;
 
class node
{
    public:
        int data;
        node *next;
};

class stack
{
    private:
        node *top;
    public:
        stack(){top = NULL;}
        void push(int x);
        int pop();
        void display();
};

void stack :: push(int x)
{
    node *t = new node;
    if (t == NULL)
    {
        cout << "stack is full" << endl;
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int stack :: pop()
{
    int x = -1;
    node *t = top;
    if (top == NULL)
    {
        cout << "stack is empty." << endl;
    }
    else
    {
        x = top->data;
        top = top->next;
        delete t;
    }
    return x;
}

void stack :: display()
{
    node *p = top;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int n, m;
    cout << "Enter number of element: ";
    cin >> m;
    stack stk;

    for (int i = 0; i < m; i++)
    {
        cin >> n;
        stk.push(n);
    }

    stk.display();

    cout << stk.pop() << endl;

    stk.display();
    
    return 0;
}