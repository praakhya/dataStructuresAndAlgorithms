def heapifyTD(heap, k):
    n = len(heap)
    if (k==0):
        print("After heapify: ",heap)
        return
    j=(k-1)//2
    if (heap[k]>heap[j]):
        temp = heap[j]
        heap[j] = heap[k]
        heap[k] = temp
        heapifyTD(heap,j)
def heapifyBU(heap,k):
    n=len(heap)
    print("n=",n,"k=",k,"parent=",k,end=", ")
    c=2*k+1
    if (c>=n):
        return
    if(c+1<n):
        if(heap[c+1]>heap[c]):
            c=c+1
    print("child=",c)
    if(heap[c]>heap[k]):
        temp=heap[c]
        heap[c]=heap[k]
        heap[k]=temp
        print("swap")
        heapifyBU(heap,c)
def heapBottomUp(heap):
    n = len(heap)
    if (n<=1):
        print("After heapBottomUp: ",heap)
        return
    for i in range(n//2, -1, -1):
        heapifyBU(heap,i)
        print("After heapBottomUp: ",heap)

def heapTopDown(heap):
    n=len(heap)
    for i in range(1,n):
        #print("Current=[{:d}:{:d}], Parent=[{:d}:{:d}]".format(i,heap[i],p,heap[p]))
        heapifyTD(heap,i)
        
def heapSort(heap):
    heapBottomUp(heap)
    n=len(heap)
    print("HEAP:",heap)
    for i in range(n-1,2,-1):
        heap[0]=heap[i]
        heapifyBU(heap,0)
    
if __name__=="__main__":
    numbers=[]
    print("Enter numbers to insert:-")
    c=input("")
    while (c!="."):
        numbers.append(int(c))
        c=input("")
    print("Numbers: ",numbers)
    heapSort(numbers)
    print("Heap: ",numbers)