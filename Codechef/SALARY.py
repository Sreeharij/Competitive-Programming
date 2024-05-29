def main(values):
    values = sorted(values)
    total = 0
    for i in range(1,len(values)):
        total += values[i]
    steps = total - values[0]*(len(values)-1)
    return steps

T = int(input())
for _ in range(T):
    N = int(input())
    values = list(map(int,input().split()))
    print(main(values))
