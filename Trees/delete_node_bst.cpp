#include <iostream>

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

// Function to Insert Node in a Binary Search Tree
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

Node *FindMin(Node *root)
{
    // We known that minimum element in a BST is the leftmost leaf node
    // Using Iteration to reach the leftmost leaf node in the BST
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node *Delete(Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else // When we find the node that is to be deleted
    {
        // Case 1 : No Child
        if (root->left == NULL && root->right == NULL)
        {
            delete root; // delete is an operator in C++ used to deallocate memory of an object in Heap. In C, we'd have used free function
            root = NULL; // memory was deallocated but root still has it's address
        }

        // Case 2 : One Child
        else if (root->left == NULL) // Only right child
        {
            Node *temp = root;  // store the address of node to be deleted in temporary variable
            root = root->right; // points to right child
            delete temp;        // deallocate memory
        }
        else if (root->right == NULL) // Only left child
        {
            Node *temp = root; // store the address of node to be deleted in temporary variable
            root = root->left; // points to left child
            delete temp;       // deallocate memory
        }

        // Case 3 : 2 children
        else
        {
            Node *temp = FindMin(root->right); // OR FindMax(root->left)
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void Inorder(Node *root)
{
    if (root == NULL)
        return;
    Inorder(root->left);       // visit left subtree
    cout << root->data << " "; // print data
    Inorder(root->right);      // visit right subtree
}
