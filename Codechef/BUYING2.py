def main(N,X,arr):
    total = sum(arr)
    smallest = min(arr)
    sweets = total//X
    if total%X==0:
        return sweets
    else:
        if sweets <= (total-smallest)//X:
            return -1
        else:
            return sweets

for case in range(int(input())):
    N,X = map(int,input().split())
    arr = list(map(int,input().split()))
    print(main(N,X,arr))
