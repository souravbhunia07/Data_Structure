#include "queue.h"
#ifndef stack_h
#define stack_h

// structuring the stack containing size, top, array=s.
struct stack 
{
    int size;
    int top;
    struct Node **s;
};

// Initializing stack.

void stackCreate(struct stack *st, int size)
{
    st->size = size;
    st->top = -1;
    st->s = new Node*[st->size];
}

// Pushing element in stack.

void stackPush(stack *st, struct Node *x)
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

struct Node *stackPop(struct stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        cout << "stack underflow";
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

// isEmpty is used to check whether the stack is empty or not.

int stackIsEmpty(stack st)
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

int stackIsFull(stack st)
{
    return st.top == st.size - 1;
}

#endif