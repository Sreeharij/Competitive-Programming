N = int(input())
arr = [int(i) for i in input().split()]
total = 0
frequency = [0 for i in range(30)]
for i in arr:
    for j in range(0,len(bin(i)[2:])):
        if i&(1<<j):
            frequency[j] += 1

for i in range(30):
    total += (frequency[i]*(frequency[i]-1)//2)*(2**i)

print(total)
