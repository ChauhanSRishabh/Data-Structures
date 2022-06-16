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

struct Node* head;

void Reverse(struct Node* p)
{
    //This block serves as our exit condition
    if(p->next == NULL)
    {
        head = p; //We want head to point to the last node for Reverse
        return;
    }
    //Will make Reverse call till we reach the Last Node, i.e., the node with p->next = NULL
    Reverse(p->next);
    struct Node* q = p->next; //q points to node after p
    q->next = p; //make q point to p; reverse linkage
    p->next = NULL; //make p point to nothing, as ultimately our first node will point to NULL after we've reversed the entire LL
}

