def main(health,attack):
    while attack!=0:
        if health<=0:
            break
        health -= attack
        attack //= 2
    if health<=0:
        return 1
    else:
        return 0

for case in range(int(input())):
    H,P = map(int,input().split())
    print(main(H,P))
