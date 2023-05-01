#include <stdio.h>
#include <stdlib.h>
#include "../helperFunctions.h"
const int maxLen = 200;
typedef struct Graph {
    int** matrix;
    int numOfVert;
} graph;
void dfsIter(int v, graph* g, int visited[]);
void dfsRec(int v, graph* g, int visited[]);
void dfs(int v, graph* g);
void dfsRec(int v, graph* g, int visited[]) {
    printf("%d ",v);
    visited[v]=1;
    for (int i=0; i<g->numOfVert; ++i) {
        if (!visited[i] && g->matrix[v][i]!=0) {
            dfsRec(i,g,visited);
        }
    }
}
void push(int val, int stack[], int* top) {
    if ((*top)+1>=maxLen) {
        return;
    }
    stack[++(*top)]=val;
}
int pop(int stack[], int* top) {
    if ((*top)==-1) {
        return -1;
    }
    return stack[(*top)--];
}
void dfsIter(int v, graph* g, int visited[]) {
    int numVert = g->numOfVert;
    int stack[maxLen], top=-1;
    push(v,stack,&top);
    visited[v]=1;
    while (top!=-1) {
        //printf("top=%d, stack=",top);
        //printArr(stack,top+1);
        //printf("\n");
        int val = pop(stack,&top);
        printf("%d ",val);
        for (int i=0; i<numVert; ++i) {
            if (g->matrix[val][i]!=0 && !visited[i]) {
                push(i,stack,&top);
                visited[i]=1;
            }
        }
    }
    printf("\n");

}
void dfs(int v, graph* g) {
    int visited[g->numOfVert];
    for (int i=0; i<g->numOfVert; ++i) {
        visited[i]=0;
    }
    dfsRec(v, g, visited);
    printf("\n");
}
int main() {
    int n;
    graph* g = (graph*) malloc(sizeof(graph));
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    g->matrix = (int**) malloc(sizeof(int*)*n);
    for (int i=0; i<n; ++i) {
        g->matrix[i]=(int*) malloc(sizeof(int)*n);
    }
    for (int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            g->matrix[i][j]=0;
        }
    }
    g->numOfVert = n;
    printf("Enter edges (-1 -1 to end)\n");
    int src=0,dest=0,wt;
    scanf("%d%d%d",&src,&dest,&wt);
    while ((src!=-1) && (dest!=-1)) {
        g->matrix[src][dest]=wt;
        scanf("%d%d%d",&src,&dest,&wt);
    }
    printMat(g->matrix, g->numOfVert, g->numOfVert);
    printf("\n");
    dfs(0,g);
    return 0;
}