#include "comparisionCountingSort.h"
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
    int* sorted = comparisionCountingSort(arr,n);
    printArr(sorted,n);
}