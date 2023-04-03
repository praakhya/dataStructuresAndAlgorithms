#include <stdio.h>
#include <stdlib.h>

struct Task
{
    int index;
    int enqueueTime;
    int processingTime;
};
int isCompleted(int n, int *arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if (n == arr[i])
        {
            return 1;
        }
    }
    return 0;
}
int *getOrder(struct Task *tasks, int tasksSize, int *returnSize)
{
    // printf("In get order\n");
    int currTime = 0;
    int *result = (int *)malloc(sizeof(int) * tasksSize);
    *returnSize = 0;
    while (1)
    {
        // printf("In while\n");
        int iWithMinProcess = -1;
        int minProcessVal = 1000;
        for (int i = 0; i < tasksSize; ++i)
        {
            // printf("In for i=%d\n",i);
            if (tasks[i].enqueueTime > currTime)
            {
                continue;
            }
            if (tasks[i].enqueueTime <= currTime)
            {
                if (!isCompleted(tasks[i].index, result, *returnSize) && tasks[i].processingTime < minProcessVal)
                {
                    minProcessVal = tasks[i].processingTime;
                    iWithMinProcess = tasks[i].index;
                }
            }
        }
        if (iWithMinProcess != -1)
        {
            result[*returnSize] = iWithMinProcess;
            ++(*returnSize);
            currTime += minProcessVal;
        }
        else
        {
            ++currTime;
        }
        int numOfCompleted = 0;
        for (int i = 0; i < tasksSize; ++i)
        {
            if (isCompleted(tasks[i].index, result, *returnSize))
            {
                ++numOfCompleted;
            }
        }
        if (numOfCompleted == tasksSize)
        {
            return result;
        }
        // printArr(result, *returnSize);
    }
}
int main()
{
    int tasksSize;
    scanf("%d", &tasksSize);

    struct Task tasks[tasksSize];
    for (int i = 0; i < tasksSize; i++)
    {
        tasks[i].index = i;
        scanf("%d %d", &tasks[i].enqueueTime, &tasks[i].processingTime);
    }

    int returnSize;
    int *result = getOrder(tasks, tasksSize, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}