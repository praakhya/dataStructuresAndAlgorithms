//boilerplate code
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * restoreString(char * s, int* indices, int indicesSize){
  char* restored = (char*) malloc(sizeof(indicesSize));
  for (int i=0; i<indicesSize; ++i)
  {

    restored[indices[i]] = s[i];
  }
  return restored;
  
}

int main() {
    char word[20];
    char* word1;
    int indices[50];
    int n=0;
    gets(word);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&indices[i]);
    }
    word1 = restoreString(word,indices,n);
    printf("%s",word1);
}
