#include "distributionCountingSort.h"
#include "../../helperFunctions.h"
const int maxlength=20;
int main()
{
    int arr[maxlength], n;
    scanf("%d",&n);
    for (int i=0; i<n; ++i)
    {
        scanf("%d",&arr[i]);
    }
    int* sorted = distributionCountingSort(arr,n,-1,-1);
    printArr(sorted,n);
}