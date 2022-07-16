#include<iostream>
using namespace std;
 
class queue
{
private:
    int front;
    int rear;
    int size;
    int *Q;

public:
    void create(int size);
    void enqueue(int x);
    int dequeue();
    void display();
};

// Creating and initialising queue.

void queue :: create(int size)
{
    front = rear = -1;
    this->size = size;
    Q = new int[this->size];
}

// Enqueue or inserting element in queue.

void queue :: enqueue(int x)
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

int queue :: dequeue()
{
    int x = -1;
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

// Displaying element of queue.

void queue :: display()
{
    for (int i = front+1; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    queue q;
    q.create(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << q.dequeue() << endl;
    q.display();
    return 0;
}