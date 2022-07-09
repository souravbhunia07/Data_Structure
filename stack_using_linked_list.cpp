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

// Fucntion for checking the element is operand or not.

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

// Function for evaluating the postfix.

int eval(char *postfix)
{
    int i, x1, x2, r;
    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            push(postfix[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                push(r);
                break;
            case '-':
                r = x1 - x2;
                push(r);
                break;
            case '*':
                r = x1 * x2;
                push(r);
                break;
            case '/':
                r = x1 / x2;
                push(r);
                break;
            }
        }
    }
    return pop();
}
 
int main()
{
    char *postfix = "234*+82/-";
    cout << eval(postfix);

    return 0;
}