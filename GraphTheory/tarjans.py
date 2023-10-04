#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'componentsInGraph' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts 2D_INTEGER_ARRAY gb as parameter.
#
def dfsTarjan():
    pass
        
        
def makeAdjMat(gb, nodes):
    mat = []
    for i in range(max(nodes)+1):
        mat.append([])
        for j in range(max(nodes)+1):
            mat[i].append(0)
    for e in gb:
        mat[e[0]][e[1]]=1
    return mat

def getVertices(gb):
    verts=set()
    for e in gb:
        verts.add(e[0])
        verts.add(e[1])
    return verts

def printAdjMat(mat):
    print("\t",end="")
    for i in range(len(mat)):
        print(i,end="|\t")
    print()
    i=0
    for row in mat:
        print(i,end="|\t")
        for val in row:
            print(val,end="\t")
        print()
        i+=1
        
def dfsForSCC(vi, matrix, processed, stack, discoveryTime, lowLink, components, visited, dtcounter=0):
    dtcounter+=1
    discoveryTime[vi]=dtcounter
    lowLink[vi]=discoveryTime[vi]
    stack.append(vi)
    foundUnvisited=0
    print("vi = ",vi)
    print("ll[{:d}]: ".format(vi), lowLink[vi])
    print("dt[{:d}]: ".format(vi), discoveryTime[vi])
    for adji in range(len(matrix[vi])):
        print("     adji: ",adji)
        print("     ",vi,"->",adji,": ",matrix[vi][adji])
        if matrix[vi][adji]:
            print("     adji visited: ",visited[adji])
            if not visited[adji]:
                visited[adji]=1
                foundUnvisited=1
                dfsForSCC(adji, matrix, processed, stack, discoveryTime, lowLink, components, dtcounter)
                if lowLink[vi]>lowLink[adji]:
                    lowLink[vi] = lowLink[adji]
            elif not processed[adji]:
                if lowLink[vi]>discoveryTime[adji]:
                    lowLink[vi]=discoveryTime[adji]
            print("     ll[{:d}]: ".format(adji),lowLink[adji])
            print("     dt[{:d}]: ".format(adji),discoveryTime[adji])
    if not foundUnvisited:
        processed[vi]=1
        if discoveryTime[vi]==lowLink[vi]:
            cc=[]
            vert = stack.pop()
            while vert!=vi:
                cc.append(vert)
                vert = stack.pop()
            cc.append(vert)
            components.append(cc)
    print("processed: ",processed)
    print("visited: ",visited)
    return
            
def componentsInGraph(gb):
    verts = getVertices(gb)
    nodes=getVertices(gb)
    matrix = makeAdjMat(gb, nodes)
    stack=[]
    processed={}
    discoveryTime={}
    lowLink={}
    components=[]
    visited={}
    printAdjMat(matrix)
    for v in verts:
        processed[v]=0
        discoveryTime[v]=0
        lowLink[v]=0
        visited[v]=0

    
    dfsForSCC(1, matrix, processed, stack, discoveryTime, lowLink, components,visited)
    print(components)
    return min(components, key=len), max(components, key=len)
    
    # Write your code here

if __name__ == '__main__':

    n = int(input().strip())

    gb = []

    for _ in range(n):
        gb.append(list(map(int, input().rstrip().split())))

    result = componentsInGraph(gb)

    print(' '.join(map(str, result)))
    