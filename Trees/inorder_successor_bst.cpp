#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *GetNewNode(int data)
{
    Node *newNode = new (Node);
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *Insert(Node *root, int data)
{
    if (root == NULL)
        root = GetNewNode(data);
    else if (data <= root->data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

Node *FindNode(Node *root, int data)
{
    if (root == NULL)
        return NULL;
    else if (data == root->data)
        return root;
    else if (data <= root->data)
        return FindNode(root->left, data);
    else
        return FindNode(root->right, data);
}

Node *FindMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Function to find INORDER SUCCESSOR
// Takes address of root node and the data of the node for which we have to find the successor
// returns the successor node
Node *GetInorderSuccessor(Node *root, int data)
{
    // Search the node : O(h)
    Node *current = FindNode(root, data);
    if (current == NULL)
        return NULL;

    // Case 1 : Node has right subtree : O(h)
    if (current->right != NULL)
        return FindMin(current->right); // Node with minimum value in right subtree is our successor

    // Case 2 : No right subtree : O(h)
    else
    {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor; // deepest node for which current is in left
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor;
    }
}

