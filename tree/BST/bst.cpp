#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = nullptr;

// Inserting in BST.

void insert(int key)
{
    Node *t = root;
    Node *r = nullptr;
    Node *p;
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = nullptr;
        root = p;
        return;
    }
    while (t != nullptr)
    {
        r = t;
        if (key > t->data)
        {
            t = t->rchild;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = p->rchild = nullptr;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

struct Node * Rinsert(struct Node *p, int key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Rinsert(p->rchild, key);
    }
    return p;
}

// Searching of a key in BST (Iterative version).

struct Node * search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if(key == t->data)
        {
            return t;
        }
        else if (key < t->data)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}

// Deletion of a node in a tree.

// Find height of a tree.

int height(struct Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    return x > y ? x + 1 : y + 1; 
}

// Function for inorder precessor.

struct Node * Inpre(struct Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}

// Function for inorder successor.

struct Node * Insucc(struct Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

struct Node * Delete(struct Node *p, int key)
{
    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (height(p->lchild) > height(p->rchild))
        {
            struct Node *q;
            q = Inpre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            struct Node *q;
            q = Insucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

void inorder(struct Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
    
}

int main()
{
    struct Node *temp;
    // insert(10);
    // insert(8);
    // insert(20);
    // insert(4);
    // insert(30);

    // for Recursive insertion.

    root = Rinsert(root, 10);
    Rinsert(root, 8);
    Rinsert(root, 20);
    Rinsert(root, 4);
    Rinsert(root, 30);

    Delete(root, 4);

    inorder(root);
    cout << endl;
    temp = search(20);
    if (temp != NULL)
    {
        cout << "Element " << temp->data <<" found." << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }
    
    return 0;
}