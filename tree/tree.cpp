#include<iostream>
#include "queue.h"
#include "stack.h"
using namespace std;

struct Node *root = NULL;
 
 void treeCreate()
 {
    Node *p, *t;
    int x;
    queue q;
    create(&q, 100);
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = 0;
    circEnqueue(&q, root);
    while (!isEmpty(q))
    {
        p = circDequeue(&q);
        cout << "Enter left child " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->lchild = t;
            circEnqueue(&q, t);
        }
        cout << "Enter right child " << p->data << " : ";
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = 0;
            p->rchild = t;
            circEnqueue(&q, t);
        }
    }
    
 }

// using recursive function.

void preOrder(Node *p)
{
    if (p)
    {
        cout << p->data;
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}

void postOrder(Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data;
    }
}

void inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout << p->data;
        inOrder(p->rchild);
    }
}

// using Iterative method.

void IpreOrder(Node *p)
{
    struct stack stk;
    stackCreate(&stk, 100);
    
    while (p || !stackIsEmpty(stk))
    {
        if (p)
        {
            cout << p->data << " ";
            stackPush(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = stackPop(&stk);
            p = p->rchild;
        }
    }
}

void IinOrder(Node *p)
{
    struct stack stk;
    stackCreate(&stk, 100);

    while (p || !stackIsEmpty(stk))
    {
        if (p)
        {
            stackPush(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = stackPop(&stk);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

// Function for level order.

void levelOrder(struct Node *p)
{
    struct queue q;
    create(&q, 100);
    cout << p->data << " ";
    circEnqueue(&q, p);

    while (!isEmpty(q))
    {
        p = circDequeue(&q);
        if (p->lchild)
        {
            cout << p->lchild->data << " ";
            circEnqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << " ";
            circEnqueue(&q, p->rchild);
        }
    }
}

int count(Node *p)
{
    if (p)
    {
        return count(p->lchild) + count(p->rchild) + 1;
    }
    return 0;
}

// counting leaf node(degree = 0) and non-leaf node.

int leafNode(Node *p)
{
    if (p == NULL)
    {
        return 0;
    }
    if (p->lchild && p->rchild)
    {
        return leafNode(p->lchild) + leafNode(p->rchild) + 1;
    }
    
    return leafNode(p->lchild) + leafNode(p->rchild);
}

int height(Node *p)
{
    int x = 0,  y = 0;
    if (p == 0)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int main()
{
    
    treeCreate();
    
    cout << leafNode(root);

    return 0;
}