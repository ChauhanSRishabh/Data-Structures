#include <stdio.h>
#include <stdlib.h>

// STACK - LINKED LIST BASED IMPLEMENTATION
// to implement a stack using LL, we basically have to insert and delete elements at the top/head

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

struct Node* GetNewNode(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void Push(int x)
{
    struct Node* newNode = GetNewNode(x);
    newNode->next = top;
    top = newNode;
}

void Pop()
{
    if(top == NULL)
    {
        printf("Error : Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    top = temp->next;
    free(temp);
}

void Print()
{
    struct Node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}


int main()
{
    Push(2);
    Push(3);
    Push(5);
    Pop();
    Push(7);
    printf("Stack : ");
    Print();
    printf("\n");
}