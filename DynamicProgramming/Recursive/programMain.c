#include "knapsack.h"
int main()
{
    struct knapsackItems items[] = {
        {1,2,12},
        {2,1,10},
        {3,3,20},
        {4,2,15}
    };
    int len = 4;
    int capacity = 5
    printf("%d\n",knapsack(&items, len, capacity));
}