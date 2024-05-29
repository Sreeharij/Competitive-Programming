def main(W,K):
    val1 = val2 = 0
    if K>len(W)//2:
        for i in range(-1,-(K+1),-1):
            val1 += W[i]
        for i in range(-len(W),-K,1):
            val2 += W[i]
        return val1-val2
    else:
        for i in range(K,len(W)):
            val1 += W[i]
        for i in range(0,K):
            val2 += W[i]
        return val1-val2
try:
    T = int(input())
    for i in range(T):
        N,K = map(int,input().split(' '))
        W = list(map(int,input().split(' ')))
        W.sort()
        val = main(W,K)
        print(val)
except:
    pass
