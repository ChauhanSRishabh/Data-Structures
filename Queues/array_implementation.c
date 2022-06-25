
#include <stdio.h>

// QUEUES - ARRAY BASED IMPLEMENTATION

#define MAX_SIZE 10

int A[MAX_SIZE];
int front = -1, rear = -1;

bool isEmpty()
{
    if (front = -1 &&rear = -1)
        return true;
    else
        return false;
}

void Enqueue(int num)
{
    if (isFull())
        return;
    else if (isEmpty())
        front = 0, rear = 0;
    else
        rear += 1;
    A[rear] = num;
}

void Dequeue()
{
    if (isEmpty())
        return;
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front += 1;
}