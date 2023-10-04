class Tarjans:
    def __init__(self,edges):
        self.adjacencyMatrix = self.initMatrix(edges)
        self.discoverTime=[0]*len(self.adjacencyMatrix[0])
        self.lowLinkValue=[0]*len(self.adjacencyMatrix[0])
        self.processed=[0]*len(self.adjacencyMatrix[0])
        self.visited=[0]*len(self.adjacencyMatrix[0])
        self.stack=[]
        self.components=[]
    def pathExists(self,u,v):
        if self.adjacencyMatrix[u][v]:
            return True
        return False
    def getComponent(self,root):
        cc=[]
        print(self.stack)
        popped =self.stack.pop()
        while popped != root:
            cc.append(popped)
        cc.append(popped)
        return cc
    def printStatus(self):
        print("dt: ",self.discoverTime)
        print("ll: ", self.lowLinkValue)
        print("p: ",self.processed)
        print("vis: ",self.visited)
        print("stack: ",self.stack)
    def findComponents(self,starting=1):
        for i in range(starting,len(self.adjacencyMatrix[0])):
            self.dfs(i)
    def dfs(self,vertexIndex=1,currentDiscoveryTime=0):
        self.visited[vertexIndex]=1
        self.stack.append(vertexIndex)
        currentDiscoveryTime+=1
        foundUnvisitedVertex=0
        self.discoverTime[vertexIndex] = currentDiscoveryTime
        self.lowLinkValue[vertexIndex] = self.discoverTime[vertexIndex]
        for i in range(len(self.adjacencyMatrix[vertexIndex])):
            self.printStatus()
            if self.pathExists(vertexIndex,i):
                if not self.visited[i]:
                    foundUnvisitedVertex+=1
                    self.dfs(i,currentDiscoveryTime)
                    if self.lowLinkValue[vertexIndex]>self.lowLinkValue[i]:
                        self.lowLinkValue[vertexIndex]=self.lowLinkValue[i]
                elif not self.processed[i]:
                    if self.lowLink[vertexIndex]>self.discoveryTime[i]:
                        self.lowLink[vertexIndex]=self.discoveryTime[i]
        if not foundUnvisitedVertex:
            self.processed[vertexIndex]=1
            if self.discoverTime[vertexIndex]==self.lowLinkValue[vertexIndex]:
                self.components.append(self.getComponent(vertexIndex))
        return
    def initMatrix(self,edges):
        matrix=[]
        nodes = set()
        for (u,v) in edges:
            nodes.add(u)
            nodes.add(v)
        for i in range(max(nodes)+1):
            matrix.append([])
            for j in range(max(nodes)+1):
                matrix[i].append(0)
        for (u,v) in edges:
            matrix[u][v]=1
        return matrix
           
def stronglyConnectedComponents(n, edges):
    t = Tarjans(edges)
    return t.findComponents()  
if __name__=="__main__":

    n = int(input().strip())

    gb = []

    for _ in range(n):
        gb.append(list(map(int, input().rstrip().split())))

    result = 0#componentsInGraph(gb)

    for c in result:
        for i in c:
            print(i,end=" ")
        print()
