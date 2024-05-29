def main(N):
    count5=0
    fact=1
    power = 1 
    while N//(5**power)>=1:
        count5 += N//(5**power)
        power += 1
    return count5
        
try:
    T = int(input())
    for i in range(T):
        N = int(input())
        print(main(N))
except:
    pass
