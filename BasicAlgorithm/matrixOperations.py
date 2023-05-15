def matrixAddition(m1,m2):
    r1=len(m1)
    r2=len(m2)
    c1=len(m1[0])
    c2=len(m2[0])
    if (r1!=r2 or c1!=c2):
        print("Dimension error while adding")
        return (-1,)
    m=[]
    for i in range(r1):
        m.append([0]*c2)
    for r in range(r1):
        for c in range(c1):
            m[r][c]=m1[r][c]+m2[r][c]
    return m
def matrixMultiplication(m1,m2):
    r1=len(m1)
    r2=len(m2)
    c1=len(m1[0])
    c2=len(m2[0])
    if (c1!=r2):
        print("Dimension error while multiplying")
        return (-1,)
    m=[]
    for i in range(r1):
        m.append([0]*c2)
    for i in range(r1):
        for j in range(c1):
            for k in range(c2):
               m[i][k]+=m1[i][j]*m2[j][k]
    return m
def printMatrix(m):
    for i in range(len(m)):
        for j in range(len(m[0])):
            print(m[i][j],end="\t")
        print()
if __name__=="__main__":
    m1=eval(input("Enter matrix 1: "))
    m2=eval(input("Enter matrix 2: "))
    sum=matrixAddition(m1,m2)
    prod=matrixMultiplication(m1,m2)
    if (sum!=(-1,)):
        print("m1+m2=",sum)
    if (prod!=(-1,)):
        print("m1*m2=",prod)
