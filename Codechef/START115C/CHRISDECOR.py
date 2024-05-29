def func(n,x,y):
    if x < n:
        print("NO")
        return
    x = x - n 
    if(n <= x + y/3):
        print("YES")
    else:
        print("NO")
    return

for _ in range(int(input())):
    n,x,y = list(map(int,input().split()))
    func(n,x,y)