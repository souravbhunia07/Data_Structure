#include<iostream>
#include<string.h>
using namespace std;

// Structuring stack using Linked List.

struct node
{
    char data;
    struct node *next;
}*top = nullptr;

// Push function for pushing element in linked list.

void push(char x)
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

char pop()
{
    node *p;
    char x = -1;
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

// Paranthesis Matching

int isBalance(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == NULL)
            {
                return 0;
            }
            else
            {
                pop();
            }
        }
    }
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// operand and precedence function

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

int pre(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

// Converting infix to postfix 

char * convert(char *infix)
{
    int i = 0, j = 0;
    char *postfix = new char[strlen(infix) + 1];
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (pre(infix[i]) > pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
        while (top != NULL)
        {
            postfix[j++] = pop();
        }
        postfix[j] = '\0';
        return postfix;
    }
    
}

 
int main()
{
    char *infix = "a+b*c";
    push('#');
    char *postfix = convert(infix);
    cout << postfix;
    return 0;
}