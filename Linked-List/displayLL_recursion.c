#include <stdio.h>
#include <stdlib.h>

// PRINT A LINKED LIST USING RECURSION

struct Node
{
    int data;
    struct Node *next;
};

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

// This was our function to display contents of LL using iterative Approach
/*
void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
*/