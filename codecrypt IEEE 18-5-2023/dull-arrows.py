a,b,c = list(map(int,input().split()))
counter = 0
for i in (a,b,c):
    if (i>0) and (i<=50):
        counter += 3
    elif (i>50) and (i<=100):
        counter += 5
    elif (i>100) and (i<=200):
        counter += 8
print(counter)