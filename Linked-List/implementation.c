#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node *head; //globally declared as it is being accessed in our Print and Insert functions and we don't want to pass it as argument again and again

void Insert(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = head; //har naye node ki address field ko NULL bana de rahe hain coze tht is effectively our last node
    head = temp; //ab hamara naya node hi hamara head hai
}

void Print()
{
    struct Node *temp1 = head;
    while (temp1 != NULL) // If we use (temp1->link != NULL), our first ever inserted value, i.e., value at our last node(sice insertion is done at beginning) will never get printed as the link field of that node is NULL.
    // Hence (temp1 != NULL) is used so that
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