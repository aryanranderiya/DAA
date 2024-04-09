#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void printMat(int a[][MAX_COLS], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void addMatrix(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen(int A[][MAX_COLS], int B[][MAX_COLS], int C[][MAX_COLS], int size)
{
    if (size == 1)
    { // Base case: Use standard matrix multiplication
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    // Split matrices into submatrices
    int newSize = size / 2;
    int A11[newSize][newSize], A12[newSize][newSize], A21[newSize][newSize], A22[newSize][newSize];
    int B11[newSize][newSize], B12[newSize][newSize], B21[newSize][newSize], B22[newSize][newSize];
    int C11[newSize][newSize], C12[newSize][newSize], C21[newSize][newSize], C22[newSize][newSize];
    int M1[newSize][newSize], M2[newSize][newSize], M3[newSize][newSize], M4[newSize][newSize], M5[newSize][newSize];
    int M6[newSize][newSize], M7[newSize][newSize];
    int temp1[newSize][newSize], temp2[newSize][newSize];

    // Partition input matrices into submatrices
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // Calculate intermediate matrices
    addMatrix(A11, A22, temp1, newSize);
    addMatrix(B11, B22, temp2, newSize);
    strassen(temp1, temp2, M1, newSize);

    addMatrix(A21, A22, temp1, newSize);
    strassen(temp1, B11, M2, newSize);

    subtractMatrix(B12, B22, temp1, newSize);
    strassen(A11, temp1, M3, newSize);

    subtractMatrix(B21, B11, temp1, newSize);
    strassen(A22, temp1, M4, newSize);

    addMatrix(A11, A12, temp1, newSize);
    strassen(temp1, B22, M5, newSize);

    subtractMatrix(A21, A11, temp1, newSize);
    addMatrix(B11, B12, temp2, newSize);
    strassen(temp1, temp2, M6, newSize);

    subtractMatrix(A12, A22, temp1, newSize);
    addMatrix(B21, B22, temp2, newSize);
    strassen(temp1, temp2, M7, newSize);

    // Calculate result submatrices
    addMatrix(M1, M4, temp1, newSize);
    subtractMatrix(temp1, M5, temp2, newSize);
    addMatrix(temp2, M7, C11, newSize);

    addMatrix(M3, M5, C12, newSize);

    addMatrix(M2, M4, C21, newSize);

    addMatrix(M1, M3, temp1, newSize);
    subtractMatrix(temp1, M2, temp2, newSize);
    addMatrix(temp2, M6, C22, newSize);

    // Combine result submatrices into result matrix
    for (int i = 0; i < newSize; i++)
    {
        for (int j = 0; j < newSize; j++)
        {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }
}

int main()
{
    int size;

    printf("Enter the size of the square matrices: ");
    scanf("%d", &size);

    if (size > MAX_ROWS || size <= 0)
    {
        printf("Invalid size\n");
        return 1;
    }

    int A[MAX_ROWS][MAX_COLS], B[MAX_ROWS][MAX_COLS], C[MAX_ROWS][MAX_COLS];

    printf("Enter the elements of Matrix A (%d x %d):\n", size, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter the elements of Matrix B (%d x %d):\n", size, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            scanf("%d", &B[i][j]);
        }
    }

    strassen(A, B, C, size);

    printf("Result Matrix:\n");
    printMat(C, size, size);

    return 0;
}
