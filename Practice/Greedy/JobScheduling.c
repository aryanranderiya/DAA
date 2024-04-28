#include <stdio.h>
#include <stdlib.h>

struct Job
{
    int id;
    int deadline;
    int profit;
};

// Function to compare jobs based on their profits (used for sorting)
int compare(const void *a, const void *b)
{
    return ((struct Job *)b)->profit - ((struct Job *)a)->profit;
}

// Function to find the maximum profit job schedule using greedy approach
void jobScheduling(struct Job jobs[], int n)
{
    qsort(jobs, n, sizeof(struct Job), compare);

    printf("Sorted: \n");

    for (int i = 0; i < n; i++)
    {
        printf("Job %d, ", jobs[i].id);
    }

    int maxDeadline = 0;
    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    int slots[maxDeadline];               // To keep track of which slot to schedule
    for (int i = 0; i < maxDeadline; i++) // 0, 1, 2, 3 if 4 is thwe maximum deadline
    {
        slots[i] = -1; // Assigning -1 to each element of the array to signify that the slot has not been selected
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (slots[j] == -1) // If it has not been assigned then assign it
            {
                slots[j] = jobs[i].id;
                break;
            }
        }
    }

    printf("\nThe maximum profit job schedule is:\n");
    for (int i = 0; i < maxDeadline; i++)
    {
        if (slots[i] != -1)
        {
            printf("Job %d\n", slots[i]);
        }
    }
}

int main()
{
    struct Job jobs[] = {
        {1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}}; // id, deadline,profit

    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobScheduling(jobs, n);

    return 0;
}
