/*  Warehouse Inventory Management System */
#include <stdio.h>
#define N 3 // Number of products
#define DAYS 7 // Number of days

/*|-----------------------------------INSTRUCTIONS - PROGRAM USAGE EXPLANATION--------------------------------------|
    --->SUBTASK A: Ask the user to input the stock (quantities) of each product for 7 days.                        |
                  There are 3 products and 7 days. For each product and each day, the user provides                |
                  a value, and these values are stored in a 2D array inventory[N][DAYS].                           |
    --->SUBTASK B: Display the inventory table in a formatted manner for all products and days.                    |
    --->SUBTASK C: Calculate the total stock of each product for the entire week.                                  |
                  For each product: Sum the quantities for each day and store the result                           |
                  in the array weeklyTotal[N], then print the total stock of each product.                         |
    --->SUBTASK D: Find the highest stock value that appeared for any product on any day.                          |
                  Start from position [0][0] and compare it with all other values in the inventory array.          |
    --->SUBTASK E: Calculate the average stock for each product.                                                   |
                  - Use the total quantity of the week (from weeklyTotal).                                         |
                  - Divide it by the number of days (DAYS = 7).                                                    |
                  - Store the result in a float array weeklyAverage[N].                                            |
    --->SUBTASK F: Calculate the insurance cost for each product based on its total weekly quantity                |
                  (weeklyTotal) and the unit cost per item (array costs[N]).                                       |
                  For each product:                                                                                |
                      1) Multiply the total weekly stock with the corresponding cost.                              |
                      2) Add this amount to totalCost.                                                             |
                      3) Print the insurance cost for the product.                                                 |
                  Also, identify which product has the lowest insurance cost (minCostProduct).                     |
|------------------------------------------------------------------------------------------------------------------|*/

void InputData(int inventory[N][DAYS]); /* SUBTASK A */
void DisplayTable(int inventory[N][DAYS]); /* SUBTASK B */
void WeeklyInventory(int inventory[N][DAYS], int weeklyTotal[N]); /* SUBTASK C */
void MaxInventory(int inventory[N][DAYS], int *product, int *day, int *maxStock);  /* SUBTASK D */

void AverageProductInventory(int weeklyTotal[N], float weeklyAverage[N]); /* SUBTASK E */
void InsuranceCostCalculation(int weeklyTotal[N], int costs[N], int *totalCost, int *minCostProduct); /* SUBTASK F */

void InputData(int inventory[N][DAYS])
{  
    printf("Enter the incoming quantities for each product over 7 days (positive integers): \n"); 
    for (int i = 0; i < N; i++)
    {
        printf("------> Product #%d: \n", i+1);
        for (int j = 0; j < DAYS; j++)
        {
            do
            {
                printf("Day %d: ", j+1);
                scanf("%d", &inventory[i][j]);
                if (inventory[i][j] < 0)
                {
                    printf("Quantity must be a positive integer.\n");
                }
            } while (inventory[i][j] < 0);
        }
    }
    printf("\n---------->End of Week<----------\n");
}

void DisplayTable(int inventory[N][DAYS])
{
    printf("\nProduct\t\tMon\tTue\tWed\tThu\tFri\tSat\tSun\n");
    for (int i = 0; i < N; i++)
    {
        printf("\nProduct #%d", i + 1);
        for (int j = 0; j < DAYS; j++)
        {
            printf("\t%d", inventory[i][j]);
        }
        printf("\n");
    }
}

void WeeklyInventory(int inventory[N][DAYS], int weeklyTotal[N])
{
    printf("\nWeekly total inventory per product: \n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < DAYS; j++)
        {
            weeklyTotal[i] += inventory[i][j];
        }
        printf("Product #%d: %d units.\n", i+1, weeklyTotal[i]);
    }
}

void MaxInventory(int inventory[N][DAYS], int *product, int *day, int *maxStock)
{
    *maxStock = inventory[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < DAYS; j++)
        {
            if (inventory[i][j] > *maxStock)
            {
                *maxStock = inventory[i][j];
                *product = i;
                *day = j;
            }
        }
    }
}

void AverageProductInventory(int weeklyTotal[N], float weeklyAverage[N]) {
    for (int i = 0; i < N; i++)
    {
        weeklyAverage[i] = weeklyTotal[i] / (float)DAYS;
    }
}


void InsuranceCostCalculation(int weeklyTotal[N], int costs[N], int *totalCost, int *minCostProduct)
{
    int minCost = weeklyTotal[0] * costs[0];
    *minCostProduct = 0;
    printf("\nInsurance cost per product:\n");
    for (int i = 0; i < N; i++)
    {
        int productCost = weeklyTotal[i] * costs[i];
        *totalCost += productCost;
        printf("Product #%d: %d euros\n", i + 1, productCost);
        if (productCost < minCost)
        {
            minCost = productCost;
            *minCostProduct = i;
        }
    }
}


int main() {
    int inventory[N][DAYS];
    int weeklyTotal[N] = {0};
    float weeklyAverage[N];
    int costs[N] = {10, 14, 20}; // Insurance costs per product
    int totalCost = 0, minCostProduct = 0;
    int maxStock = 0, product = 0, day = 0;

    /* SUBTASK A */
    InputData(inventory);

    /* SUBTASK B */
    DisplayTable(inventory);

    /* SUBTASK C: Calculate total stock per product */
    WeeklyInventory(inventory, weeklyTotal);

    /* SUBTASK D: Find maximum stock */
    MaxInventory(inventory, &product, &day, &maxStock);
    printf("\nHighest stock level:---> Product #%d on day %d with quantity %d units.\n\n", product + 1, day + 1,maxStock);

    /* SUBTASK E: Calculate average inventory */
    AverageProductInventory(weeklyTotal, weeklyAverage);
    printf("---> Average stock for each product: \n");
    for (int i = 0; i < N; i++) {
        printf("Product #%d: %.2f\n", i + 1, weeklyAverage[i]);
    }

    /* SUBTASK F: Calculate insurance cost */
    InsuranceCostCalculation(weeklyTotal, costs, &totalCost, &minCostProduct);
    printf("\n--->Total insurance cost: %d€\n", totalCost);
    printf("--->Product with the lowest insurance cost: Product #%d.\n", minCostProduct + 1);

    return 0;
}
