#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    int height; 
    struct Node *rchild;
} *root = NULL;

// Function for checking height of the nodes.

int nodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

// Function for checking balancing factor of the node(i.e subtraction of total sum of left side node and total sum of right side node.)

int balanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

// Function for LL-rotation.

struct Node *LLrotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }
    
    return pl;
}

// Function for LR-rotation.

struct Node *LRrotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}

// Function for RR-rotation.

struct Node *RRrotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}

// Function for RL-rotation.

struct Node *RLrotation(struct Node *p)
{
    struct Node *pr = p->rchild;
    struct Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if (root == p)
    {
        root = prl;
    }
    
    return prl;
}

// recursive function for inserting node in AVL tree.

struct Node * Rinsert(struct Node *p, int key)
{
    struct Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
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
    p->height = nodeHeight(p);
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
    {
        return LLrotation(p);
    }
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
    {
        return LRrotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1)
    {
        return RRrotation(p);
    }
    else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1)
    {
        return RLrotation(p);
    }
    return p;
}

// Function for displaying the tree.

void display(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        display(p->lchild);
        display(p->rchild);
    }
}

int main()
{
    root = Rinsert(root, 10);
    Rinsert(root, 30);
    Rinsert(root, 20);
    display(root);
    return 0;
}