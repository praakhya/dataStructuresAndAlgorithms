#ifndef _KNAPSACK_H
#include <stdio.h>
int knapsack(struct knapsackItem* items, int len, int capacity);
int F(int i, int j, int* w, int* v);
int max(int a,int b);
struct knapsackItem {
    int itemNo;
    int itemWt;
    int itemVal;
};
#endif
