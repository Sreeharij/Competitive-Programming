import math

def main(N):
    for i in range(1,int(math.sqrt(N))+1):
        if N%i==0:
            factor_lower_than_root = i
            factor_higher_than_root = N//i
    return factor_higher_than_root - factor_lower_than_root

for case in range(int(input())):
    N = int(input())
    print(main(N))
