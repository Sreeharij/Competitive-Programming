for _ in range(int(input())):
    a1,a2,a3,b1,b2,b3 = list(map(int,input().split()))
    score1 = sorted([a1,a2,a3])[-1] + sorted([a1,a2,a3])[-2]
    score2 = sorted([b1,b2,b3])[-1] + sorted([b1,b2,b3])[-2]
    
    if(score1 > score2):
        print("Alice")
    elif (score2 > score1):
        print("Bob")
    else:
        print("Tie")