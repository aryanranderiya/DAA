#include <stdio.h>

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{

    int n; // The number of elements

    int arr[100], j, pivot;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Loop for user input for elements of the array
    for (int i = 0; i < n; i++)
    {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    //   Insertion Sort
    for (int i = 1; i < n; i++)
    {
        pivot = arr[i]; // Set pivot as the 2nd element and consider the first element sorted
        j = i - 1;

        while (j >= 0 && arr[j] > pivot) // loop from j=i-1 until an element larger than the pivot is found
        {
            arr[j + 1] = arr[j]; // Next element which is the larger (j+1) is assigned the value of the previous
            j = j - 1;           // Decrement the index
        }
        arr[j + 1] = pivot; // The 
    }

    printf("Elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}