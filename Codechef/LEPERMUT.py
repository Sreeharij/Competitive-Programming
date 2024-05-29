def main(N,A):
    inversions = local_inversions = 0
    for i in range(len(A)-1):
        if A[i]>A[i+1]:
            local_inversions += 1
    for i in range(len(A)-1):
        for j in range(i+1,len(A)):
            if A[i] > A[j]:
                inversions += 1

    if inversions == local_inversions:
        return "YES"
    return "NO"

for case in range(int(input())):
    N = int(input())
    A = list(map(int,input().split()))
    print(main(N,A))
