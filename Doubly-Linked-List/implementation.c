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
        printf("%d ",temp->data);
        temp = temp->prev;
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

void InsertAtTail(int num)
{
    struct Node* newNode = GetNewNode(num);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    struct Node* traverse = head;
    while(traverse->next != NULL)
    {
        traverse = traverse->next;
    }
    //traverse points to the last node;
    traverse->next = newNode;
    newNode->prev = traverse;
}

int main()
{
    head = NULL;
    InsertAtHead(2); //Print(); ReversePrint();
    InsertAtHead(4); //Print(); ReversePrint();
    InsertAtHead(6); //Print(); ReversePrint();
    printf("DLL after Insertion at Head/Beginning : ");
    Print();
    printf("Same DLL in Reverse Order : ");
    ReversePrint();
    
    //head = NULL; uncomment this if you don't want to see 2,4,6 with 3,5,7
    
    InsertAtTail(3);
    InsertAtTail(5);
    InsertAtTail(7);
    printf("DLL after Insertion at End/Tail : ");
    Print();
    printf("Same DLL in Reverse Order : ");
    ReversePrint();
    return 0;
}