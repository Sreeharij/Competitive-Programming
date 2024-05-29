Q = int(input())
for i in range(Q):
    N = int(input())
    S = input()
    T = input()
    U = input()
    
    shift = ord(T[0]) - ord(S[0])
    if(shift<0):
        shift = shift + 26
    for i in U:
        if(ord(i) + shift > 122):
            print(chr(ord(i)+shift - 122 + 97 - 1),end="")
        else:
            print(chr(ord(i) + shift),end="")
    print()