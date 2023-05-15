#include <stdio.h>
#include <math.h>
int power(int a,int n) {
    int p=1;
    for (int i=1; i<=n; ++i) {
        p=p*a;
    }
    return p;
}
int powerDivConq(int a, int n) {
    if (n==0) {
        return 1;
    }
    if (n==1) {
        return a;
    }
    return powerDivConq(a,floor(n/2))*powerDivConq(a,floor(n/2));
}
int powerDecConq(int a, int n) {
    if (n==0) {
        return 1;
    }
    return a*powerDecConq(a,n-1);
}
int powerDecConstFact(int a, int n) {
    if (n==0) {
        return 1;
    }
    int p = powerDecConstFact(a, floor(n/2));
    p = p*p;
    if (n%2!=0) {
        p = p*a;
    }
    return p;
}

int main() {
    printf("%d\n",power(3,4));
    printf("%d\n",powerDivConq(3,4));
    printf("%d\n",powerDecConq(3,4));
    printf("%d\n",powerDecConstFact(3,4));
}