#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Edge
{
    int src;
    int des;
    int weight;
};

struct Graph
{
    int v;
    int e;
    struct Edge *edge;
};

struct Subset
{
    int parent;
};

// Function to create a graph with given vertices and edges
struct Graph *createGraph(int ve, int ed)
{
    // Allocate memory for the graph structure
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct
                                                        Graph));
    // Initialize number of vertices and edges
    graph->v = ve;
    graph->e = ed;
    // Allocate memory for the edges array
    graph->edge = (struct Edge *)malloc(graph->e * sizeof(struct
                                                          Edge));
    return graph;
}

// Function to find the subset (or set) of an element i
int find(struct Subset subset[], int i)
{
    // If the parent of element i is not itself, recursively find the parent
    if (subset[i].parent != i)
    {
        subset[i].parent = find(subset, subset[i].parent);
    }
    // Return the parent of element i
    return subset[i].parent;
}

// Function to perform union operation of two subsets
void Union(struct Subset subset[], int x, int y)
{
    // Find the roots of x and y
    int xroot = find(subset, x);
    int yroot = find(subset, y);
    // Attach one tree under the root of another tree
    subset[yroot].parent = xroot;
}

// Kruskal's algorithm to find Minimum Spanning Tree (MST)
void Kruskals(struct Graph *graph)
{
    // Number of vertices and edges in the graph
    int v = graph->v;
    int e = graph->e;
    // Array to store the edges of the MST
    struct Edge result[v];
    // Index to keep track of the edges added to the MST
    int edgeIndex = 0;
    int i, j;

    // Sorting the edges of the graph based on their weights (bubble sort)
    for (i = 0; i < e; i++)
    {
        for (j = 0; j < e - i - 1; j++)
        {
            if (graph->edge[j].weight > graph->edge[j + 1].weight)
            {
                struct Edge temp = graph->edge[j];
                graph->edge[j] = graph->edge[j + 1];
                graph->edge[j + 1] = temp;
            }
        }
    }

    // Allocate memory for the subset array and initialize each subset
    struct Subset *subset = (struct Subset *)malloc(v *
                                                    sizeof(struct Subset));
    for (int vertex = 0; vertex < v; vertex++)
    {
        subset[vertex].parent = vertex;
    }

    // Iterate through all edges of the graph
    for (i = 0; edgeIndex < v - 1 && i < e; i++)
    {
        struct Edge next_edge = graph->edge[i];
        // Find the subsets (or sets) of the source and destination vertices of the edge
        int x = find(subset, next_edge.src);
        int y = find(subset, next_edge.des);
        // If including this edge does not form a cycle, add it to the result
        if (x != y)
        {
            result[edgeIndex++] = next_edge;
            // Perform union operation to merge the subsets of x and y
            Union(subset, x, y);
        }
    }

    // Print the edges of the MST
    printf("Edges in MST\n");
    for (i = 0; i < edgeIndex; ++i)
    {
        printf("%d -- %d = %d\n", result[i].src, result[i].des,
               result[i].weight);
    }
}

// Main function to input graph and find MST using Kruskal's algorithm
void main()
{
    int v, e, i = 0, s, d, w;
    // Input number of vertices and edges of the graph
    printf("Enter the number of vertices : ");
    scanf("%d", &v);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    // Create graph with given number of vertices and edges
    struct Graph *graph = createGraph(v, e);

    // Input each edge of the graph
    for (i = 0; i < e; i++)
    {
        printf("Enter source destination and weight of edge %d : ",
               i);
        scanf("%d%d%d", &s, &d, &w);
        // Store the edge information in the graph
        graph->edge[i].src = s;
        graph->edge[i].weight = w;
        graph->edge[i].des = d;
    }
    // Find Minimum Spanning Tree (MST) using Kruskal's algorithm
    Kruskals(graph);
}