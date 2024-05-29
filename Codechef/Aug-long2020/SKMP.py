for case in range(int(input())):
    S = list(input())
    P  = input()
    for i in P:
        S.remove(i)
    S.sort()
    new1 = new2 = ""
    obj = len(S)-sorted(S+[P[0]],reverse=True).index(P[0])
    new1 += ''.join(S[0:obj]) + P + ''.join(S[obj:])
    if P[0] in S:
        for i in range(0,S.index(P[0])):
            new2 += S[i]
        new2 += P
        for i in range(S.index(P[0]),len(S)):
            new2 += S[i]
        print(min(new1,new2))
    else:
        print(new1)
