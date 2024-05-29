try:
    A,B = input().split(' ')
    s = int(A) - int(B)
    if str(s)[-1]!='9':
        print(s+1)
    else:
        print(s-1)
except:
    pass
