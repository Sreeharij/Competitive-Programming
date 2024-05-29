for _ in range(int(input())):
    n = int(input())
    if n%2 == 0:
        mini = n/2
    else:
        mini = n//2 + 1 
    print(int(mini),n)