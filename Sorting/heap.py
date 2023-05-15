from math import floor
def heapify(heap, k,n):
    print("\t\theapify: ",heap)
    if (2*k+1 >= n):
        return
    j=2*k+1
    if (j+1<n and heap[j+1] > heap[j]):
        j=j+1
    print("\t\t",k,j,n)
    if (heap[j] > heap[k]):
        temp=heap[j]
        heap[j]=heap[k]
        heap[k]=temp
        heapify(heap,j,n)

def heapBU(heap,ln):
    print("\theapBU: ",heap)
    if ln<=1:
        return
    n = floor((ln-1)/2)
    for i in range(n,-1,-1):
        print("\t",ln,n,i,heap)
        heapify(heap,i,ln)

def heapSort(heap,n):
    print("sort: ",heap)
    if (n<=1):
        return
    heapBU(heap,n)
    temp=heap[0]
    heap[0]=heap[n-1]
    heap[n-1]=temp
    print(heap)
    heapSort(heap,n-1)
    print("sorted=",heap[0:n])
if __name__=="__main__":
    arr=eval(input("Enter heap: "))
    heapSort(arr,len(arr))
    print(arr)

