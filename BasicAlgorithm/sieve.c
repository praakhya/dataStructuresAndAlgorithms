#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int* sieve(int n) {
    int* primes = (int*) malloc(sizeof(int)*n);
    int primeList[n];
    for (int i=0; i<n; ++i) {
        primeList[i]=i;
    }
    
    for (int i=2; i<sqrt(n); ++i) {
        if (primeList[i]!=0) {
            int j = i*i;
            while (j<=n) {
                primeList[j]=0;
                j+=i;
            }
        }
        
    }
    int i=0;
    for (int p=2; p<n; ++p) {
        if (primeList[p]!=0) {
            primes[i] = primeList[p];
            ++i;
        }
    }
    primes[i]=-1;
    return primes;
}
int main() {
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int* primes = sieve(n);
    int i=0;
    while (primes[i]!=-1) {
        printf("%d ",primes[i]);
        ++i;
    }
    printf("\n");
    return 0;
}