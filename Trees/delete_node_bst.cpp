#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

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
            return root; // one of the above 2 else ifs will have the correct reference/link with this
        }

    }
}