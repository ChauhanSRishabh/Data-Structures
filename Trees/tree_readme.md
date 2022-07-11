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
