#include "../../helperFunctions.h"
int* distributionCountingSort(int* arr, int len, int min, int max)
{
    int range;
    if (min==-1 && max==-1)
    {
        min=arr[0], max=arr[0];
        for (int i=0; i<len; ++i)
        {
            if (arr[i]>max)
            {
                max = arr[i];
            }
            if (arr[i]<min)
            {
                min = arr[i];
            }
        }
    }
    range = max-min+1;
    int freq[range];
    for (int i=0; i<range; ++i)
    {
        freq[i]=0;
    }
    for (int i=0; i<len; ++i)
    {
        int freqInd = arr[i]-min;
        ++freq[freqInd];
    }
    for (int i=1; i<range; ++i)
    {
        freq[i]+=freq[i-1];
    }
    int* outputArray = (int*) malloc(sizeof(int)*len);
    for (int i=len-1; i>=0; --i)
    {
        --freq[arr[i]-min];
        outputArray[freq[arr[i]-min]] = arr[i];
    }
    return outputArray;

}