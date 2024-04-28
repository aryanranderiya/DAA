#include <stdio.h>

// Number of vertices in the graph
#define V 6
#define INT_MAX 99999999

// Function to find the vertex with minimum distance value
int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (visited[v] == 0 && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[])
{
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

// Function to implement Dijkstra's algorithm for a given graph
void dijkstra(int graph[V][V], int src)
{
    int dist[V];    // The output array. dist[i] will hold the shortest distance from src to i
    int visited[V]; // visited[i] will be true if vertex i is included in the shortest path tree or shortest distance from src to i is finalized
    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visited[i] = 0;
    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = minDistance(dist, visited);
        // Mark the picked vertex as processed
        visited[u] = 1;
        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            // Update dist[v] only if it is not visited, there is an edge from u to v, and total weight of path from src to v through u is smaller than current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    // Print the constructed distance array
    printSolution(dist);
}

// Main function
int main()
{
    // Graph representation using adjacency matrix
    int graph[V][V] = {{0, 4, 0, 0, 0, 0},
                       {4, 0, 8, 0, 0, 0},
                       {0, 8, 0, 7, 0, 4},
                       {0, 0, 7, 0, 9, 14},
                       {0, 0, 0, 9, 0, 10},
                       {0, 0, 4, 14, 10, 0}};
    // Call Dijkstra's algorithm with source vertex 0
    dijkstra(graph, 0);
    return 0;
}
