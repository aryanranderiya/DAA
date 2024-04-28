#include <stdio.h>
#include <stdlib.h>

// Structure for an item which stores weight and value of item
struct Item
{
    int value;
    int weight;
};

// Function to compare two items according to their value per unit weight
int compare(struct Item *a, struct Item *b)
{
    double ratio1 = (double)(a->value) / (double)(a->weight);
    double ratio2 = (double)(b->value) / (double)(b->weight);
    if (ratio1 < ratio2)
        return 1;
    else if (ratio1 > ratio2)
        return -1;
    else
        return 0;
}

// Function to perform fractional knapsack
double fractionalKnapsack(int W, struct Item arr[], int n)
{
    // Sort items based on their value per unit weight
    qsort(arr, n, sizeof(arr[0]), compare);

    int currentWeight = 0;   // Current weight in knapsack
    double finalValue = 0.0; // Final value of items in knapsack

    // Loop through all items
    for (int i = 0; i < n; i++)
    {
        // If adding item won't overflow, add it completely
        if (currentWeight + arr[i].weight <= W)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        // If we can't add current item, add fractional part of it
        else
        {
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    int W = 50;                                           // Weight capacity of knapsack
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}}; // Array of items {value, weight}
    int n = sizeof(arr) / sizeof(arr[0]);                 // Number of items

    double maxValue = fractionalKnapsack(W, arr, n);
    printf("Maximum value in Knapsack = %.2lf\n", maxValue);

    return 0;
}
