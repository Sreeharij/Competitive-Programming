def main(J,S):
    count = 0
    for letter in S:
        if letter in J:
            count+=1
    return count

try:
    T = int(input())
    for i in range(T):
        J = input()
        S = input()
        print(main(J,S))
except:
    pass
