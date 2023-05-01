#include <stdio.h>
#include <limits.h>
#include "../helperFunctions.h"

//Brute Force method to sort an array.

const int maxLen = 100; 
void swap(int* a, int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectSort(int* arr, int len) {
    int min;
    for (int i=0; i<len-1; ++i) {
        min = i;
        for (int j=i+1; j<len; ++j) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        swap(&(arr[i]),&(arr[min]));
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
    printf("\n");
    return 0;
}