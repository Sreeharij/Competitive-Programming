def main(I,N,Q):
    if N%2!=0:
        if I==Q:
            num = N//2 
            return(num)
        else:
            num = N//2 + 1
            return(num)
    else:
        return int((N/2))
        

try:
    T = int(input())
    for i in range(T):
        G = int(input())
        for j in range(G):
            I,N,Q = input().split(' ')
            I,N,Q = int(I),int(N),int(Q)
            print(main(I,N,Q))
except:
    pass
