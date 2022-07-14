#include <stdio.h>
#include <stdlib.h>

// BINARY SEARCH TREE

struct BstNode
{
    int data;
    struct BstNode *left;   // pointer to left child
    struct BstNode *right; // pointer to right child
};

struct Node* GetNewNode(int data)
{
    struct BstNode* newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert in BST, returns address of root node
// Uses recursion to insert
struct BstNode* Insert(struct BstNode* root, int data)
{
    if(root == NULL) //if tree is empty
    {
        root = GetNewNode(data);
    }
    else if(data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

// Insertion can also be achieved using temporary pointer to nodes and loops

int main()
{
    struct BstNode *root = NULL; // Creating an Empty Tree. root is pointer to root node

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);

}
