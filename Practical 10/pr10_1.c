#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int index;
    double growth_rate;
} License;
int compare(const void *a, const void *b)
{
    License *license1 = (License *)a;
    License *license2 = (License *)b;
    if (license1->growth_rate < license2->growth_rate)
        return -1;
    else if (license1->growth_rate > license2->growth_rate)
        return 1;
    else
        return 0;
}

void compute_order(License licenses[], int n)
{
    qsort(licenses, n, sizeof(License), compare);
    double total_cost = 0.0;
    for (int i = 0; i < n; i++)
    {
        total_cost += licenses[i].growth_rate * (i + 1) * 100;
    }

    printf("Total cost: $%.2lf\n", total_cost);
    printf("Order of licenses to minimize cost:\n");
    for (int i = 0; i < n; i++)
    {
        printf("License %d\n", licenses[i].index);
    }
}

int main()
{
    int n;
    printf("Enter the number of licenses: ");
    scanf("%d", &n);
    License licenses[n];
    for (int i = 0; i < n; i++)
    {
        licenses[i].index = i + 1;
        printf("Enter growth rate for license %d: ", i + 1);
        scanf("%lf", &licenses[i].growth_rate);
    }
    compute_order(licenses, n);
    return 0;
}