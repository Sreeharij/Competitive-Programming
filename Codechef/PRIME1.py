import math

def main(m,n):
    length = n-m + 1
    arr = [True for i in range(length)]

    for number in range(2,int(math.sqrt(n)//1)+1):
        # print(f'number = {number}')
        if m%number == 0:
            num = m
        else:
            num = m + (number - m%number)
        for divisor in range(max(num,2*number),n+1,number):
            # print(f'divisor = {divisor}')
            arr[divisor-m] = False
    for i in range(len(arr)):
        if arr[i] and (i+m)>=2:
            print(i+m)
    print()

for case in range(int(input())):
    m,n = map(int,input().split())
    main(m,n)
