N = int(input())
stamps = list(map(int,input().split()))
if sum(stamps)==(N*(N+1)/2):
    print("YES")
else:
    print("NO")
