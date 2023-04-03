#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1005
#define MOD 1000000007
#define inf 0x3f3f3f3f
int n, m, dis[MAXN], ways[MAXN], vis[MAXN];
int g[MAXN][MAXN];
typedef struct myQueue
{
    int queue[MAXN][2];
    int front;
    int rear;
} myq;
myq* createQueue() {
    myq* q = (myq*)malloc(sizeof(myq));
    q->front = 0;
    q->rear = 0;
    return q;
}
void destroyQueue(myq* q) {
    free(q);
}
int isEmpty(myq *q)
{
    return q->rear == q->front;
}
void enqueue(int node, int cost, myq *q)
{
/*     if (q->rear > q->front)
    {
        return;
    }
     
    if (q->front == -1)
    {
        q->front = 0;
    }*/
    if (q->rear >= MAXN) {
        printf("Queue Overflow");
        exit(-1);
    }
    q->queue[q->rear][0] = node;
    q->queue[q->rear][1] = cost;
    ++(q->rear);
}
int* dequeue(myq *q)
{
    if (!isEmpty(q))
    {
        int* rv = q->queue[q->front];
        ++(q->front);
        return rv;
    }
    else {
        printf("Queue is empty.");
        exit(-1);
    }
}
typedef struct adjacentNode
{
    int node;
    int cost;
    struct adjacentNode *next;
} adjNode;
typedef struct sourceNode
{
    int node;
    adjNode *next;
} srcNode;

void dijkstraFunction(int roads[2*m][3])
{
    printf("roads\n");
    srcNode *adj[n];
    for (int i=0; i<n; ++i)
    {
        adj[i] = (srcNode *)malloc(sizeof(srcNode));
        adj[i]->next = NULL;
    }
    for (int i = 0; i < 2*m; ++i)
    {
        int src = roads[i][0], dest = roads[i][1], cost = roads[i][2];
        adjNode *newNode = (adjNode *)malloc(sizeof(adjNode));
        newNode->node = dest;
        newNode->cost = cost;
        newNode->next = adj[src]->next;
        adj[src]->next = newNode;
    }
    myq *pq = createQueue();
    for (int i=0; i<n; ++i)
    {
        dis[i] = inf;
    }
    dis[0] = 0;
    ways[0] = 1;
    enqueue(0, 0, pq);
    int mod = (int)(1e9 + 7);
    while (!isEmpty(pq))
    {
        int* e = dequeue(pq);
        int node = e[0];
        int currDis = e[1];

        if (dis[node] < currDis)
            continue;
        adjNode *ptr = adj[node]->next;
        while (ptr != NULL)
        {
            int adjacent = ptr->node;
            int edgeWeight = ptr->cost;
            if (currDis + edgeWeight < dis[adjacent])
            {
                dis[adjacent] = currDis + edgeWeight;
                //printf("Enqueuing %d, %d\n", adjacent, currDis + edgeWeight);
                enqueue(adjacent, currDis + edgeWeight, pq);
                ways[adjacent] = ways[node];
            }
            else if (currDis + edgeWeight == dis[adjacent])
            {
                ways[adjacent] = (ways[adjacent] + ways[node]) % mod;
            }
            /*printf("CurrentNode = %d, ways[adjacent] = %d, Node = %d, EdgeW = %d, dis[adjacent] = %d, currentDis=%d, dis[node]=%d, dis[adjacent]=%d\n", 
            node,
            ways[adjacent],
            ptr->node,
            ptr->cost,
            dis[adjacent],
            currDis,
            dis[node],
            dis[adjacent]);
            ptr = ptr->next;*/
        }
    }
}
void dijkstra(int start)
{
    int roads[2*m][3];
    int k = 0;
/*    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            printf("%d ",g[i][j]);
        }
        printf("\n");
    }*/
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (g[i][j]!=-1)
            {
                roads[k][0] = i;
                roads[k][1] = j;
                roads[k][2] = g[i][j];
                ++k;
            }
        }
    }
    dijkstraFunction(roads);
}
void printAdjList(srcNode** adj) {

    adjNode* p;
    for (int i=0; i<n; ++i)
    {
        p = adj[i]->next;
        printf("%d -> ",i);
        while (p!=NULL)
        {
            printf("%d|%d ",p->node, p->cost);
            p=p->next;
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    memset(g, -1, sizeof(g));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u][v] = g[v][u] = w;
    }
    dijkstra(0);

    printf("%d\n", ways[n - 1]);
     
/*myq* q = createQueue();
enqueue(1, 5, q);
enqueue(2, 4, q);
enqueue(3, 7, q);
enqueue(4, 8, q);
enqueue(5, 2, q);
enqueue(6, 1, q);
while(!isEmpty(q)) {
    int* v = dequeue(q);
    printf("Values are %d %d\n", v[0], v[1]);
}
printf("Is Empty: %d\n", isEmpty(q));
destroyQueue(q);*/
return 0;
}