#include <stdio.h>
#include <stdlib.h>

// QUEUES - LINKED LIST BASED IMPLEMENTATION
// To implement Queues using LL, we basically have to insert at the end/tail and delete from the head OR vice-versa

/*
PROBLEM W/ NORMAL IMPLEMENTATION OF LL
There is just one requirement with Queue Data Structure, the operations Enqueue, Dequeue, front and isEmpty must take constant time, i.e., O(1)

Cost of insertion/removal in a LL:
at head = O(1)
at end = O(n)

Here's the deal, in a normal implementation of LL, if we insert at one end and remove from the other, then one of these operations, Enqueue or Dequeue, depending on how we are picking sides, will cost us O(n).

We must make sure that both Enqueue and Dequeue operation take constant time.
*/

/*
PROBLEM WITH ARRAY BASED IMPLEMENETATION
(1) We can take a large enough array and use only few block of memory. As a result, we'll be left with unused memory, which is not efficient
(2) Suppose the array gets filled completely and we have to insert another element into it, we will first have to create a new larger array and copy elements from previous array into this larger array which would take time T ∝ n, i.e., O(n)
*/

/*
SOLUTION : We will be inserting at the end and removing from the front and instead of just taking the head pointer, we will take 2 pointers, front and rear, and after each insertion/removal, we will update both the front and rear pointers accordingly.
Now with this design, both Enqueue and Dequeue will be constant-time operations.
*/

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;

    if (front == NULL && rear == NULL) // when Queue is empty, inserting at head of LL, our front
    {
        front = rear = temp;
        return;
    }
    rear->next = temp; // Only runs,when there is atleast one element in the queue, i.e., inserting at the end
    rear = temp;       // Making rear point to the newly inserted node
}

void Dequeue() // Deleting from the front
{
    struct Node *temp = front;
    if (front == NULL) // When Queue is empty
    {
        printf("Queue is empty. Nothing to remove\n");
        return;
    }
    if (front == rear) // When there is just one element in the Queue
    {
        front = rear = NULL;
        return;
    }
    // These lines run only when there are more than one element in the queue
    front = temp->next; // front now points to the next node in the Queue
    free(temp);         // free the memory, i.e., node is wiped off
}

void Print()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    Enqueue(2);
    Enqueue(3);
    Enqueue(5);
    printf("Queue : ");
    Print();
    printf("\n");
    Dequeue();
    printf("Queue : ");
    Print();
    printf("\n");
    Enqueue(7);
    printf("Queue : ");
    Print();
    printf("\n");
}