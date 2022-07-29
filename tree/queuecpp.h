#ifndef queuecpp_h
#define queuecpp_h
#include <iostream>
using namespace std;

class Node
{
    public:
        Node *lchild;
        int data;
        Node *rchild;
};

class queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    queue(){front = rear = -1; size = 10; Q = new Node*[size];}
    queue(int size){front = rear = -1; this->size = size; Q = new Node*[this->size];}
    void enqueue(Node *x);
    Node* dequeue();
    void display();
    int isEmpty() {return front == rear;}
};

// Enqueue or inserting element in queue.

void queue :: enqueue(Node *x)
{
    if (rear == size - 1)
    {
        cout << "Queue is full";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

// Dequeue or deleting element from queue.

Node* queue :: dequeue()
{
    Node *x = NULL;
    if (front == rear)
    {
        cout << "Queue is Empty";
    }
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}


#endif