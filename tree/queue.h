#ifndef queue_h
#define queue_h
#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

// Initialising the queue object.

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new Node*[q->size];
}

void circEnqueue(queue *q, struct Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

// Deletion of object in circular queue.

Node* circDequeue(queue *q)
{
    Node* x = nullptr;
    if (q->front == q->rear)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

// Function for checking if the queue is empty or not.

int isEmpty(struct queue q)
{
    return q.front == q.rear;
}

#endif // queue_h