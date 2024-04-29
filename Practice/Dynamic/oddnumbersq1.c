#include <stdio.h>

#define MAX_PLATFORMS 100
#define MAX_BUDGET 1000

int maxImpact(int n, int B, int costs[], int quantities[], int impacts[])
{
    // Dynamic programming array to store maximum impact for each budget
    int dp[MAX_BUDGET + 1];

    // Initialize dp array
    for (int i = 0; i <= B; i++)
    {
        dp[i] = 0;
    }

    // Iterate through each platform
    for (int i = 0; i < n; i++)
    {
        // Iterate through each budget amount
        for (int j = B; j >= costs[i]; j--)
        {
            // Try buying 0 to the maximum quantity of the platform
            for (int k = 1; k <= quantities[i] && k * costs[i] <= j; k++)
            {
                // Update dp[j] with maximum impact achievable using platform i
                dp[j] = dp[j] < dp[j - k * costs[i]] + k * impacts[i] ? dp[j - k * costs[i]] + k * impacts[i] : dp[j];
            }
        }
    }

    // Return maximum impact achievable within budget B
    return dp[B];
}

int main()
{
    int n = 4;                        // Number of advertising platforms
    int B = 100;                      // Maximum allocated budget
    int costs[] = {80, 40, 12, 20};   // Cost of advertisement on each platform
    int quantities[] = {3, 4, 10, 6}; // Quantity of advertisement required for each platform
    int impacts[] = {10, 8, 5, 6};    // Impact of advertisement on each platform

    printf("Maximized impact within budget: %d\n", maxImpact(n, B, costs, quantities, impacts));

    return 0;
}
