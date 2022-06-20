#include <stdio.h>
#include <stdlib.h>

// REVERSE A LINKED LIST THROUGH AN ITERATIVE APPRAOCH

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

// Time Complexity = O(n)
// Space Complexity = O(1)
void ReverseLL()
{
    struct Node *prev, *current, *next; // We need pointers to the current node, previous node and next node

    // To begin with, these 2 lines give an idea of what we are starting with
    current = head;
    prev = NULL;

    // ITERATIVE APPROACH
    while (current != NULL)
    {
        next = current->next; //next points to the next node, i.e, the 2nd node for 1st iteration
        current->next=prev; //alter address of current node to point to the previous node, visualise the reverse linkage
        prev = current; //before next iteration, current becomes previous
        current = next; //Next becomes current
    }
    head = prev; // finally head is pointing to  the previous node, i.e., the last node of our initial LL 
}

int main()
{
    head = NULL;
    InsertEnd(2);
    InsertEnd(4);
    InsertEnd(6);
    InsertEnd(5);
    printf("The initial Linked List is : ");
    Print();
    printf("\n");
    ReverseLL();
    printf("The Linked List after Reversal is is : ");
    Print();
    printf("\n");
    return 0;
}