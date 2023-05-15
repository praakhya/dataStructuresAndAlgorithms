#include <stdio.h>
#include "../helperFunctions.h"
void printArrLn(int arr[], int n) {
    printArr(arr,n);
    printf("\n");
}
int euclidsGCDRec(int m, int n) {
    if (n==0) {
        return m;
    }
    return euclidsGCDRec(n, m%n);
}
int euclidsGCDIter(int m, int n) {
    int r;
    while (n!=0) {
        r = m%n;
        m = n;
        n = r;
    }
    return m;
}
int min(int a, int b) {
    return a<b?a:b;
}
int max(int a, int b) {
    return a>b?a:b;
}
int conseqIntGCD(int m, int n) {
    int t=min(m,n);
    if (t==0) {
        return max(m,n);
    }
    while (!(((n%t)==0) && ((m%t)==0))) {
        --t;
    }
    return t;
}
void swap (int* a, int* b) {
    int temp = *a;
    *a= *b;
    *b = temp;
}
void generatePrimes(int primes[], int n) {
    for (int i=2; i<n; ++i) {
        primes[i]=i;
    }
    int i=2;
    while (i<n) {
        if (primes[i]!=0) {
            int start=i*i;
            for (int j=start; j<n; j+=i) {
                primes[j]=0;
            }
        }
        ++i;
        
    }
}
int nextPrime(int p, int primes[], int n) {
    for (int i=p+1; i<n; ++i) {
        if (primes[i]!=0) {
            return i;
        }
    }
    return -1;
}
int gcdPrimeFactors(int m, int n) {
    int primes[n];
    generatePrimes(primes,n);
    if (m<n) {
        swap(&m, &n);
    }
    if (n==0) {
         return m;
    }
    if (n==1) {
        return 1;
    }
    int gcd=1, prime=2;
    while (prime<=n && prime!=-1) {
        if (m%prime==0 && n%prime==0) {
            gcd*=prime;
            m=m/prime;
            n=n/prime;
        }
        else {
            prime=nextPrime(prime,primes,n);
        }
    }
    return gcd;
}
int gcd(int m, int n) {
    return gcdPrimeFactors(m,n);
}
int main() {
    int a,b;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&a,&b);
    printf("GCD(%d,%d): %d\n",a,b,gcd(a,b));
    return 0;
}