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

// DEPTH-FIRST STRATEGY
// Postorder Traversal
void Postorder(Node *root)
{
    if (root == NULL)
        return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    /*Code To Test the logic
      Creating an example tree
                 F
               /   \
              D     J
             / \   / \
            B   E G   K
           / \     \
          A   C     I
                   /
                  H 
    */

    Node *root = GetNewNode('F');
    root->left = GetNewNode('D');
    root->right = GetNewNode('J');
    root->left->left = GetNewNode('B');
    root->left->right = GetNewNode('E');
    root->right->left = GetNewNode('G');
    root->right->right = GetNewNode('K');
    root->left->left->left = GetNewNode('A');
    root->left->left->right = GetNewNode('C');
    root->right->left->right = GetNewNode('I');
    root->right->left->right->left = GetNewNode('H');

    Postorder(root);
    return 0;
}