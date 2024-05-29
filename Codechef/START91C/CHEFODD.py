def main(n,k):
    if k>(n//2):
        return "NO"
    if n%2==0:
        odd_numbers = n//2
    else:
        odd_numbers = n//2 + 1

    if odd_numbers%2==0:
        if k%2!=0:
            return "NO"
        else:
            return "YES"
    else:
        if k%2!=0:
            return "YES"
        else:
            return "NO"
        
    
for _ in range(int(input())):
    n,k = list(map(int,input().split()))
    print(main(n,k))