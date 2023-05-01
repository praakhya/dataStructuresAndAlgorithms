#include <stdio.h>
#include "../helperFunctions.h"
const int maxLen = 100; 

//Decrease-and-Conquer method to sort an array.

void insertionSortIter(int arr[], int len) {
    int temp, j;
    for (int i=1; i<len; ++i) {
        temp = arr[i];
        j=i-1;
        while (j>=0 && arr[j]>temp) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1]=temp;
    }
}
void insertionSortRec(int arr[], int len) {
    if (len>1) {
        insertionSortRec(arr, len-1);
    }
    int temp=arr[len-1];
    int j=len-2;
    while (j>=0 && arr[j]>temp) {
        arr[j+1] = arr[j];
        --j;
    }
    arr[j+1] = temp;
}
void insertionSort(int arr[], int len) {
    insertionSortRec(arr,len);
}
int main() {
    int arr[maxLen], n;
    printf("Count of numbers: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&(arr[i]));
    }
    insertionSort(arr,n);
    printArr(arr,n);
    printf("\n");
    return 0;
}