#include <stdio.h>
#include <stdlib.h>

// LINKED LIST : DELETE A NODE AT nth POSITION

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int num)
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

