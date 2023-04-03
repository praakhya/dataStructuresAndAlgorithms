#include <stdio.h>

// Returns minimum number of
// jumps to reach arr[h] from arr[l]
int nextPos(int arr[], int currPos, int h)
{
    int maxVal = arr[currPos+1];    //let maximum value(steps) be the number of steps at the next position
    int max=currPos+1;              //index of the maximum value
    for (int j=currPos; j<currPos+arr[currPos]; ++j)    //looping in the array from current position to (current position + no. of steps from current position)
    {
        //printf("currPos=%d, j=%d\n",currPos,j);
        if (currPos+arr[j]>=h)      //If the jth element has no. of steps that can reach till the last position or beyond, return this as the next pssible position
        {
            return currPos+arr[j];
        }
        if (arr[j]>maxVal)          //Else, the j with the maximum number of steps possible is chosen
        {
            maxVal = arr[j];
            max = j;
        }
    }
    if (maxVal==0)                  //If the number of steps of all following positions within the current position's step range is zero, movement is not possible. Trap.
    {
        return -1;
    }
    else                            //Else the j with maximum value of steps is chosen.
    {
        return max;
    }
}
int minJumps(int arr[], int l, int h)
{
    int notFinished=1;
    int currPos = l;
    int jumps=0;
    while (notFinished)
    {
        //printf("currPos=%d\n",currPos);
        currPos = nextPos(arr, currPos, h);     //gets the possible next position from above function
        ++jumps;    //increases number of jumps by one.
        if (currPos>=h)
        {
            return jumps;
        }
        else if(currPos==-1)    //if -1 was returned from the above function, no path was found
        {
            return -1;
        }
    }
}
 
// Driver program to test above 
int main()
{
    int arr[50];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Minimum number of jumps to reach end is %d ",
           minJumps(arr, 0, n - 1));
    return 0;
}