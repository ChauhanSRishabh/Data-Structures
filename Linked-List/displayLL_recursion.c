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

void Display_Reverse_Order(struct Node* p)
{
    if(p==NULL) //This will serve as our exit condition
    {
        return;
    }
    Display_Reverse_Order(p->next);
    printf("%d ", p->data);
}

int main()
{
    struct Node* head = NULL;
    head = InsertEnd(head, 2);
    head = InsertEnd(head, 4);
    head = InsertEnd(head, 6);
    head = InsertEnd(head, 5);
    head = InsertEnd(head, 1);
    head = InsertEnd(head, 3);
    head = InsertEnd(head, 7);
    printf("The Linked List is : ");
    Display(head);
    printf("\n");
    printf("The Linked List in Reverse Order is : ");
    Display_Reverse_Order(head);
    printf("\n");
    return 0;
}

/*
IMPORTANT

For a 'Normal Print', Iterative Approach will be a lot more efficient than the Recursive Approach
Why? Because in Iterative approach, we use just one temporary variable while in Recursive approach, we will use space is the Stack section of the memory for so many function calls, there is implicit use of memory.

For a 'Reverse Print' operation, we will anyway have to store elements in some structure, so if we use Recursion, it's still OK. 
*/