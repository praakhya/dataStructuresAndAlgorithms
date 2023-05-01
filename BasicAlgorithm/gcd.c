#include <stdio.h>
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
    while ((m%t)!=0) {
        --t;
    }
    while ((n%t)!=0) {
        --t;
    }
    return t;
}
int gcd(int m, int n) {
    return conseqIntGCD(m,n);
}
int main() {
    int a,b;
    printf("Enter 2 numbers: ");
    scanf("%d%d",&a,&b);
    printf("GCD(%d,%d): %d\n",a,b,gcd(a,b));
    return 0;
}