#include<stdio.h>
#include<stdlib.h>

//STACK - ARRAY BASED IMPLEMENTATION

#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if(top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    A[++top] = x;
}


