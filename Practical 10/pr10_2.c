#include <stdio.h>
int peakentry(int arr[], int size)
{
    int first = 0;
    int last = size - 1;
    while (first < last)
    {
        int mid = (first + last) / 2;
        if (arr[mid] < arr[mid + 1])
        {
            first = mid + 1;
        }
        else
        {
            last = mid;
        }
    }
    return first;
}
int main()
{
    int arrsize;
    printf("Enter your array size: ");
    scanf("%d", &arrsize);
    int arr[arrsize];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < arrsize; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Given array is:\n");
    for (int i = 0; i < arrsize; i++)
    {
        printf("%d\n", arr[i]);
    }
    int peak = peakentry(arr, arrsize);
    printf("Peak element is at index %d with value %d\n", peak, arr[peak]);
    return 0;
}