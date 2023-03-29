#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxnum=100;
typedef struct Item {
    int weight;
    int value;
} item;
void sort(int len, int* arr)
{

}
int solveKnapsack(int len, int* arr)
{
    

}
int main()
{
    int a[maxnum];
    int len;
    scanf("%d",&len);
    for (int i=0; i<len; ++i)
    {
        scanf("%d",&a[i]);
    }
    printf("Maximum value: %d\n",solveKnapsack(len,arr));
    return 0;
}