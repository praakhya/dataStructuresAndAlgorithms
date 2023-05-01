#include <stdio.h>
int fibDynamic(int n, int sequence[]) {
    if (sequence[n]!=-1) {
        return sequence[n];
    }
    else {
        sequence[n] = fibDynamic(n-1,sequence) + fibDynamic(n-2,sequence); 
    }
}

void fibonacci(int n) {
    int sequence[n+1];
    for (int i=0; i<n+1; ++i) {
        sequence[i]=-1;
    }
    sequence[0]=0;
    sequence[1]=1;
    fibDynamic(n,sequence);
    for (int i=0; i<n+1; ++i) {
        printf("%d ",sequence[i]);
    }
    printf("\n");
}

int main() {
    fibonacci(7);
}