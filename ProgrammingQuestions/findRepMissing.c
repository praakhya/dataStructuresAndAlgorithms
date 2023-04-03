#include<stdio.h>
#include<stdlib.h>

void findErrorNums(int *nums, int numsSize)
{
    for (int i=0; i<numsSize-1; ++i)
    {
        if (nums[i]==nums[i+1]) //if the (i+1)th number is a copy of the ith number
        {
            if (i+2<numsSize) //to check if there is a number after i+1
            {
                printf("%d\n%d\n", i+1, (nums[i]+nums[i+2])/2); //i+1 is the repeated number. the average of the ith & i+2 th number tells what i+1 value should have been(given that the numbers are either in increasing or decreasing order and not shuffled)
                break;
            }
            if (i+1<numsSize) //i+1 is the last number
            {
                if (numsSize>2 &&nums[i-1]>nums[i]){ // here i+1's value is decided based on whether the sequence was ascending or descending
                    printf("%d\n%d\n", i+1, nums[i]-1); //sequence was decreasing
                }
                else {
                    printf("%d\n%d\n", i+1, nums[i]+1); //sequence was increasing
                }

                break;
            }
        }
    }
}
int main() {
    // Write C code here
    int a[100000];
    int i, count;
    scanf("%d", &count);
    for (i = 0; i < count; i++) 
    {
          scanf("%d", &a[i]);
    }
    findErrorNums(a, count);
    return 0;
}