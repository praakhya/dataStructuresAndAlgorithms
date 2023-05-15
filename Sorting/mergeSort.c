#include <stdio.h>
#include <math.h>
#include "../helperFunctions.h"
const int maxLen = 100; 

//Divide-and-Conquer method to sort an array.

void merge(int a[], const int l, const int r, int m) {
    printf("\tIn merge\n");
    printf("\tl=%d, r=%d, m=%d, ",l,r,m);
    printArrSect(a,l,r);
    printf("\n");
    int i=l, j=m, k=0;
    const int len=r-l+1;
    int b[len]; 
    while (i<m && j<=r) {
        if (a[i]<=a[j]) {
            printf("\tpick i\n");
            b[k]=a[i];
            ++i;
        }
        else {
            printf("\tpick j\n");
            b[k]=a[j];
            ++j;
        }
        ++k;
        printf("\tb: ");
        printArr(b,k);
        printf("\n");
    }
    if (i==m) {
        if (j<=r) {
            printf("\tFill from second half\n");
            for (k=k; k<len; ++k) {
                b[k] = a[j];
                ++j;
            }
        }
    }
    else {
        printf("\tFill from first half\n");
        for (k=k; k<len; ++k) {
            b[k] = a[i];
            ++i;
        }
    }
    k=0;
    for (int i=l; i<=r; ++i) {
        a[i]=b[k];
        ++k;
    }
}
void mergeSort(int arr[], int l, int r) {
    int len=r-l+1;
    printArrSect(arr,l,r);
    printf("(len=%d)\n",len);
    if (l>=r) {
        return;
    }
    
    int m = floor(len/2);
    mergeSort(arr,l,l+m-1);
    printf("[%d:%d] complete\n",l,l+m-1);
    mergeSort(arr,l+m,r);
    printf("[%d:%d] complete\n",l+m,r);
    merge(arr,l,r,l+m);
    printArrSect(arr,l,r);
    printf(" <-- after merge\n");
}

int main() {
    int arr[maxLen], n;
    printf("Count of numbers: ");
    scanf("%d",&n);
    printf("Enter %d numbers: ",n);
    for (int i=0; i<n; ++i) {
        scanf("%d",&(arr[i]));
    }
    mergeSort(arr,0,n-1);
    printArr(arr,n);
    printf("\n");
    return 0;
}