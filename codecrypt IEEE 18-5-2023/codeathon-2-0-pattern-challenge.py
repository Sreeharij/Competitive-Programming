def func(n):
    counter = 1
    secondary_counter = 0
    for i in range(1,n+1):
        print(i,end=" ")
        val = i
        start = (n+1-2)
        for j in range(i-1):
            val = val + start
            start = start - 1
            print(val,end=" ")
        print()

n = int(input())
if n>0:
    func(n)
else:
    print("INVALID INPUT")

        
