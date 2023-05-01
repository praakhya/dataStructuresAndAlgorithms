#include <stdio.h>
#include <string.h>
int bruteForceMatching(char* pattern, char* text) {
    int n = strlen(text), m=strlen(pattern), j=0;
    if (n<m) {
        return -2;
    }
    for (int i=0; i<n-m; ++i) {
        while (j<m && (pattern[j]==text[i+j])) {
            ++j;
        }
        if (j==m) {
            return i;
        }
    }
    return -1;
}
int main() {
    char p[100], t[100];
    printf("Enter text: ");
    scanf("%[^\n]%*c",t);
    printf("Enter pattern: ");
    scanf("%[^\n]%*c",p);
    int ind = bruteForceMatching(p,t);
    switch(ind) {
        case -1:
            printf("Value not found\n");
            break;
        case -2:
            printf("Error: Length of pattern greater than length of text\n");
            break;
        default:
            printf("Pattern found at index %d\n",ind);

    }
    return 0;
}