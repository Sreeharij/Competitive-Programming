def check_perfect_square(num):
    return (int(num**0.5) * int(num**0.5) == num)

for _ in range(int(input())):
    n = int(input())
    flag = False
    if check_perfect_square(n/2):
        flag = True 
    elif check_perfect_square(n/4):
        flag = True 
    if flag:
        print("YES")
    else:
        print("NO")