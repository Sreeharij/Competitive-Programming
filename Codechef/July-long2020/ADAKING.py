def main(k):
    lines = k//8
    col = k%8
    for loop in range(lines):
        if loop==0:
            print("O.......")
        else:
            print("........")
    if col!=0:
        for loop in range(8):
            if loop==0 and lines==0:
                print("O",end="")
            elif loop < col:
                print(".",end="")
            else:
                print("X",end="")
        print()
    if (lines+1)<8 :
        print("XXXXXXXX")
        if col==0:
            rest = 8-lines-1
        else:
            rest = 8-lines-2
        for loop in range(rest):
            print("........")
    else:
        pass
for case in range(int(input())):
    k = int(input())
    if k==56:
        print("O.......")
        for i in range(6):
            print("........")
        print("XXXXXXXX")
    else:
        main(k)
