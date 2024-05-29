def main(arr):
    count = 0
    for i in range(len(arr)-1):
        if arr[i+1]>arr[i]:
            count += arr[i+1]-arr[i]-1
        else:
            count += arr[i]-arr[i+1]-1
    return count

for case in range(int(input())):
    total = int(input())
    arr = list(map(int,input().split()))
    print(main(arr))
