def fibonacci(n):
    if (n<=1):
        return n
    return fibonacci(n-1) + fibonacci(n-2)

if __name__=="__main__":
    n=int(input("Enter n: "))
    print("nth fibonacci number = ",fibonacci(n))