#include <stdio.h>
#include <stdlib.h>

// FINDING MINIMUM AND MAXIMUM ELEMENT IN A BINARY SEARCH TREE
// USING ITERATIVE METHOD

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

void FindMin(struct BstNode *root)
{
    // We are not assigning root to a temporary variable as root being a local variable of main() is passed on to the FindMin() function and changes made here won't affect root unlike the case where root would have been a global variable

    if (root == NULL)
    {
        printf("Error : No nodes in BST\n");
        return;
    }

    // We known that minimum element in a BST is the leftmost leaf node for Left subtree

    // Using Iteration to reach the leftmost leaf node in the BST
    while (root->left != NULL)
        root = root->left;

    printf("Minimum element is : %d\n", root->data);
}

void FindMax(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error : No nodes in BST\n");
        return;
    }

    // We known that maximum element in a BST is the rightmost leaf node for the right subtree

    // Using Iteration to reach the rightmost leaf node in the BST
    while (root->right != NULL)
        root = root->right;

    printf("Maximum element is : %d\n", root->data);
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

    FindMin(root);
    FindMax(root);

    return 0;
}