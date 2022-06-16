#include<stdio.h>
#include<stdlib.h>

//DOUBLY LINKED LIST IMPLEMENTATION

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* GetNewNode(int num)
{
    //local variable
    //will be cleared from memory when function call will finish
    // struct Node myNode;
    // myNode.data = num;
    // myNode.next = NULL;
    // myNode.prev = NULL;
    // We do not want this to happen. 
    //Hence a node is created in Dynamic memory, i.e., Heap as it wll not be cleared from memory unless we explicitly free it.

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //this newNode is local to GetNewNode
    newNode->data = num; //OR write this as (*newNode).data=num;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void Print() 
{
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) 
    {
        printf("%d ", temp->data);
        temp = temp->next;   
    }
    printf("\n");
}

void ReversePrint()
{
    struct Node* temp = head;
    if (temp == NULL) return; // empty list, exit
    // Going to last Node
    while(temp->next != NULL) 
    {
        temp = temp->next;
    }
    // Traversing backward using prev pointer
    printf( "Reverse: ") ;
    while(temp != NULL)
    {
        printf("%d ",temp-›data);
        temp = temp-›prev;
    }
    printf("\n");
}

void InsertAtHead(int num)
{
    struct Node* newNode = GetNewNode(num); //this newNode is local to InsertAtHead
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

int main()
{

}