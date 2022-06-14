#include <stdio.h>
#include <stdlib.h>

// PRINT A LINKED LIST USING RECURSION

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

void Display(struct Node* p) //we can use head instead of p as well, just remember that the scope of this variable is limited to this function
{
    if(p==NULL) //This will serve as our exit condition
    {
        return;
    }
    printf("%d ", p->data);
    Display(p->next);
}

int main()
{
    struct Node* head = NULL;
    head = InsertEnd(head, 2);
    head = InsertEnd(head, 4);
    head = InsertEnd(head, 6);
    head = InsertEnd(head, 5);
    printf("The Linked List is : ");
    Display(head);
    printf("\n");
    return 0;
}