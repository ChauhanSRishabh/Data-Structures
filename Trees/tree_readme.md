# Trees

Array, Linked List, Stack, Queue are all Linear Data Structures.  
In all of these, data is arranged in a sequential manner. 

## Concepts

<img width="1405" alt="Screenshot 2022-07-08 at 11 34 00 PM" src="https://user-images.githubusercontent.com/15028913/178207605-a2391691-809e-417d-bfc1-303789b6cf72.png">

Each arraow in the diagram is a link.  
When we are walking the tree, we can walk in only one direction. 

### Relationships

- **Root node** : The topmost node. Only node without a parent ; Node 1  
- **Prent Node** : Node 1 is parent of nodes 2 and 3.  
- **Children** : 2 and 3 are children of 1  
Node 2 is child of 1 but parent of nodes 4, 5 and 6
- **Sibling** : Children of same parent.
2 and 3 are siblings ; 4, 5 and 6 are siblings ; 7 and 8 are siblings  
- **Leaf Node** : Any node in the tree that does not have a child is called Leaf Node ; 4, 6, 8, 9, 10, 11  
- **Grandparent** : Parent of parent.
1 is grandparent of 4 and 4 is grandchild of 1.
- **Ancestor and Descendant** : If we can go from Node A to B, then A can be called ancestor of B, and B can be called descendant of A.  
1, 2 and 5 are all ancestors of 10 and 10 is descendant of all these nodes.  
Common ancestors of 4 and 9 are 1 and 2
- **Cousins** : 6 and 7 do not have the same parent, but the same grandparent, i.e., 1. Hence 6 and 7 are cousins
- **Uncle** : We can say Node 3 is uncle of 6 as it is sibling of Node 2, the parent of Node 6.

### Properties

#### Tree can be called a recursive data structure.  
We can define tree as a structure that consists of a distinguished node called **root** and some sub-trees and the arrangement is such that the root of the tree contains link to roots of all the sub-trees, T1, T2 and T3.  

<img width="1421" alt="Screenshot 2022-07-11 at 1 21 24 PM" src="https://user-images.githubusercontent.com/15028913/178215267-536161e3-0ce6-42fd-92a2-7bb1119bd201.png">

In the figure above, we have 2 sub-trees for root node(in red), the left subtree in brown and the right subtree in yellow. We can further split the left subtree as such that Node 2 is the root node with 3 subtrees in 3 different colors as shown below. 

<img width="656" alt="Screenshot 2022-07-11 at 3 16 04 PM" src="https://user-images.githubusercontent.com/15028913/178237238-85c6220a-3575-4b4d-8eec-697a132ecd57.png">

#### In a tree with **N nodes**, there will be exactly **N-1 edges**.  
All nodes except the root node will have exactly one incoming edge.

#### **Depth and Height**

<img width="1294" alt="Screenshot 2022-07-08 at 11 38 19 PM" src="https://user-images.githubusercontent.com/15028913/178239217-988dbd44-2438-400b-a611-7b9f109f68bd.png">

**Depth of X**(some node) = Length of the path from root to node X. Each edge in the path from root to X will contribute one unit to the length.  
*It can also be said as no. of edges in path from root to node X*.  
For root node , depth is 0
For Nodes 2 and 3, depth is 1.  
For Nodes 4, 5, 6, 7 and 8, depth is 2.  
For Nodes 9, 10 and 11, depth is 3

<img width="697" alt="Screenshot 2022-07-11 at 3 31 32 PM" src="https://user-images.githubusercontent.com/15028913/178240088-3e6b91b5-6701-4530-9b82-519555fb5f78.png">

**Height of X** = No. of edges in longest path from X to a leaf node.  
Height of Node 3 is 2. Node 8 is also a leaf node but the longest path from node 3 to leaf node is 2.
Height of leaf nodes will be 0.

<img width="697" alt="Screenshot 2022-07-11 at 3 32 10 PM" src="https://user-images.githubusercontent.com/15028913/178240319-123ef26e-44dc-4126-9654-4286befddf10.png">

**Height of Tree** is the height of root node.

*Height and Depth of a node may or may not be same*