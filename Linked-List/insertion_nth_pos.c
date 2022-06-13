#include <stdio.h>
#include <stdlib.h>

// PROGRAM FOR INSERTION IN A LINKED LIST AT nth POSITION

typedef int* intPointer;
// cretaed a datatype of type int* 
// easy to declare pointer varaibles

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void insert(int num, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = NULL;
    // Node to be inserted has been created. 
    // Has the value n and currently points to no valid memory location

    if (pos == 1)
    {
        temp->next = head; //temp points to what head was pointing to
        head = temp; // head points to temp
        return;
    }

    struct node *temp1 = head;
    // we need a pointer to traverse the list to the point where insertion has to take place
    // we used a temporary variable and not head as we didn't want to lose our head pointer

    for (int i = 0; i < pos - 2; i++) // for loop will take us to the node that precedes the position of insertion
    {
        temp1 = temp1->next;
    }
    // New Linkages are made
    temp->next = temp1->next; // Incoming node points to what preceding node is pointing to
    temp1->next = temp; // Preceding node points to the Incoming node
}

void print()
{
    struct node *temp2 = head;
    // If I use temp or temp1 here, we are destined to have a "Segmentation Fault Error" 
    // These pointers would be pointing to a certain location in the memory after the insert() function is executed 
    // When we change them to point to head inside our print() function, we are destined for disaster
    // It may run successfully for the first few iterations, but it'll definitely give error: SIGSEGV at some point of time

    while (temp2 != NULL)
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
}

int main()
{
    head = NULL; // List is empty to begin with
    
    printf("The Linked List is currently Empty. Enter the number and position of insertion in the order -> num pos\n");
    printf("For 1st input, pos must be 1, i.e., input should look like -> num 1. Afetr that it is the user's choice\n");

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
        insert(*num, *pos);
        printf("The list is : ");
        print();
        printf("\n");
        
        free(num);
        free(pos);
        //memory that was earlier allocated dynamically is ultimately freed at the end of each iteration
    }
    return 0;
}