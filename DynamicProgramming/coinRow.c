#include <stdio.h>

int max(int a, int b) { return a>=b?a:b; };
int coinRow(int n, int coins[]) {
    int F[n+1];
    for (int i=0; i<n; ++i) {
        F[i]=-1;
    }
    
    F[0]=0; 
    F[1]=coins[1];
    for (int i=2; i<=n; ++i) {
        
        F[i] = max(coins[i]+F[i-2], F[i-1]);
    }
    for (int i=0; i<=n; ++i) {
        printf("%d: %d\n",i,F[i]);
    }
    return F[n];
}
int main() {
    int n=6;
    int len=n+1;
    int coins[] = {0,5,1,2,10,6,2};
    printf("Max=%d\n",coinRow(n,coins));
    return 0;
}