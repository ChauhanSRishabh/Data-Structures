#include <stdio.h>
#include <stdlib.h>

// PROGRAM FOR INSERTION IN A LINKED LIST AT nth POSITION

typedef int* intPointer;
// created a datatype of type int* 
// easy to declare pointer varaibles

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head;

void Insert(int num, int pos)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = NULL;
    // Node to be inserted has been created. 
    // Has the value num and currently points to no valid memory location

    if (pos == 1)
    {
        temp->next = head; //temp points to what head was pointing to
        head = temp; // head points to temp
        return;
    }

    struct Node *temp1 = head;
    // we need a pointer to traverse the list to the point just before the point of insertion
    // we used a temporary variable and not head as we didn't want to lose our head pointer

    for (int i = 0; i < pos - 2; i++) // for loop will take us to the Node that precedes the position of insertion
    {
        temp1 = temp1->next;
    }
    // New Linkages are made
    temp->next = temp1->next; // Incoming Node points to what preceding Node is pointing to
    temp1->next = temp; // Preceding Node points to the Incoming Node
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
    head = NULL; // List is empty to begin with
    
    printf("The Linked List is currently Empty. Enter the number and position of insertion in the order -> num pos\n");
    printf("For 1st input, pos must be 1, i.e., input should look like -> num 1. Afetr that it is the user's choice\n");

    //AREA FOR IMPROVEMENT
    
    while (1)
    {
        intPointer num, pos;
        num = (int*)malloc(sizeof(int));
        pos = (int*)malloc(sizeof(int));
        // making use of dynamic memory allocation
        // It will also enable us to free the memory once we're done with our work
        
        printf("Press I for insertion and Q to quit\n");
        
        fflush(stdin);
        //fflush() is used to avoid our scanf() getting skipped due to an already presnt '/n' from previous inputs.
        // This happens when we press Enter after our input.
        // When we hit Enter, the newline character comes in the input buffer and when you read scanf() from stdin, it treats “\n”(one that is in stdin because we pressed Enter) as the data you have entered and it appears that the scanf() was skipped

        char choice;
        scanf("%c", &choice);
        if (choice == 'Q')
        {
            break;
        }
        printf("Enter the number and position of insertion\n");
        scanf("%d %d", num, pos);
        Insert(*num, *pos);
        printf("The list is : ");
        Print();
        printf("\n");
        
        free(num);
        free(pos);
        //memory that was earlier allocated dynamically is ultimately freed at the end of each iteration
    }
    return 0;
}