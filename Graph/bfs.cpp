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

int visited[V] = {0, 0, 0, 0, 0, 0, 0};
int graph[V][V] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

// BREADTH FIRST SEARCH
void BFS(int i)
{
    cout << i;
    visited[i] = 1;
    
    queue<int> explorationQueue;
    explorationQueue.push(i);
    while (!explorationQueue.empty())
    {
        int node = explorationQueue.front();
        explorationQueue.pop();
        for (int j = 0; j < V; j++)
        {
            if (graph[node][j] == 1 && visited[j] == 0) // edge exists to a node  and the node is unvisited
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
    BFS(4); // pass the node you want BFS to begin from
    return 0;
}