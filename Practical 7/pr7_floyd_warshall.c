#include <stdio.h>
#include <stdlib.h>

#define INFINITY 99999999

void printSolution(int V, int dist[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INFINITY)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

// Solves the all-pairs shortest path
// problem using Floyd Warshall algorithm
void floydWarshall(int V, int dist[][V])
{
    int i, j, k;

    //  Add all vertices one by one to
    //   the set of intermediate vertices.
    //   ---> Before start of an iteration, we
    //   have shortest distances between all
    //   pairs of vertices such that the shortest
    //   distances consider only the
    //   vertices in set {0, 1, 2, .. k-1} as
    //   intermediate vertices.
    //   ----> After the end of an iteration,
    //   vertex no. k is added to the set of
    //   intermediate vertices and the set
    //   becomes {0, 1, 2, .. k}
    for (k = 0; k < V; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < V; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    printf("The following matrix shows the shortest distances between every pair of vertices \n");
    printSolution(V, dist);
}

int main()
{
    int V; // Number of vertices
    printf("Enter the number of Vertices:");
    scanf("%d", &V);

    int(*W)[V] = malloc(sizeof(int[V][V])); // Dynamic allocation of 2D array

    int weight;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j)
            {
                int flag = 0;
                printf("Is there a connection between edge %d and %d? (0=No or 1=Yes) No = Infinity \n", i + 1, j + 1);
                scanf("%d", &flag);

                if (flag == 0)
                    W[i][j] = INFINITY;
                else
                {
                    printf("Enter Weight [%d,  %d] : ", i + 1, j + 1);
                    scanf("%d", &weight);
                    W[i][j] = weight;
                }
            }
            else
            {
                W[i][j] = 0;
            }
        }
    }

    printf("The matrix before floyd warshall\n");
    printSolution(V, W);
    floydWarshall(V, W);

    free(W); // Free allocated memory
    return 0;
}