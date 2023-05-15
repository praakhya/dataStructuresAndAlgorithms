#include "helperFunctions.h"
void printArr(int* arr, int len)
{
    printf("[");
    for (int i=0; i<len; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("]");
}
void printArrSect(int* arr, int l, int r)
{
    printf("[");
    for (int i=l; i<=r; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("]");
}
void printMat(int** mat, int r, int c)
{
    printf("[");
    for (int i=0; i<r; ++i)
    {
        printf("[ ");
        for (int j=0; j<c; ++j)
        {
            printf("%d ",mat[i][j]);
        }
        printf("]\n");
    }
    printf("]");
}
