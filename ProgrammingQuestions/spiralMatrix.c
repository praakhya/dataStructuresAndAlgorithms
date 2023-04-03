#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int spiralmatrix(int m, int n, int (*arr)[n])
{
    int top = 0, left = 0, right = n, bottom = m, i = 0;

    while (left <= right && top <= bottom)
    {
        for (i = left; i < right; ++i)
        {
            // printf("(%d%d) ",top,i);
            printf("%d ", arr[top][i]);
        }
        ++top;
        for (i = top; i < bottom; ++i)
        {
            // printf("(%d%d) ",i,right);
            printf("%d ", arr[i][right]);
        }
        --right;
        for (i = right; i > left; --i)
        {
            // printf("(%d%d) ",bottom,i);
            printf("%d ", arr[bottom][i]);
        }
        --bottom;
        for (i = bottom; i > top; --i)
        {
            // printf("(%d%d) ",i,left);
            printf("%d ", arr[i][left]);
        }
        ++left;
    }
    return 1;
}

int main()
{
    int n, m;
    // printf("\nInput the number of rows : ");
    scanf("%d", &m);
    // printf("\nInput the number of columns : ");
    scanf("%d", &n);
    int arr[m][n];
    int i, j;
    // printf("\nInput the matrix \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    spiralmatrix(m, n, arr);
}