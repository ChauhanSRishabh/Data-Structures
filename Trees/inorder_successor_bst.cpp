#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *GetNewNode(char data)
{
    Node *newNode = new (Node);
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *Insert(Node *root, int data)
{
    if (root = NULL)
        root = GetNewNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

