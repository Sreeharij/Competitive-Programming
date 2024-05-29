for _ in range(int(input())):
    n,m = list(map(int,input().split()))
    arr = list(map(int,input().split()))
    total = sum(arr)
    current_fill = total//n
    reminder = total - current_fill*n
    dic = {reminder : current_fill+1 , n-reminder : current_fill}
    if dic[reminder]==m:
        print(reminder)
    elif dic[n-reminder]==m:
        print(n-reminder)
    else:
        print(0)