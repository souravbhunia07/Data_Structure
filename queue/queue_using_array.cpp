#include<iostream>
using namespace std;
 
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// Initialising the queue object.

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = new int[q->size];
}

// enqueue or inserting element in queue.

void enqueue(queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

// Dequeue or deleting element in queue.

int dequeue(queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Displaying element of queue.

void display(queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

// Circular queue 

// Insertion of elememt in circular queue

void circEnqueue(queue *q, int x)
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

int circDequeue(queue *q)
{
    int x = -1;
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

// Displaying circular queue.

void display(queue q)
{
    int i = q.front + 1;
    do
    {
        cout << q.Q[i];
        i = (i + 1) % q.size;
    } while (i != ((q.rear + 1) % q.size));
}

int main()
{
    struct queue q;
    create(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);
    display(q);
    cout << dequeue(&q) << endl;
    display(q);
    return 0;
}