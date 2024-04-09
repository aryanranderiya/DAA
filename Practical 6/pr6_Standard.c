#include <stdio.h>
#include <conio.h>

void main()
{
    int s, i, j, k;

    printf("Enter the size of matrix : ");
    scanf("%d", &s);

    int res[s][s], mat1[s][s], mat2[s][s];

    // MATRIX 1
    printf("Enter values of matrix 1 : \n");
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            printf("[%d][%d] : ", i, j);
            scanf("%d", &mat1[i][j]);
        }
    }
    // MATRIX 2
    printf("Enter values of matrix 2 : \n");
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            printf("[%d][%d] : ", i, j);
            scanf("%d", &mat2[i][j]);
        }
    }

    for (i = 0; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < s; k++)
            {
                res[i][j] = res[i][j] + (mat1[i][k] * mat2[k][j]);
            }
        }
    }
    for (i = 0; i < s; i++)
    {
        for (j = 0; j < s; j++)
        {
            printf("%d   ", res[i][j]);
        }
        printf("\n");
    }
}
