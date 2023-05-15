def findMax(arr):
    n = len(arr)
    max=arr[0]
    for i in range(1,n):
        if (arr[i]>max):
            max=arr[i]
    return max

def findMaxDivConq(arr):
    if len(arr)==1:
        return arr[0]
    m=len(arr)//2
    return max(max(arr[0:m]),max(arr[m:len(arr)]))

def findMaxDecConq(arr):
    if len(arr)==1:
        return arr[0]
    return max([arr[0], max(arr[1:len(arr)])])

def findMaxTransConq(arr):
    arr.sort()
    return arr[len(arr)-1]

if __name__=="__main__":
    a = [1,100,2,34,1000,-9,60,0]
    print(findMax(a))
    print(findMaxDivConq(a))
    print(findMaxDecConq(a))
    print(findMaxTransConq(a))

