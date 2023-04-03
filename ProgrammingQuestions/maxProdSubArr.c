#include <stdio.h>
// Find maximum between two numbers.
int max(int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}
int subArrProd(int start, int end, int* arr, int len)
{
    int prod=1;
    for (int i=start; i<=end; ++i)
    {
        prod*=arr[i];
    }
    return prod;
}
/* Returns the product of max product subarray.*/
int maxSubarrayProduct(int arr[], int n)
{
    int maxProd=1, prod=1, end=n, start;
    for (int i=0; i<n; ++i)
    {
        for (int end=i; end<n; ++end)
        {
            prod=subArrProd(i,end,arr,n);
            maxProd = max(maxProd, prod);
        }
        
        prod=1;
    }
    return maxProd;
}
// Driver code
int main()
{
    int arr[20], n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    // int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    printf("Maximum Sub array product is %d ",
           maxSubarrayProduct(arr, n));
    return 0;
}