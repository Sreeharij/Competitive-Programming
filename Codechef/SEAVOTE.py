for case in range(int(input())):
    N = int(input())
    B = [int(i) for i in input().split()]
    total = sum(B)
    N = N - B.count(0)
    if ((total) >=(100) and (total-N)<100) :
        print('YES')
    else:
        print('NO')
