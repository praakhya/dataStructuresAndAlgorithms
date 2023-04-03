//boilerplate code
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
float probability(int n){
  if (n==1)
  {
    return 1;
  }
  else
  {
    return 0.5;
  }
}
int main() {
    int n=0;
    float prob=0;
    scanf("%d",&n);
    prob = probability(n);
    printf("%0.5f",prob);
    return 0;
}