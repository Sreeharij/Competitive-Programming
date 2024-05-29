def main(arr,n,k):
    for i in range(n):
        arr[i] = arr[i]%(k+1)
    # print(arr)
    if arr.count(arr[0])>=(n-1) or arr.count(arr[1])>=(n-1):
        return "YES"
    return "NO"
for case in range(int(input())):
    n,k = map(int,input().split())
    arr = list(map(int,input().split()))
    print(main(arr,n,k))
