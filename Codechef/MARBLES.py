def main(n,k):
    posibilities = 1
    if (k>n/2):
        for i in range(n-k):
            posibilities = posibilities*(n-i-1)
            posibilities = posibilities/(i+1)
        return int(posibilities)

    else:
        for i in range(k-1):
            posibilities = posibilities*(n-i-1)
            posibilities = posibilities/(i+1)
        return int(posibilities)

try:
    T = int(input())
    for i in range(T):
        N,K = map(int,input().split(' '))
        print(main(N,K))
except:
    pass
