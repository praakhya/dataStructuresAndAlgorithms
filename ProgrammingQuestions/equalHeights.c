#include <stdio.h>
#include <stdlib.h>

int* copyArray(int* arr, int size)
{
    int* newArr = (int*) malloc(sizeof(size));
    for (int i=0; i<size; ++i)
    {
        newArr[i] = arr[i];
    }
    return newArr;
}
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArr(int* arr, int n)
{
    for (int i=0; i<n; ++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void sort(int* arr, int size)
{
    for (int i=0; i<size; ++i)
    {
        int anyswap=0;
        for (int j=0; j<size-2-i; ++j)
        {
            if (arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                anyswap=1;
            }
            if (anyswap==0)
            {
                return;
            }
        }
    }
}

int heightChecker(int* heights, int heightsSize){
    int result=0;
    int* expected = copyArray(heights, heightsSize);
    sort(expected,heightsSize);
    for (int i=0; i<heightsSize; ++i)
    {
        if (heights[i]==expected[i])
        {
            ++result;
        }
    }
    return result;
}
int main()
{
    // array to store digits
    int a[100000];
    int i, count;
    scanf("%d", &count);
    for (i = 0; i < count; i++) {
  
        // %1d reads a single digit
        scanf("%3d", &a[i]);
    }
  
     printf("%d", heightChecker(a,count));
      
    return 0;
}
