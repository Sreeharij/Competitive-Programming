def main(P,K):
    loss = 0
    for number in P:
        if int(number) > K:
            loss += (int(number) - K)
    return loss
            
try:
    T = int(input())
    for i in range(T):
        N,K = input().split(' ')
        N,K = int(N),int(K)
        P = input().split(' ')
        print(main(P,K))
except:
    pass
