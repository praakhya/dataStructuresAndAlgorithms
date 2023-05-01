#include <stdio.h>
#include <limits.h>
#include "../helperFunctions.h"
const int maxLen = 100; 
void swap(int* a, int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectSort(int* arr, int len) {
    int minVal;
    for (int i=0; i<len-1; ++i) {
        minVal = arr[i];
        for (int j=i+1; j<len; ++j) {
            if (arr[j]<minVal) {
                minVal = arr[j];
            }
        }
        swap(&(arr[i]),&(minVal));
    }
}
int main() {
    int arr[maxLen], n;
    printf("Count of numbers: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&(arr[i]));
    }
    selectSort(arr,n);
    printArr(arr,n);
    return 0;
}