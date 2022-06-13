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

void delete(int pos)
{

}


void Print()
{
    struct Node *temp2 = head;
    while (temp2 != NULL) 
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
}

int main()
{
    head = NULL; // empty list
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5); //List would look like : 2,4,6,5
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