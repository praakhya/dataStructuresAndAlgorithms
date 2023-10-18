#include <iostream>
#include <vector>
#include <queue>
#include <climits>

class Graph {
    public:
    int vertexCount;
    std::vector<std::vector<int> > adjacencyMatrix;
    
    Graph(int numVertices, int numEdges, std::vector<std::vector<int> > edgeSet) {
        vertexCount = numVertices;
        adjacencyMatrix.resize(vertexCount);
        for (int i=0; i<numVertices; ++i) {
            adjacencyMatrix[i].resize(vertexCount);
            for (int j=0; j<numVertices; ++j) {
                adjacencyMatrix[i][j]=0;
            }
        }
        for (auto edge:edgeSet) {
            int src = edge[0], dest = edge[1], wt = edge[2];
            adjacencyMatrix[src][dest] = wt;
        }
    }
    int bfs(int src, int dest, std::vector<int>&parent) {
        std::queue<int> queue;
        std::vector<int> visited(vertexCount,0);
        visited[src]=1;
        queue.push(src);
        int currentNode;
        while (!queue.empty()) {
            currentNode=queue.front();
            queue.pop();
            for (int neighbour=0; neighbour<vertexCount; ++neighbour) {
                if (adjacencyMatrix[currentNode][neighbour] && !visited[neighbour]) {
                    visited[neighbour]=1;
                    parent[neighbour]=currentNode;
                    queue.push(neighbour);
                }
            }
        }
        if (visited[dest]) {
            return 1;
        }
        return 0;
    }
    std::pair<int, std::vector<std::vector<int> > > MaxFlow(int source, int destination) {     //Maximum flow using Ford Fulkerson
        std::vector<int> parent(vertexCount);
        for (int i=0; i<parent.size(); ++i) {
            parent[i]=-1;
        }
        int maximumFlow=0;
        std::vector<std::vector<int> > allPaths;
        std::vector<int> currentPath;
        while (bfs(source, destination, parent)) {
            int flow = INT_MAX;
            int currentNode = destination;
            while (currentNode != source) {
                flow = std::min(flow, adjacencyMatrix[parent[currentNode]][currentNode]);
                currentPath.insert(currentPath.begin(), currentNode);
                currentNode = parent[currentNode];
            }
            currentPath.insert(currentPath.begin(), currentNode);
            allPaths.push_back(currentPath);
            maximumFlow+=flow;
            currentNode = destination;
            while (currentNode!=source) {
                int immediateParent = parent[currentNode];
                adjacencyMatrix[immediateParent][currentNode] -= flow;
                adjacencyMatrix[currentNode][immediateParent] += flow;
                currentNode = immediateParent;
            }
            currentPath.clear();
        }
        std::pair<int, std::vector<std::vector<int> > > result;
        result.first = maximumFlow;
        result.second = allPaths;
        return result;
    }
};
void addEdge(std::vector<std::vector<int> >& graph, int from, int to, int capacity) {
    std::vector<int> edge;
    edge.push_back(from);
    edge.push_back(to);
    edge.push_back(capacity);
    graph.push_back(edge);
}
std::pair<int, std::vector<std::vector<int> > > fordFulkerson(int n, int e, std::vector<std::vector<int> > graph, int source, int sink) {
    Graph* g = new Graph(n,e,graph);
    return g->MaxFlow(source, sink);

} 
struct Edge {
    int to, capacity, flow;
};
int main() {
    int n; // Number of nodes
    std::cin >> n;

    std::vector<std::vector<int> > graph;

    int m; // Number of edges
    std::cin >> m;

    std::cout << "Enter the edges and capacities (from to capacity):" << std::endl;
    for (int i = 0; i < m; i++) {
        int from, to, capacity;
        std::cin >> from >> to >> capacity;
        addEdge(graph, from, to, capacity);
    }

    int source, sink;
    std::cin >> source;
    std::cin >> sink;

    std::pair<int, std::vector<std::vector<int> > > result = fordFulkerson(n, graph.size(), graph, source, sink);

    std::cout << result.first << std::endl;

    for (int i=0; i<result.second.size(); ++i) {
        for (int j=0; j<result.second[i].size(); ++j) {
            std::cout << result.second[i][j] <<" ";
        }
        std::cout << std::endl;
    }

    return 0;
}