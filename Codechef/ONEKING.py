def main(arr,N):
    arr.sort()
    l_bound,r_bound = arr[0][0],arr[0][1]
    bomb_count = 1
    for i in range(1,N):
        if arr[i][0] <= r_bound:
            l_bound = arr[i][0]
            r_bound = min(arr[i][1],r_bound)
        else:
            bomb_count += 1
            l_bound,r_bound = arr[i][0],arr[i][1]
    return bomb_count


for case in range(int(input())):
    N = int(input())
    arr = []
    for kingdom in range(N):
        a,b = map(int,input().split())
        arr.append((a,b))
    print(main(arr,N))
