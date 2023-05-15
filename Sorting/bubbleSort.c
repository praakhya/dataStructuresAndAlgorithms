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
void bubbleSort(int* arr, int len) {
    for (int i=0; i<len-1; ++i) {
        for (int j=0; j<len-1-i; ++j) {
            if (arr[j]>arr[j+1]) {
                swap(&(arr[j]),&(arr[j+1]));
            }
        }
    }
}
void bubbleSortImproved(int* arr, int len) {
    for (int i=0; i<len-1; ++i) {
        int anyswaps=0;
        for (int j=0; j<len-1-i; ++j) {
            if (arr[j]>arr[j+1]) {
                swap(&(arr[j]),&(arr[j+1]));
                anyswaps=1;
            }
        }
        if (!anyswaps) {
            return;
        }
    }
}
void bubbleSortRec(int* arr, int len) {
    if (len<=1) {
        return;
    }
    int anyswaps=0;
    for (int j=0; j<len-1; ++j) {
        if (arr[j]>arr[j+1]) {
            swap(&(arr[j]),&(arr[j+1]));
            anyswaps=1;
        }
    }
    if (!anyswaps) {
        return;
    }
    else {
        bubbleSort(arr,len-1);
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
    bubbleSortRec(arr,n);
    printArr(arr,n);
    printf("\n");
    return 0;
}
