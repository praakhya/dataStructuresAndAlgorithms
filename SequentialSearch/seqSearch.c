#include <stdio.h>
int seqSearchBasic(int key, int* arr, int len) {
    for (int i=0; i<len; ++i) {
        if (arr[i]==key) {
            return i;
        }
    }
    return -1;
}
int seqSearchSentinel(int key, int* arr, int len) {
    arr[len]=key;
    int i=0;
    while (arr[i]!=key) {
        ++i;
    }
    if (i==len) {
        return -1;
    }
    else {
        return i;
    }
}
int seqSearch(int key, int* arr, int len) {
    return seqSearchSentinel(key,arr,len);
}
int main() {
    int arr[100], len, key;
    printf("Enter count of numbers: ");
    scanf("%d",&len);
    printf("Enter %d numbers: ",len);
    for (int i=0; i<len; ++i) {
        scanf("%d",&(arr[i]));
    }
    printf("Enter value to be searched: ");
    scanf("%d",&key);
    int ind = seqSearch(key,arr,len);
    if (ind==-1) {
        printf("Value not found\n");
    }
    else {
        printf("%d found at index %d\n",key,ind);
    }
    return 0;
}