#include <stdio.h>
#include <stdlib.h>

//INSERTING A NODE AT THE BEGINNING

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head; //globally declared as it is being accessed in our Print and Insert functions and we don't want to pass it as an argument again and again

void Insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = head; //every new node created gets the address of the node before it
    // 1st node gets NULL, as head points to NULL when the 1st insertion takes place
    // subsequent nodes point to the node inserted just before them
    head = temp; //since insertion is done at the beginning, our new node is effectively our head 
}

void Print()
{
    struct Node *temp1 = head;
    while (temp1 != NULL) // If we use (temp1->link != NULL), our first ever inserted value, i.e., value at our last node(sice insertion is done at beginning) will never get printed as the link field of that node is NULL.
    {
        printf("%d ", temp1->data);
        temp1 = temp1->link;
    }
}

int main()
{
    head = NULL; //begin with and empty list
    int x, n;
    printf("How many numbers you'll enter : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter the no.\n");
        scanf("%d", &x);
        Insert(x);
        printf("The list is : ");
        Print();
        printf("\n");
    }
    return 0;
}