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

// BREADTH FIRST SEARCH
void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
        return;
    }
    queue<Node *> Q;
    Q.push(root); // pushing the root node into the queue

    while (!Q.empty()) // while there is atleast one discovered node
    {
        Node *current = Q.front();    // assigning the pointer to node at front of the queue to a temporary pointer
        cout << current->data << " "; // display content of the node
        if (current->left != NULL)    // check to see if it has a left child
            Q.push(current->left);    // push the left child into the queue
        if (current->right != NULL)   // check to see if it has a right child
            Q.push(current->right);   // push the right child into the queue
        Q.pop();                      // remove the element at front
    }
}

int main()
{
    /*Code To Test the logic
      Creating an example tree
                B
               / \
              A   C
             / \
            Z   D

    */
    Node *root = GetNewNode('B');
    root->left = GetNewNode('A');
    root->right = GetNewNode('C');
    root->left->left = GetNewNode('Z');
    root->left->right = GetNewNode('D');

    LevelOrderTraversal(root);
    return 0;
}