def main(N):
    if N==3:
        return 2

    c = N*(N+1)/2
    m1 = (-1 - (1 + 4*c)**(1/2))/2
    m2 = (-1 + (1 + 4*c)**(1/2))/2
    if m1==int(m1) and m1>0:
        ans = (m1-1)*m1/2 + (N-m1-1)*(N-m1)/2 + (N-m1)
    elif m2==int(m2) and m2>0:
        ans = (m2-1)*m2/2 + (N-m2-1)*(N-m2)/2 + (N-m2)
    else:
        m = max(m1,m2)//1
        ans = N-m

    return ans

for case in range(int(input())):
    N = int(input())
    if N%4==3 or N%4==0:
        print(int(main(N)))
    else:
        print(0)


