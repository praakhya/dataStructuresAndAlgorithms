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
void selectSortRec(int* arr, int l, int r) {
    if (l>=r) {
        return;
    }
    int min = l;
    for (int j=l+1; j<=r; ++j) {
        if (arr[j]<arr[min]) {
            min = j;
        }
    }
    swap(&(arr[l]),&(arr[min]));
    selectSortRec(arr,l+1,r);
}

int main() {
    int arr[maxLen], n;
    printf("Count of numbers: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&(arr[i]));
    }
    selectSortRec(arr,0,n-1);
    printArr(arr,n);
    printf("\n");
    return 0;
}