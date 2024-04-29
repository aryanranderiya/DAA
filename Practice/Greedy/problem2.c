#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to find the maximum profit
int maxProfit(int prices[], int n)
{
    int totalProfit = 0;

    // Loop until there are at least two prices left
    while (n >= 2)
    {
        // Find the minimum price
        int minPrice = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
                minIndex = i;
            }
        }

        // Find the maximum price after the minimum price
        int maxPrice = INT_MIN;
        int maxIndex = -1;

        for (int i = minIndex + 1; i < n; i++)
        {
            if (prices[i] > maxPrice)
            {
                maxPrice = prices[i];
                maxIndex = i;
            }
        }

        // Calculate profit and add to total profit
        if (maxIndex != -1)
        {
            totalProfit += maxPrice - minPrice;

            // Delete elements at minIndex and maxIndex
            // Move elements after maxIndex to fill the gap left by deletion
            for (int i = maxIndex + 1; i < n; i++)
            {
                prices[i - 1] = prices[i];
            }
            n--; // Decrement array size

            // Move elements after minIndex to fill the gap left by deletion
            for (int i = minIndex; i < n; i++)
            {
                prices[i] = prices[i + 1];
            }
            n--; // Decrement array size
        }
        else
        {
            // If no maximum price found, break the loop
            break;
        }
    }

    return totalProfit;
}

int main()
{
    // Test case data
    int prices[] = {10, 15, 7, 20, 5, 25, 30, 12, 18, 22};
    int n = sizeof(prices) / sizeof(prices[0]);

    // Calculate and print the maximum profit
    int max_profit = maxProfit(prices, n);
    printf("Maximum profit is: %d\n", max_profit);

    return 0;
}
