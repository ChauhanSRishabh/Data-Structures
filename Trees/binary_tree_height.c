#include <stdio.h>
#include <stdlib.h>

// HEIGHT OF A BINARY TREE
// No. of edges in longest path from root node to a leaf node
// Height of an empty tree is -1
// Height of tree with one node is 0

struct BTNode
{
    int data;
    struct BTNode *left;  // pointer to left child
    struct BTNode *right; // pointer to right child
};

struct BTNode *GetNewNode(int data)
{
    struct BTNode *newNode = (struct BTNode *)malloc(sizeof(struct BTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// The logic is to count the no. of edges from a particular node to the leaf nodes in it's left and right subtree. Finally adding 1 to whichever is greater would be the height for that node.
// Do this recursively to get the height of the root node and that would be the height of the Binary Tree
int Height(struct BTNode *root)
{
    int lh, rh; // to store the height of left and right subtree respectively

    if (root == NULL) // no node
        return -1;    
        // not returning 0 since we are adding 1 in return statement below and if we return 0 here, then the height of leaf node(OR tree with one node) would be returned as 1, which would be wrong as it should be 0
        // Also, -1 would be the ideal height for an empty Tree. If we return 0, it would mean that it is a tree with one node.

    lh = Height(root->left);
    rh = Height(root->right);

    if (lh > rh)
        return (lh + 1);
    else
        return (rh + 1);
}

int main()
{
    struct BTNode *root = NULL; // Creating an Empty Tree. root is pointer to root node

    // Creating a Binary Tree
    root = GetNewNode(1);

    root->left = GetNewNode(2);
    root->right = GetNewNode(3);
    root->left->left = GetNewNode(4);
    root->left->right = GetNewNode(5);

    if(Height(root) == -1)
        printf("Empty Tree\n");
    else
        printf("Height of the Binary tree is %d\n", Height(root));
}

/*
   DRY RUN

    h(1) = 2(max(1,0) + 1)
    |
    |- h(2) = 1(0+1)
        |- h(4) = 0(-1 + 1)
            |   4->left = NULL lh = -1
            |   4->right = NULL rh = -1
        |- h(5) = 0(-1 + 1)
            |   5->left = NULL lh = -1
            |   5->right = NULL rh = -1
    |- h(3) = 0(-1 + 1)
            |   3->left = NULL lh = -1
            |   3->right = NULL rh = -1

*/