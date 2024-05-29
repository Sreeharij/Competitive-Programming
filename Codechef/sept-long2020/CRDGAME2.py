high_num = 1000000007

def combination(k):
    r = k//2
    numerator = 1
    denominator = 1
    j = 1
    for i in range(k,r,-1):
        numerator = (numerator*i)%high_num
        denominator = (denominator*j)%high_num
        j+= 1
    return numerator*pow(denominator,high_num-2,high_num)%high_num

for case in range(int(input())):
    N = int(input())
    arr = list(map(int,input().split()))
    highest = max(arr)
    freq = arr.count(highest)

    if freq%2==0:
        comb = combination(freq)
        ans = ( (2**(N-freq))%high_num * (2**freq%high_num - comb)%high_num )%high_num
        print(int(ans%high_num))
    else:
        print(int((2**N)%high_num))
