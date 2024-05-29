for _ in range(int(input())):
    x,y = list(map(int,input().split()))
    
    if x < 1000:
        x = x + 1000
        y -= 1 
        
    while(y > 0):
            x = x * 2
            y -= 1 
    print(x)