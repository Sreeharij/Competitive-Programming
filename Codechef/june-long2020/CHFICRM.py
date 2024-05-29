def main(N,a):
    available_coin = []
    for i in range(len(a)):
        a[i] = int(a[i])
    for i in range(len(a)):
        if a[i] == 5:
            available_coin.append(5)
        else:
            if (a[i] - 5) in available_coin:
                available_coin.remove((a[i] - 5))
                available_coin.append(a[i])
            elif (a[i] == 15) and available_coin.count(5)>=2:
                available_coin.remove(5)
                available_coin.remove(5)
                available_coin.append(a[i])
            
            else:
                return False
    return True
    

try:
    T = int(input())
    for i in range(T):
        N = int(input())
        a = input().split(' ')
        if main(N,a):
            print("YES")
        else:
            print("NO")
        
except:
    pass
