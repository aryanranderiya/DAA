#include <stdio.h>
#include <stdlib.h>

// Function to merge two subarrays of arr[]
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Merge the temporary arrays back into arr[l..r]
    while (i < n1 && j < n2)
    {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    // Copy the remaining elements from L[] if any
    while (i < n1)
        arr[k++] = L[i++];

    // Copy the remaining elements from R[] if any
    while (j < n2)
        arr[k++] = R[j++];
}

// Main function that sorts arr[l..r] using merge()
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int arr_size;
    int arr[100];
    int i;

    // Input array size from user
    printf("Enter array size : ");
    scanf("%d", &arr_size);

    // Input array elements from user
    for (i = 0; i < arr_size; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Given array is \n");
    printArray(arr, arr_size);

    // Sort the array using merge sort
    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
