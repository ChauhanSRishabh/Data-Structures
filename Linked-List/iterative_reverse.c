#include <stdio.h>
#include <stdlib.h>

//REVERSE A LINKED LIST THROUGH AN ITERATIVE APPRAOCH

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void InsertEnd(int num)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = num;
    temp->next = NULL;
    
    if (head == NULL)
    {
        temp->next = head;
        head = temp;
        return;
    }

    struct Node *traverse = head;
    while (traverse->next != NULL)
    {
        traverse = traverse->next;
    }
    traverse->next = temp;
}

void Print()
{
    struct Node *temp = head;
    while (temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Basic logic of the ReverseLL function is to alter the address, i.e., the next field of each node and the head pointer in such a way that the order is reversed.
void ReverseLL()
{
    struct Node *prev, *current, *next; // We need pointers to the current node, previous node and next node

    //to begin with
    current = head;
    prev = NULL;
    

}