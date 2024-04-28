#include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
struct Activity{
    int start;
    int finish;
};

// Function to compare activities based on their finish times
int compare(const void *a, const void *b)
{
    return ((struct Activity *)a)->finish - ((struct Activity *)b)->finish;
}

// Function to print the maximum number of activities that can be performed
void printMaxActivities(struct Activity activities[], int n)
{
    // Sort activities based on their finish times
    qsort(activities, n, sizeof(struct Activity), compare);
    printf("Sorted activities:\n");

    for (int i = 0; i < n; i++)
    {
        printf("(%d, %d) ", activities[i].start, activities[i].finish);
    }

    printf("\nThe following activities are selected:\n");

    // The first activity is always selected
    int i = 0;
    printf("(%d, %d) ", activities[i].start, activities[i].finish);

    // Consider rest of the activities
    for (int j = 1; j < n; j++)
    {
        // If this activity has start time greater than or equal to the finish time
        // of previously selected activity, then select it
        if (activities[j].start >= activities[i].finish)
        {
            printf("(%d, %d) ", activities[j].start, activities[j].finish);
            i = j;
        }
    }
}

int main()
{
    // Example activities
    struct Activity activities[] = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
    int n = sizeof(activities) / sizeof(activities[0]);

    // Print the maximum number of activities that can be performed
    printMaxActivities(activities, n);

    return 0;
}
