for _ in range(int(input())):
    N = int(input())
    S = input()
    
    flag = False
    count = 0
    bracket_count = 0
    for i in S:
        if i==":":
            if not flag:
                flag = True 
            else:
                if bracket_count>0:
                    count += 1
                    bracket_count = 0
        elif i==")":
            if flag:
                bracket_count += 1
        else:
            if flag:
                flag = False
                bracket_count = 0
    print(count)
            