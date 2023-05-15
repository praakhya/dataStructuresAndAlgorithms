import string
def createBadSymbolTable(pattern):
    table={}
    for i in range(0,256):
        table[chr(i)]=len(pattern)
    for i in range(len(pattern)-1):
        table[pattern[i]] = len(pattern)-i-1
    return table

def createGoodSuffixTable(pattern):
    table={}
    lenP = len(pattern)
    for k in range(1,lenP):
        suffix = pattern[lenP-k:lenP]
        suffixIndex = lenP-k
        charBeforeSuffix = pattern[suffixIndex-1]
        lenS=len(suffix)
        patternWithoutSuffix = pattern[0:lenP-lenS]
        lenPws = len(patternWithoutSuffix)
        #print(patternWithoutSuffix,"(",charBeforeSuffix,")",suffix,sep="|")
        #print(lenPws)
        found=False
        #print("Suffix")
        for i in range(lenPws-lenS-1, -1, -1):
            #print("\t",i,"pattern",patternWithoutSuffix[i:i+lenS], "suffix",suffix)
            if patternWithoutSuffix[i:i+lenS] == suffix:
                if (i-1)<0 or patternWithoutSuffix[i-1]!=charBeforeSuffix:
                    table[k] = {"suffix":suffix, "d2": suffixIndex-i}
                    found=True
                    break
        if (not found):
            #print("Prefix")
            ct=0
            for i in range(0,lenS):
                #print("\t",i,pattern[0:i+1], suffix[-(i+1):lenS])
                if (pattern[0:i+1]==suffix[-(i+1):lenS]):
                    ct=i+1
                    #print(ct)
            table[k] = {"suffix":suffix, "d2": lenP-ct}
    print(table)
    return table

def BoyerMooreMatching(text, pattern):
    bst = createBadSymbolTable(pattern)
    gst = createGoodSuffixTable(pattern)
    n = len(text)
    m=len(pattern)
    i=m-1
    while (i<n):
        k=0
        while (k<m and text[i-k]==pattern[m-1-k]):
            k+=1
        if (k==m):
            return i-(m-1)
        elif (k==0):
            d=max(bst[text[i-k]]-k,1)
        else:
            d = max(max(bst[text[i-k]]-k,1),gst[k]["d2"])
        i=i+d
    return -1


if __name__=="__main__":
    pattern = "barber"
    text="jim saw me at a barber shop"
    print("\"{:s}\" matches \"{:s}\" at index: ".format(pattern,text),BoyerMooreMatching(text,pattern))
