#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *next;
    int vertex;
} node;
node *G[20];
// heads of linked list
int visited[20];
int n;
void read_graph();
// create adjacency list
void insert(int, int);
// insert an edge (vi,vj) in te adjacency list
void DFS(int);
void show_graph();

int main()
{
    int i;
    read_graph();
    // initialised visited to 0

    for (i = 0; i < n; i++)
        visited[i] = 0;
    DFS(0);
    return 0;
}
void printNode(int i)
{
    printf("%d -> %d\n", G[i]->vertex, G[i]->next != NULL ? G[i]->next->vertex : -1);
}
void DFS(int i)
{
    // printf("i=%d: ",i);
    // printNode(i);
    if (!visited[i])
    {
        printf("%d\n", i); // print current node with value i
        visited[i] = 1;    // mark i visited
        node *p = G[i];
        while (p != NULL) // Looping through all children of i
        {
            DFS(p->vertex); // Recursive call to function to get all children of current p
            p = p->next;    // Repeat loop for next p
        }
    }
}
void read_graph()
{
    int i, vi, vj, no_of_edges;

    scanf("%d", &n);
    // initialise G[] with a null

    for (i = 0; i < n; i++)
    {
        G[i] = NULL;
        // read edges and insert them in G[]

        scanf("%d", &no_of_edges);
        for (i = 0; i < no_of_edges; i++)
        {
            scanf("%d%d", &vi, &vj);
            insert(vi, vj);
        }
    }
}
void show_graph()
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d: %d | ", i, G[i]->vertex);
        node *p = G[i]->next;
        while (p != NULL)
        {
            printf("%d ", p->vertex);
            p = p->next;
        }
        printf("\n");
    }
}
void insert(int vi, int vj)
{
    node *p, *q;

    // acquire memory for the new node
    q = (node *)malloc(sizeof(node));
    q->vertex = vj;
    q->next = NULL;
    // insert the node in the linked list number vi
    if (G[vi] == NULL)
        G[vi] = q;
    else
    {
        // go to end of the linked list
        p = G[vi];

        while (p->next != NULL)
            p = p->next;
        p->next = q;
    }
}