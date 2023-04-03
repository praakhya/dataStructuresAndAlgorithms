#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print primes
void printPrimeOld(int n)
{
    int* primeArr = (int*) malloc(sizeof(n));
    int temp=0;
    int ct=0;
    for (int p=2; p<n; ++p)
    {
        primeArr[p] = p;
    }
    for (int p=2; p<n; ++p)
    {
        if (primeArr[p]!=0)
        {
            temp=p*p;
            while (temp<=n)
            {
                primeArr[temp]=0;
                temp=temp+p;
            }
        }
    }
    for (int p=2; p<n; ++p)
    {
        if (primeArr[p]!=0)
        {
            ++ct;
        }
    }
    printf("%d",ct);
}
void printPrime(int n)
{
    int ct=0;
    for (int i=2;i<n;++i)
    {
        int isPrime=1;
        for (int j=2; j<i; ++j)
        {
            if (i%j==0)
            {
                isPrime=0;
            }
        }
        if (isPrime)
        {
            ++ct;
        }
    }
    printf("%d",ct);
}
int main()
{
    int n;
    scanf("%d", &n);
    printPrime(n);
    return 0;
}