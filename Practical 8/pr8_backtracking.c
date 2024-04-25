#include <stdio.h>
#include <conio.h>
int mat[100][100];

// Function to check if a queen can be placed at the given position
int checkQueenSafe(int row, int col, int q)
{
    int i, j;
    // Check if there's a queen in the same row to the left
    for (i = 0; i < col; i++)
    {
        if (mat[row][i])
        {
            return 0; // Not safe
        }
    }
    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (mat[i][j])
        {
            return 0; // Not safe
        }
    }
    // Check lower left diagonal
    for (i = row, j = col; j >= 0 && i < q; i++, j--)
    {
        if (mat[i][j])
        {
            return 0; // Not safe
        }
    }
    return 1; // Safe to place queen at this position
}

// Function to solve N Queens problem recursively
int solveNQueens(int col, int q)
{
    int row;
    if (col >= q)
        return 1; // All queens are placed successfully

    for (row = 0; row < q; row++)
    {
        // Check if queen can be placed in this row and column
        if (checkQueenSafe(row, col, q))
        {
            // Place the queen
            mat[row][col] = 1;

            // Place the other queens recursively
            if (solveNQueens(col + 1, q))
                return 1; // Queens are placed successfully

            // If placing queen in this position doesn't lead to a solution, backtrack
            mat[row][col] = 0;
        }
    }
    return 0; // Solution not found for this configuration
}

// Function to print the solution
void printSolution(int q)
{
    int i, j;
    for (i = 0; i < q; i++)
    {
        for (j = 0; j < q; j++)
        {
            if (mat[i][j] == 1)
            {
                printf("Q "); // Queen is present at this position
            }
            if (mat[i][j] == 0)
            {
                printf("[] "); // Empty position
            }
        }
        printf("\n");
    }
}

int main()
{
    int q, i, j;
    printf("Enter the no. of queens : ");
    scanf("%d", &q);
    mat[q][q];

    // Initialize the matrix with all zeros
    for (i = 0; i < q; i++)
    {
        for (j = 0; j < q; j++)
        {
            mat[i][j] = 0;
        }
    }

    // Solve the N Queens problem
    if (!solveNQueens(0, q))
    {
        printf("Solution does not exist");
    }
    else
    {
        // Print the solution
        printSolution(q);
    }
    return 0;
}
