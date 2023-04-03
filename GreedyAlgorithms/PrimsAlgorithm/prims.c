#include <stdio.h>
#include <stdlib.h>
const int maxLength=100;

typedef struct set_t
{
    int setArr[maxLength];
    int len;
} set;
typedef struct adjacencyMatrix
{
    int mat[maxLength][maxLength];
    int len;
} adjMat;
void addToSet(set* s, int val) {
    if (s->len==maxLength)
    {
        return;
    }
    s->setArr[s->len] = val;
    ++(s->len);
}
int setContains(set* s, int val) {
    for (int i=0; i<s->len; ++i)
    {
        if (s->setArr[i]==val)
        {
            return i;
        }
    }
    return -1;
}
void removeFromSet(set* s, int val) {
    if (s->len==0)
    {
        return;
    }
    int i = setContains(s,val);
    for (int j=i; j<s->len-1; ++j)
    {
        s->setArr[j] = s->setArr[j+1];
    }
    --(s->len);
}

adjMat* minEdgeMat(adjMat* m, set* inTree, set* notInTree)
{
    int minVal=m->mat[0][0], minI=0, minJ=0;
    adjMat* newM = (adjMat*) malloc(sizeof(adjMat));
    newM->len = m->len;
    for (int i=0; i<m->len; ++i)
    {
        for (int j=0; j<m->len; ++j)
        {
            if (m->mat[i][j]<minVal)
            {
                minI = i;
                minJ = j;
                minVal = m->mat[i][j];
            }
        }
    }
    newM->mat[minI][minJ] = minVal;
    addToSet(inTree, minI);
    addToSet(inTree, minJ);
    removeFromSet(notInTree, minI);
    removeFromSet(notInTree, minJ);

    return newM;
}
void addMinEdgeNode(adjMat* oldMat, adjMat* newMat, set* inTree, set* notInTree)
{
    int minCost=oldMat->mat[0][0], minI=0, minJ=0;
    for (int i=0; i<notInTree->len; ++i)
    {
        for (int j=0; j<inTree->len; ++j)
        {
            if (oldMat->mat[j][i]>0 && oldMat->mat[j][i]<minCost)
            {
                minCost = oldMat->mat[j][i];
                minI = j;
                minJ = i;
            }
        }
    }
    oldMat->mat[minI][minJ] = minCost;
    removeFromSet(notInTree, minI);
    removeFromSet(notInTree, minJ);
    addToSet(inTree, minI);
    addToSet(inTree, minJ);
}
void printMat(adjMat* m)
{
    int len=m->len;
    for (int i=0; i<len; ++i)
    {
        for (int j=0; j<len; ++j)
        {
            printf("%d ", m->mat[i][j]);
        }
        printf("\n");
    }
}
void prims(adjMat* m, set* inTree, set* notInTree)
{
    adjMat* newM = minEdgeMat(m,inTree,notInTree);
    while (notInTree->len>0)
    {
        addMinEdgeNode(m, newM, inTree, notInTree);
    }
    printMat(newM);
}
int main()
{
    set* treeNodes = (set*) malloc(sizeof(set));
    treeNodes->len=0;
    set* notInTreeNodes = (set*) malloc(sizeof(set));
    notInTreeNodes->len=0;
    adjMat* m = (adjMat*) malloc(sizeof(adjMat));
    int input[] = {0,4,4,0,0,0,
                    4,2,0,0,0,0,
                    4,2,0,3,2,0,
                    0,0,3,0,0,3,
                    0,0,2,0,0,3,
                    0,0,4,3,3,0};
    int len=6;
    int ind=0;
    for (int i=0; i<len; ++i)
    {
        addToSet(notInTreeNodes,i);
        for (int j=0; j<len; ++j)
        {
            m->mat[i][j] = input[ind];
            ++ind;
        }
    }
    m->len=len;
    prims(m,treeNodes,notInTreeNodes);
}
