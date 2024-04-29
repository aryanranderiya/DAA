#include <stdio.h>
#include <stdlib.h>

#define MAX_ASSETS 100
#define MAX_BUDGET 1000

double compare(double a, double b)
{
    if (a > b)
        return a;
    else if (b > a)
        return b;
    else
        return a;
}

double maxReturns(int n, int b, int t, int costs[], int quantities[], double returns[])
{
    double dp[b + 1];
    for (int i = 0; i <= b; i++)
    {
        dp[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = b; j >= costs[i]; j--)
        {
            for (int k = 1; k <= quantities[i] && k * costs[i] <= j; k++)
            {
                dp[j] = compare(dp[j], dp[j - k * costs[i]] + k * returns[i]);
            }
        }
    }

    return dp[b];
}

int main()
{
    int n = 5;                                    // Number of assets
    int b = 100;                                  // Maximum allocated budget
    int t = 6;                                    // Time in months
    int costs[] = {20, 50, 10, 30, 20};           // Cost of each asset
    int quantities[] = {5, 2, 4, 3, 2};           // Quantity available for each asset
    double returns[] = {1.5, 1.8, 2.1, 1.1, 0.5}; // Expected returns after t months

    printf("Maximum returns after %d months: %.2f\n", t, maxReturns(n, b, t, costs, quantities, returns));

    return 0;
}
