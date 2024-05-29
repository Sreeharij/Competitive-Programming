def func(n):
    counter = 1
    for i in range(1,n+1):
        start = int(i*(i+1)/2)
        end = int((i-1)*i/2)
        for number in range(start,end,-1):
            print(number,end=" ")
        print()

n = int(input())
if n>=3:
    func(n)
else:
    print("INVALID INPUT")

        
