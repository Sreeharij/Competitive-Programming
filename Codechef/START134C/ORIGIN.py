for _ in range(int(input())):
    n = int(input())
    val = (n//9) * 45 + (n%9)*(n%9+1)//2
    print(val)
