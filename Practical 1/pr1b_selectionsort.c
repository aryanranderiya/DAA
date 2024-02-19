#include <stdio.h>
#include <conio.h>

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
    int arr[100], min;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Loop for user input for elements of the array
    for (int i = 0; i < n; i++)
    {
        printf("Enter element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++) // Iterate over all the elements once to set the minimum value
    {
        min = i;                    // Set the first element as the minimum
        for (int j = i; j < n; j++) // Loop until j = i -> n
        {
            if (arr[j] < arr[min]) // Compare if any element is smaller than the minimum
            {
                swap(&arr[j], &arr[min]); // If any element is smaller than minimum then swap them
            }
        }
    }

    printf("Elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}