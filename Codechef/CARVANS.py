def main(speeds,N):
    count = 1
    current_lowest = int(speeds[0])
    for i in range(len(speeds)-1):
        if int(speeds[i])<current_lowest:
            current_lowest = int(speeds[i])
        if int(speeds[i+1])<current_lowest:
            count+=1
    return count


try:
    T = int(input())
    for i in range(T):
        N = int(input())
        speeds = input().split(' ')
        print(main(speeds,N))
except:
    pass
