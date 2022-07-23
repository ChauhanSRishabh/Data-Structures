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

Node *FindMax(Node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Function to find INORDER PREDECESSOR
// Takes address of root node and the data of the node for which we have to find the predecessor
// returns the predecessor node
Node *GetInorderPredecessor(Node *root, int data)
{
    // Search the node : O(h)
    Node *current = FindNode(root, data);
    if (current == NULL)
        return NULL;

    // Case 1 : Node has left subtree : O(h)
    if (current->left != NULL)
        return FindMax(current->left); // Node with minimum value in right subtree is our predecessor

    // Case 2 : No left subtree : O(h)
    else
    {
        Node* predecessor = NULL;
        Node* ancestor = root;
        while(ancestor != current)
        {
            if(current->data > ancestor->data)
            {
                predecessor = ancestor; // deepest node for which current is in right
                ancestor = ancestor->right;
            }
            else
                ancestor = ancestor->left;
        }
        return predecessor;
    }
}

int main()
{
    /*Code To Test the logic
      Creating an example tree
                5
               / \
              3   10
             / \   \
            2   4   11
           /     \
          1       5
    */
    Node *root = NULL;
    root = Insert(root, 5);
    root = Insert(root, 10);
    root = Insert(root, 3);
    root = Insert(root, 4);
    root = Insert(root, 2);
    root = Insert(root, 11);
    root = Insert(root, 5);
    root = Insert(root, 1);

    Node * predecessor = GetInorderPredecessor(root, 3);
    cout << "Inorder predecessor of 3 is : " << predecessor->data << endl;
    predecessor = GetInorderPredecessor(root, 10);
    cout << "Inorder predecessor of 10 is : " << predecessor->data;
}