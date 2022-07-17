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

void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "Empty Tree" << endl;
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    while(!Q.empty())
    {
        Node* current = Q.front();
        cout << current->data << " ";
        if(current->left != NULL)
            Q.push(root->left);
        if(current->right != NULL)
            Q.push(root->right);
        Q.pop();
    }
}
