def main(arr,N):
    boolean = True

    for i in range(N):
        if arr[i][0]!=i+1:
            boolean = False
            break

    if boolean:
        return 1

    count = 0
    transposed = False

    if arr[0][1]!=2:
        transposed = True

    for i in range(1,N):
        if (arr[0][i] != i+1) and (transposed ==False):
            count += 1
            transposed = True
        if (arr[0][i]==i+1) and transposed:
            count += 1
            transposed = False

    if arr[0][N-1]!=N:
        count += 1
    return count

for case in range(int(input())):
    N = int(input())
    arr = []
    for row in range(N):
        arr.append(list(map(int,input().split())))
    print(main(arr,N))
