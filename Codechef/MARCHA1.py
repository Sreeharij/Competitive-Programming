def main(arr,required_sum,n):
    for i in range(1,2**n):
        current_sum = 0
        num = bin(i)
        for j in range(-1,-21,-1):
            if num[j]=='b':
                break
            if num[j]=='1':
                current_sum += arr[j]
        if current_sum==required_sum:
            return "Yes"
    return "No"

for case in range(int(input())):
        n,m = map(int,input().split())
        arr = []
        for note in range(n):
            x = int(input())
            if x<=m:
                arr.append(x)
        print(main(arr,m,len(arr)))
