#include <iostream>
#include <stack>

//USING STACK TO REVERSE A LL

/*
REVERSING LL

Recursive Solution (Here we are using IMPLICIT STACK, think of the diagram that will be a result of recursive function calls inside the stack)
Time Complexity = O(n)
Space Complexity = O(n)

Iterative Solution
Time Complexity = O(n)
Space Complexity = O(1)
*/

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head;

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

void Print()
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


//USING EXPLICIT STACK

//pushing references/pointers to the nodes in the stack

