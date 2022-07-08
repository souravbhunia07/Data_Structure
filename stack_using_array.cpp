#include <iostream>
using namespace std;

// structuring the stack containing size, top, array=s.
struct stack 
{
    int size;
    int top;
    int *s;
};

// Initializing stack.

void create(struct stack *st)
{
    cout << "Enter size of stack : ";
    cin >> st->size;
    st->s = new int[st->size];
    st->top = -1;
}

//Function for displaying stack.

void display(struct stack st)
{
    for (int i = st.top; i >= 0; i--)
    {
        cout << st.s[i] << " ";
    }
    cout << endl;
}

// Pushing element in stack.

void push(stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "stack overflow";
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
    
}

// Popping or Deleting element from stack.

int pop(stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "stack underflow";
    }
    else
    {
        x = st->s[st->top];
        st->top--;
    }
    return x;
}

// Peeking element in a stack.

int peek(stack st, int pos) 
{
    int x = -1;
    if ((st.top -pos + 1) < 0)
    {
        cout << "Invalid Position.";
    }
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

// stackTop is used to see the current top element.

int stackTop(stack st)
{
    if (st.top == -1)
    {
        return -1;
    }
    else
    {
        return st.s[st.top];
    }
}

// isEmpty is used to check whether the stack is empty or not.

int isEmpty(stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// isFull is used to check whether the stack is full or not.

int isFull(stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main() 
{
    struct stack st;
    int x;
    create(&st);
    for (int i = 0; i < st.size; i++)
    {   
        cin >> x;
        push(&st, x);
    }
    cout << pop(&st);
    cout << endl;
    display(st);

    return 0;
}