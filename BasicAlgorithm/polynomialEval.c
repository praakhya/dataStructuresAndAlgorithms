#include <stdio.h>

float evalPoly(int degree, int xVal, float coeffs[]) {
    float result=0;
    int powOfX=1;
    for (int i=degree; i>=0; --i) {
        result+=coeffs[i]*powOfX;
        powOfX*=xVal;
    }
    return result;
}
void printPoly(int degree, float coeffs[]) {
    printf("f(x) = ");
    for (int i=degree; i>=0; --i) {
        printf("%+.2fx^%+d ",coeffs[degree-i],i);
    }
    printf("\n");
}


int main() {
    const int maxDegree=201;
    float coeffs[maxDegree], xVal, inpCoeff;
    int degree, inpPow;
    char inpEnd;
    printf("Enter degree of polynomial: ");
    scanf("%d", &degree);
    printf("Enter polynomial: ");
    for (int j=0; j<=degree; ++j) {
        coeffs[j]=0;
    }
    int i=degree;
    while (i>=0) {
        scanf("%fx^%d%c",&inpCoeff, &inpPow,&inpEnd);
        coeffs[degree-inpPow] = inpCoeff;
        i=inpPow;
        if (inpEnd=='\n') {
            break;
        }
    }
    printf("Enter value of x: ");
    scanf("%f",&xVal);
    printPoly(degree,coeffs);
    printf("f(%+.2f)=%+.2f\n",xVal,evalPoly(degree,xVal,coeffs));
    return 0;
}
