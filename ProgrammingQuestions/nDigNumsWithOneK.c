#include <stdio.h>
#include <math.h>

int countNumbers(int N, int K)
{
    int numOfNDigNums = 9 * pow(10, N - 1);
    int numOfNDigNums_noK = 8 * pow(9, N - 1);
    int numOfNDigNums_yesK = numOfNDigNums - numOfNDigNums_noK;
    return numOfNDigNums_yesK;
}

int main()
{
    int N = 0;
    int K = 0;
    scanf("%d", &N);
    scanf("%d", &K);
    int countWithK = countNumbers(N, K);
    printf("%d", countWithK);
}