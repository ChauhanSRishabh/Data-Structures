#include <stdio.h>
#include <stdlib.h>

// FINDING MINIMUM AND MAXIMUM ELEMENT IN A BINARY SEARCH TREE
// USING RECURSIVE APPROACH

struct BstNode
{
    int data;
    struct BstNode *left;  // pointer to left child
    struct BstNode *right; // pointer to right child
};

struct BstNode *GetNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BstNode *Insert(struct BstNode *root, int data)
{
    if (root == NULL) // if tree is empty
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

int FindMin(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error : No nodes in BST\n");
        return -1;
    }

    // We known that minimum element in a BST is the leftmost leaf node for the left subtree
    
    else if (root->left == NULL)
        return root->data;
    // Using Recursion to reach the leftmost leaf node in the BST
    return FindMin(root->left);
}


int FindMax(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error : No nodes in BST\n");
        return -1;
    }

    // We known that maximum element in a BST is the rightmost leaf node for the right subtree
    
    else if (root->right == NULL)
        return root->data;
    // Using Recursion to reach the rightmost leaf node in the BST
    return FindMax(root->right);
}

int main()
{
    struct BstNode *root = NULL; // Creating an Empty Tree. root is pointer to root node

    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 99);
    root = Insert(root, 98);
    root = Insert(root, 1);
    root = Insert(root, 12);

    int max = FindMax(root);
    printf("Maximum element is : %d\n", max);
    int min = FindMin(root);
    printf("Minimum element is : %d\n", min);
    return 0;
}