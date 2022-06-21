#include <iostream>
#include <stack>

using namespace std;
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

//REVERSING LL USING EXPLICIT STACK
void Reverse()
{
    struct Node* temp = head;
    if (head == NULL)
        return;
    
    stack<struct Node*> S; // created a stack of type struct Node* named S
    
    //pushing references/pointers to the nodes in the stack
    while(temp!=NULL)
    {
        S.push(temp);
        temp = temp->next;
    }

    //popping the references and forming linkages
    temp = S.top(); //temp has the last node
    head = temp;    //for reversing, our last node should be our first node
    S.pop(); //move to the next reference in Stack

    while(!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    //After the loop, temp is our last node(the first node of the initial LL)
    temp->next = NULL; //last node points to NULL
}


int main()
{
    head = NULL;
    Insert(2);
    Insert(4);
    Insert(6);
    Insert(5);
    cout<<"The initial Linked List is : ";
    Print();
    cout<<endl;
    
    Reverse();
    cout<<"The Linked List after Reversal using Stack is : ";
    Print();
    cout<<endl;;
    return 0;
}


