#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main()
{
    int n, arr[100], i;
    printf("Enter array size: ");
    scanf("%d", &n);

    for (i = 0; i < arr_size; i++)
    {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Unsorted Array\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array in ascending order: \n");
    printArray(arr, n);
}
