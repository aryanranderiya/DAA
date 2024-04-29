#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum returns after 'months' months
int maxReturns(int n, int budget, int months, int costs[], int quantities[], int returns[])
{
    // Create a 2D array to store maximum returns
    int dp[budget + 1][months + 1];

    // Initialize base cases
    for (int i = 0; i <= budget; i++)
    {
        for (int j = 0; j <= months; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Iterate over each asset
    for (int i = 0; i < n; i++)
    {
        // Update dp for each asset and each month
        for (int j = 1; j <= months; j++)
        {
            for (int k = budget; k >= costs[i]; k--)
            {
                // If quantity of asset 'i' is available
                if (quantities[i] > 0)
                {
                    dp[k][j] = (dp[k][j] > (dp[k - costs[i]][j - 1] + returns[i])) ? dp[k][j] : (dp[k - costs[i]][j - 1] + returns[i]);
                    quantities[i]--;
                }
            }
        }
    }

    // Maximum returns will be stored in dp[budget][months]
    return dp[budget][months];
}

int main()
{
    // Example inputs
    int n = 3;                    // Number of assets
    int budget = 5;               // Maximum allocated budget
    int months = 2;               // Number of months
    int costs[] = {1, 2, 3};      // Cost of buying one unit of each asset
    int quantities[] = {2, 1, 2}; // Quantity of each asset available
    int returns[] = {2, 3, 4};    // Expected return after 'months' months for each asset

    // Find and print the maximum returns after 'months' months
    int max_profit = maxReturns(n, budget, months, costs, quantities, returns);
    printf("Maximum returns after %d months: %d\n", months, max_profit);

    return 0;
}
