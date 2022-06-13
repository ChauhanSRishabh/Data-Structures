#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void insert(int n, int pos)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    //Node to be inserted has been created. Has the value n and currently points to no valid memory location

    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
   
    struct node *temp1 = head;
    // we need a pointer to traverse the list ot the point where insertion has to take place
    // we used a temporary variable and not head as we diddn't want to loose our head pointer

    for (int i = 0; i < pos - 2; i++)
    {
        temp1 = temp1->next;
    }
    temp->next = temp1->next;
    temp1->next = temp;
}

void print()
{
    struct node *temp1 = head;
    while (temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
}

int main()
{
    head = NULL;  // List is empty to begin with
    insert(2, 1); // 2
    insert(3, 2); // 2,3
    insert(4, 1); // 4, 2, 3
    insert(5, 2); // 4, 5, 2, 3
    print();
    return 0;
}