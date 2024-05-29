global arr
arr = {}
def main(N):
    n1=N//2
    n2=N//3
    n3=N//4
    if N<12:
        return N
    if N in arr.keys():
        return arr[N]
    arr[N] = main(n1)+main(n2)+main(n3)
    return int(arr[N])
try:
    while True:
        N = int(input())
        print(main(N))
except:
    pass
