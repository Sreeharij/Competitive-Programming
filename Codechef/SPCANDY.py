for case in range(int(input())):
    N,K = map(int,input().split())
    if K==0:
        print(0,N)
    else:
        print(N//K,N%K)
