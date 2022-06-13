#include <stdio.h>
#include <stdlib.h>

// INSERTING A NODE AT THE END OF A LINKED LIST

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
    // Node to be inserted has been created. 
    // Has the value num and currently points to no valid memory location

    // This block of code will run for the very first insertion only, as after that Head will point to the starting node
    if (head == NULL)
    {
        temp->next = head;
        head = temp;
        return;
    }

    struct Node *traverse = head; // Pointer to traverse through the Linked List is given it's starting position, i.e., the head
    
    // Block of code to reach the last node
    while (traverse->next != NULL) // We know that the next field of the last node will be pointing to NULL 
    // Notice how we didn't use (traverse != NULL) coz then it would've given us a segmentation fault
    {
        traverse = traverse->next;
    }
    traverse->next = temp; // Last node is linked with the incoming node
    
}

void Print()
{
    struct Node *temp2 = head;
    while (temp2 != NULL) 
    // If we would've used (temp2->next != NULL), the program would not have printed the value at the last node, as the next field for the last node has the value NULL
    //If you still want to use the above condn, then uncomment the printf() statement below 
    // Dry-Run this block of code to understand better
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
    //printf("%d ", temp2->data);
}

int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    printf("The Linked List is : ");
    Print();
    printf("\n");
    return 0;
}