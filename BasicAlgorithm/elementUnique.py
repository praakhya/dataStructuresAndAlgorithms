def arrHasUnique(arr):
    sortedArr = arr.sort()
    for i in range (1,len(arr)):
        if arr[i]==arr[i-1]:
            return 0
    return 1
if __name__=="__main__":
    arr=eval(input("Enter numbers: "))
    if (arrHasUnique(arr)):
        print("The elements in the array are unique")
    else:
        print("The array has duplicates")