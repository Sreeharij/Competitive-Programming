def main(N,S):
    n = S.count('1')
    return int(n*(n+1)/2)

try:
    T = int(input())
    for i in range(T):
        N = int(input())
        S = input()
        print(main(N,S))
except:
    pass
