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

void InsertAtHead(int num)
{
    //local variable
    //will be cleared from memory when function call will finish
    // struct Node myNode;
    // myNode.data = num;
    // myNode.next = NULL;
    // myNode.prev = NULL;
    // We do not want this to happen. 
    //Hence a node is created in Dynamic memory, i.e., Heap as it wll not be cleared from memory unless we explicitly free it.

}

int main()
{

}