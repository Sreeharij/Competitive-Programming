for _ in range(int(input())):
    n = int(input())
    s = input()
    count_A = 0
    count_B = 0
    
    server = "alice"
    receiver = "bob"
    
    for i in s:
        if i=='A' and server=="alice":
            count_A += 1
        elif i=='A' and server=='bob':
            server = "alice"
        elif i=='B' and server=="bob":
            count_B += 1  
        elif i=='B' and server=='alice':
            server='bob'
            
    print(count_A,count_B)