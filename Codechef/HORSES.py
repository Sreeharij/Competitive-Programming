def main(arr,N):
    minimum = 1000000000
    for i in range(N-1):
        if (arr[i+1]-arr[i])<minimum:
            minimum = (arr[i+1]-arr[i])
    return (minimum)
try:
    T = int(input())
    for i in range(T):
        N = int(input())
        arr = input().split(' ')
        for j in range(len(arr)):
            arr[j] = int(arr[j])
        arr.sort()
        print(main(arr,N))

except:
    pass
