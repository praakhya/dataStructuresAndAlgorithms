#include "knapsack.h"
#include "../../helperFunctions.h"
int max(int a,int b) {
    return a>b?a:b;
}
int F(int i, int j, int* w, int* v) {
    if (i==j) {
        if (w[i]>j) {
            return 0;
        }
        else {
            return v[i];
        }
    }
    else {
        if (w[i]>j) {
            return F(i-1,j,w,v);
        }
        else {
            return max(F(i-1,j,w,v), v[i]+F(i-1,j-w[i],w,v));
        }
    }
}

int knapsack(struct knapsackItem* items, int len, int capacity)
{
    int w[len], v[len];
    for (int i=0; i<len; ++i) {
        w[items[i].itemNo] = items[i].itemWt;
        v[items[i].itemNo] = items[i].itemVal;
    }
    return F(items[len-1].itemNo, capacity,w,v);
}