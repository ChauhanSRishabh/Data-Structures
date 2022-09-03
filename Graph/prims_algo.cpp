#include <iostream>
#include <climits>
using namespace std;

#define V 5

int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    cout << "Edge"
         << "  "
         << "Weight" << endl;
    for (int i = 1; i < V; i++)
    {
        cout << parent[i] << "-" << i << "  " << graph[i][parent[i]] << endl;
    }
}

void primsMST(int graph[V][V])
{
    int parent[V];  // Array to store the parent of each node in the constructed MST
    bool mstSet[V]; // Whether vertex is included in MST or not
    int key[V];     // To pick edge with minimum weight

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;  // Set all key values to infinity
        mstSet[i] = false; // Initially, no vertex is included in MST
    }

    key[0] = 0;     // Set key 0 for source vertex(in our case, vertex 0) so that this vertex is picked as first vertex.
    parent[0] = -1; // 0 is the root of MST, has no parent, hence -1

    for (int edges = 0; edges < V - 1; edges++) // MST has V-1 edges
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };
    primsMST(graph);
    return 0;
}