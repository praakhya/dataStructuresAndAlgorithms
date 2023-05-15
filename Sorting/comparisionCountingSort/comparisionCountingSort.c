#include "../../helperFunctions.h"
int* comparisionCountingSort(int* arr, int len) {
    int countArr[len];
    for (int i=0; i<len; ++i)
    {
        countArr[i]=0;
    }
    for (int i=0; i<len; ++i)
    {
        for (int j=i+1; j<len; ++j)
        {
            if (arr[j]<=arr[i])
            {
                ++countArr[i];
            }
            else if (arr[j]>arr[i])
            {
                ++countArr[j];
            }
            printf("ai=%d, aj=%d: ",arr[i],arr[j]);
            printArr(countArr,len);
            printf("\n");
        }
    }
    printArr(countArr,len);
    printf("\n");
    int* sortedArr = (int*) malloc(sizeof(int)*len);
    for (int i=0; i<len; ++i)
    {
        int newInd = countArr[i];
        sortedArr[newInd] = arr[i];
    }
    return sortedArr;
}
