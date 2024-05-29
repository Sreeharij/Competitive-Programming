def main(arr,N,position):
    greater=smaller=0
    for i in range(N):
        if i<=position:
            if int(arr[i])>int(arr[position]):
                greater +=1
        elif i>=position:
            if int(arr[i])<int(arr[position]):
                smaller +=1
    return(position-greater+smaller+1)

try:
    T = int(input())
    for i in range(T):
        N = int(input())
        arr = input().split(' ')
        position = int(input())-1
        print(main(arr,N,position))
        
except:
    pass
