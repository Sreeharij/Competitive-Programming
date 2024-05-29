N = int(input())
sentence = input()

flag = True
for i in range(0,N-1):
    if sentence[i]==sentence[i+1]:
        flag = False
        break
if flag:
    print("Yes")
else:
    print("No")