#include <iostream>
#include <queue>
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

// BREADTH FIRST SEARCH
// Undirected and non-weighted Graph
void BFS(int visited[], int graph[V][V], int src)
{
    cout << src;
    visited[src] = 1;

    queue<int> explorationQueue;
    explorationQueue.push(src);
    while (!explorationQueue.empty())
    {
        int node = explorationQueue.front();
        explorationQueue.pop();
        for (int j = 0; j < V; j++)
        {
            if (graph[node][j] && visited[j] == 0) // Whether edge exists for a node that is unvisited
            {
                cout << " " << j;
                visited[j] = 1;
                explorationQueue.push(j);
            }
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
    
    BFS(visited, graph, 4); // pass the node you want BFS to begin from along with graph and visited array
    return 0;
}