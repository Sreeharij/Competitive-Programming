for _ in range(int(input())):
    L,v1,v2 = list(map(int,input().split()))
    t1 = L/v1
    t2 = L/v2
    if(t1%1!=0):
        t1 = int(t1) + 1 
    if(t2%1!=0):
        t2 = int(t2) + 1
    diff = t1 - t2 - 1
    if(diff >= 0):
        print(int(diff))
    else:
        print(-1)