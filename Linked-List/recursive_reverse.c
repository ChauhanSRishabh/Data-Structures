#include <stdio.h>
#include <stdlib.h>

// REVERSE A LINKED LIST THROUGH A RECURSIVE APPRAOCH

struct Node
{
    int data;
    struct Node *next;
};

struct Node* InsertEnd(struct Node *head, int num)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node *));
    temp->data = num;
    temp->next = NULL;

    if (head == NULL)
    {
        temp->next = head;
        head = temp;
        return head;
    }

    struct Node *traverse = head;
    while (traverse->next != NULL)
    {
        traverse = traverse->next;
    }
    traverse->next = temp;
    return head;
}

void Reverse(struct Node* p)
{
    
}