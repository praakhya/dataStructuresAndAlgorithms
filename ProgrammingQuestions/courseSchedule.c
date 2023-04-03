#include <stdio.h>
#include <stdlib.h>

#define MAX_COURSES 10000

int visited[MAX_COURSES];
int stack[MAX_COURSES];
int top = -1;

typedef struct node
{
    int vertex;
    struct node *next;
} node;
node *adjList[MAX_COURSES];
void printAdjList(int n)
{
    for (int i = 0; i < n; ++i)
    {
        node *p = adjList[i];
        while (p != NULL)
        {
            printf("%d ", p->vertex);
            p = p->next;
        }
        printf("\n");
    }
}
/* void printArr(int n, int arr[n])
{
    for (int i=0; i<n; ++i)
    {
        printf("%d ");
    }
    printf("\n");
}
 */
void addEdge(int dest, int src)
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->vertex = dest;
    newNode->next = NULL;
    adjList[dest] = (node *)malloc(sizeof(node));
    adjList[dest]->vertex = dest;
    adjList[dest]->next = NULL;         //Creating a new destination node in the adjacency list
    if (adjList[src] == NULL)           //If the index of the src in the adjacency list is NULL, assign a node to it
    {
        adjList[src] = (node *)malloc(sizeof(node));
        adjList[src]->vertex = src;
        adjList[src]->next = NULL;
    }
    node *p = adjList[src];
    while (p->next != NULL)         //Find the end of the singly linked list at the src
    {
        p = p->next;
    }
    p->next = newNode;              //Add the new node at the end of this singly linked list
}
void dfs(node *p)
{
    if (!visited[p->vertex]) //If a vertex is not visited
    {
        visited[p->vertex] = 1; //make the vertex visited
        if (p->next == NULL)    //If the next vertex is a leaf
        {
            stack[++top] = p->vertex;   //Push the vertex onto the stack
            return;
        }
        dfs(p->next);   //call dfs for next vertex
        stack[++top] = p->vertex;   //Push the vertex onto stack
    }
}
void topologicalSort(int numCourses)
{
    for (int i = 0; i < numCourses; ++i)
    {
        if (!visited[adjList[i]->vertex]) //apply dfs on every vertex (connected or disconnected)
        {
            dfs(adjList[i]);
        }
    }
    // printf("top=%d\n",top);
    for (int i = 0; i <= top; ++i)  //Printing the stack from top to bottom (order of popping of stack)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int numCourses, n;
    scanf("%d%d", &numCourses, &n);
    for (int i = 0; i < n; i++)
    {
        int src, dest;
        scanf("%d%d", &src, &dest);
        addEdge(dest, src);
    }
    // printAdjList(numCourses);
    topologicalSort(numCourses);
    return 0;
}