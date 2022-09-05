#include <iostream>
using namespace std;

#define V 7

//  Graph with 7 vertices
/*

0-------1
| \     |
|   \   |
|     \ |
3-------2
 \     /
    4
   / \
  5   6

*/

// DEPTH FIRST SEARCH
// Undirected and non-weighted Graph
void DFS(int visited[], int graph[V][V], int src)
{
    cout << src;
    visited[src] = 1;
    for (int j = 0; j < V; j++)
    {
        if (graph[src][j] && visited[j] == 0) // src is the node we're at. Checking if an edge exists from src to a node that is still not visited
        {
            cout << " ";
            DFS(visited, graph, j);
        }
    }
}

int main()
{
    int visited[V] = {0, 0, 0, 0, 0, 0, 0}; // Array to keep track of nodes that have been traversed. Initially, we haven't visited any node
    
    // Adjacency matrix representation of Graphs
    int graph[V][V] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    DFS(visited, graph, 2); // pass the node you want DFS to begin from along with graph and visited array
    return 0;
}