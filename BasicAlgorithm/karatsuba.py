def karatsuba(a, b):
    n = len(str(a))
    a=list(str(a))
    a = list(map(lambda x: int(x), a))
    b=list(str(b))
    b = list(map(lambda x: int(x), b))
    if (n==1):
        return a[0]*b[0]
    if (n%2!=0):
        a[n]=0
        b[n]=0
        n=n+1
    m=n//2
    a1 = a[:m]
    a2 = a[m+1:n+1]
    b1 = b[:m]
    b2 = b[m+1:n+1]
    suma12 = list(str(int("".join(str(a) for a in a1))+int("".join(str(a) for a in a2))))
    sumb12 = list(str(int("".join(str(a) for a in b1))+int("".join(str(a) for a in b2))))
    p1 = karatsuba(a1[0:m],b1[0:m])
    p2 = karatsuba(a2[0:m],b2[0:m])
    p3 = karatsuba(suma12[0:m+1],sumb12[0:m+1])
    return (p1*(10**n) + (p3-p1-p2)*(10**(n//2)) + p2)[0:2*n]
if __name__=="__main__":
    print("%d",karatsuba(3050,1401))    
