def partition(arr,l,r):     #Hoare's Partition
    i=l+1
    j=r
    p=l
    while (i<=j):
        while (i<=j and arr[i]<arr[p]):
            i+=1
        while (i<=j and arr[j]>arr[p]):
            j-=1
        if (i<j):
            temp=arr[i]
            arr[i]=arr[j]
            arr[j]=temp
            i+=1
            j-=1
    temp=arr[j]
    arr[j]=arr[p]
    arr[p]=temp
    return j
def quickSort(arr,l,r):
    if (l>=r):
        return
    s = partition(arr,l,r)
    quickSort(arr,l,s-1)
    quickSort(arr,s+1,r)
if __name__=="__main__":
    arr=eval(input("Enter numbers in array: "))
    quickSort(arr,0,len(arr)-1)
    print(arr)


    
        
