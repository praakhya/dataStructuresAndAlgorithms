#include <stdio.h>
#include <limits.h>
int min(int a, int b) { return a<b?a:b;}
int changeMaking(int D[], int n, int m) {
    int len=n+1;
    int F[len];
    for (int i=0; i<=n; ++i) {
        F[i]=0;
    }
    for (int i=1; i<=n; ++i) {
        int temp = INT_MAX, j=1;
        while (j<=m && i>=D[j]) {
            temp = min(F[i-D[j]],temp);
            ++j;
        }
        F[i]=temp+1;
    for (int i=0; i<=n; ++i) {
        printf("%d: %d\n",i,F[i]);
    }
    return F[n];
    }
}
int main() {
    int D[5]={0,1,2,3,4};
    int m=5, n=6;
    printf("%d\n",changeMaking(D,n,m));


}