def main(arr,n):
    count = 0
    arr.sort(reverse = True)
    for i in range(N-1):
        if arr[i]!=arr[i+1]:
            count += 1
    if arr[-1]!=0:
        count +=1
    return count

for case in range(int(input())):
    N = int(input())
    arr = list(map(int,input().split()))
    print(main(arr,N))

