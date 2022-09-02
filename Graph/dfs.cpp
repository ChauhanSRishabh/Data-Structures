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

int visited[V] = {0, 0, 0, 0, 0, 0, 0};
int graph[V][V] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

// DEPTH FIRST SEARCH
void DFS(int i)
{
    cout << i;
    visited[i] = 1; 
    for (int  j = 0; j < V; j++)
    {
        if(graph[i][j] == 1 && visited[j] == 0) // i the node we're at. Checking if an edge exists from i to a node that is still not visited
        {
            cout << " ";
            DFS(j);
        }
    }
    
}

int main()
{
    DFS(2); // pass the node you want DFS to begin from
    return 0;
}