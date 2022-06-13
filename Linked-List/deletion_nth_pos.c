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
    traverse->next = temp; // Last node is linked with the incoming node
}

void Delete(int pos)
{
    struct Node *temp1 = head;
    if (pos == 1)
    {
        head = temp1->next;
        free(temp1);
        return;
    }
    for (int i = 0; i < pos-2; i++)
    {
        temp1 = temp1->next;
    }
    // temp1 points to (pos-1)th node
    struct Node* temp2 = temp1->next; // temp2 points to the node at position pos
    temp1->next = temp2->next;// (pos-1)th node is linked with (pos+1)th node
    free(temp2); //delete temp2
    
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

int main()
{
    head = NULL; // empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); // List would look like : 2,4,6,5
    printf("The Linked List is : ");
    Print();
    printf("\n");
    int n;
    printf("Enter a position at which deletion is to be done\n");
    scanf("%d", &n);
    Delete(n);
    printf("The Linked List after deletion is : ");
    Print();
    printf("\n");
}