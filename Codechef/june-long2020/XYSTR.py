def main(S):
    x = 0
    y = 0
    pair = 0
    i=0
    while i <= (len(S)):
        if i>=len(S)-1:
            break
        if S[i] == 'x' and S[i+1] == 'y':
            pair +=1
            i+=2
        elif S[i] == 'y' and S[i+1] == 'x':
            pair +=1
            i+=2
        else:
            i+=1
    return pair
            



T = int(input())
for i in range(T):
    S = input()
    print(main(S))
        
