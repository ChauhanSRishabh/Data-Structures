#include <iostream>
using namespace std;

// QUEUES - ARRAY BASED IMPLEMENTATION

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isFull()
{
    if (rear == MAX_SIZE - 1)
        return true;
    else
        return false;    
}

void displayfront()
{
    cout << queue[front];
}

bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

void Enqueue(int num)
{
    if (isFull()) // when queue is completely full
        return;
    else if (isEmpty()) // when there are no elements, i.e., 1st insertion occurs
    {
        front = 0;
        rear = 0;
    }
    else // when atleast one insertion has already taken place
    {
        rear += 1;
    }    
    queue[rear] = num;
}

void Dequeue()
{
    if (isEmpty()) // when queue is empty
        return;
    else if (front == rear) // when there is just one element inside the queue
    {
        front = -1;
        rear = -1;
    }
    else // more than one element in the queue
    {
        front += 1;
    }        
}

// CIRCULAR ARRAY
/*
Current Position = i
Next Position = (i+1)%N
Previous Position = (i+N-1)%N
*/

void display()
{
    if (rear == -1)
    {
        cout << "Empty queue" << endl;
    }
    else
    {
        cout << "Curent Queue is : ";
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << ' ';
        }
        cout << endl;
    }
}

int main()
{
    Enqueue(1);
    //display();
    Enqueue(4);
    //display();
    Enqueue(5);
    display();
    Dequeue();
    display();
    Enqueue(2);
    display();
    return 0;
}