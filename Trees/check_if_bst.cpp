#include <iostream>

using namespace std;

struct Node
{
    int data;
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

/*                              MOST INEFFICIENT APPROACH

bool IsSubtreeLesser(Node *root, int value) // run-time proportional to no. of nodes in subtree
{
    if (root == NULL)
        return true;

    if (root->data <= value && IsSubtreeLesser(root->left, value) && IsSubtreeLesser(root->right, value))
        return true;
    else
        return false;
}

bool IsSubtreeGreater(Node *root, int value) // run-time proportional to no. of nodes in subtree
{

    if (root == NULL)
        return true;

    if (root->data > value && IsSubtreeGreater(root->left, value) && IsSubtreeGreater(root->right, value))
        return true;
    else
        return false;
}

bool IsBinarySearchTree(Node *root)
{
    if (root == NULL)
        return true;

    if (IsSubtreeLesser(root->left, root->data) && IsSubtreeGreater(root->right, root->data) && IsBinarySearchTree(root->left) && IsBinarySearchTree(root->right))
        return true;
    else
        return false;
}
*/

/*
        PROBLEM WITH THE ABOVE APPROACH

Time Complexity : O(n²)

It has too many function calls, not at all efficient
Functions IsSubtreeLesser() and IsSubtreeGreater() are very expensive
There occurs a lot of traversal
Data in nodes is read and compared multiple times
For each node, we are looking at all the nodes in it's subtrees
*/

/*                                  EFFICIENT APPROACH

The logic is simple.
Starting with the root node, it's value must be in the range {-∞, +∞}
For it's left child, value should be in the range {-∞, value at parent node}
For it's right child, value should be in the range {value at parent node + 1, +∞}
proceed lly for all the nodes

In the recursion, we go to each node once and at each node, we take constant time to see whether data in that node is in a defined range or not.

Time Complexity will be O(n), n being the no. of nodes

*/

bool IsBSTDriverFunc(Node *root, int minValue, int maxValue)
{
    if (root == NULL)
        return true;

    if (root->data > minValue && root->data <= maxValue && IsBSTDriverFunc(root->left, minValue, root->data) && IsBSTDriverFunc(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

bool IsBinarySearchTree(Node *root)
{
    return IsBSTDriverFunc(root, INT_MIN, INT_MAX);
}

int main()
{
    /*
        Code To Test the logic
        Creating an example tree

                 7
               /   \
              4     9
             / \   / \
            1   6 8   11
                 / 
                8
    */

    Node *root = GetNewNode(7);
    root->left = GetNewNode(4);
    root->right = GetNewNode(9);
    root->left->left = GetNewNode(1);
    root->left->right = GetNewNode(6);
    root->right->left = GetNewNode(8);
    root->right->right = GetNewNode(11);
    root->right->left->left = GetNewNode(8);
    
    IsBinarySearchTree(root) ? cout << "Given tree is a BST" : cout << "Give tree is not a BST";
    return 0;
}

/*
                            <climits> (limits.h)

INT_MIN	    Minimum value for an object of type int	-32767 (-215+1) or less*
INT_MAX	    Maximum value for an object of type int	32767 (215-1) or greater*

UINT_MAX	Maximum value for an object of type unsigned int	65535 (216-1) or greater*

LONG_MIN	Minimum value for an object of type long int	-2147483647 (-231+1) or less*
LONG_MAX	Maximum value for an object of type long int	2147483647 (231-1) or greater*

ULONG_MAX	Maximum value for an object of type unsigned long int	4294967295 (232-1) or greater*

LLONG_MIN	Minimum value for an object of type long long int	-9223372036854775807 (-263+1) or less*
LLONG_MAX	Maximum value for an object of type long long int	9223372036854775807 (263-1) or greater*

ULLONG_MAX	Maximum value for an object of type unsigned long long int	18446744073709551615 (264-1) or greater*

*/