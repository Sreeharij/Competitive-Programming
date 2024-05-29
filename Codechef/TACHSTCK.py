N,D = map(int,input().split())
values = []
for i in range(N):
    values.append(int(input()))
values.sort(reverse=True)
i=0
pair = 0
while i<=(N-2):
    if (values[i]-values[i+1])<=D:
        i+=2
        pair+=1
    else:
        i+=1
print(pair)
