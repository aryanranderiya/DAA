#include <stdio.h>
#include <limits.h>

// Function to find the minimum number of coins needed to make change
int minCoins(int coins[], int n, int amount)
{
    // Create a table to store the minimum number of coins needed for each amount
    int dp[amount + 1];

    // Initialize the table with maximum possible value
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }

    // Base case: 0 coins needed to make change for amount 0
    dp[0] = 0;

    // Iterate over all possible amounts
    for (int i = 1; i <= amount; i++)
    {
        // Try all coin denominations
        for (int j = 0; j < n; j++)
        {
            // If the current coin denomination is less than or equal to the amount
            if (coins[j] <= i)
            {
                // Update the minimum number of coins needed
                dp[i] = (dp[i - coins[j]] != INT_MAX) ? (dp[i - coins[j]] + 1) : dp[i];
            }
        }
    }

    // The answer is stored in dp[amount]
    return dp[amount];
}

int main()
{
    // Example: Coin denominations
    int coins[] = {1, 5, 10, 25};
    int n = sizeof(coins) / sizeof(coins[0]);

    // Example: Amount for which change is to be made
    int amount = 32;

    // Find the minimum number of coins needed to make change
    int minCoinsNeeded = minCoins(coins, n, amount);

    printf("Minimum number of coins needed to make change for %d: %d\n", amount, minCoinsNeeded);

    return 0;
}
