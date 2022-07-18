#include <iostream>

using namespace std;

struct Node
{
    int data;
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

bool IsSubtreeLesser(Node *root, int value) // run-time proportional to no. of nodes in subtree
{
    if (root == NULL)
        return true;

    if (root->data <= value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool IsSubtreeGreater(Node *root, int value) // run-time proportional to no. of nodes in subtree
{

    if (root == NULL)
        return true;

    if (root->data > value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}

bool IsBinarySearchTree(Node *root)
{
    if (root == NULL)
        return true;

    if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
        return true;
    else
        return false;
}

int main()
{
    /*
        Code To Test the logic
        Creating an example tree

                 7
               /   \
              4     9
             / \
            1   6
    */

    Node *root = GetNewNode(7);
    root->left = GetNewNode(4);
    root->right = GetNewNode(9);
    root->left->left = GetNewNode(1);
    root->left->right = GetNewNode(6);

    IsBinarySearchTree(root) ? cout << "Given tree is a BST" : cout << "Give tree is not a BST";
    return 0;
}