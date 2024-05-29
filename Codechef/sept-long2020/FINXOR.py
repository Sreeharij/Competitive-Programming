def main(N,arr):
    high_number = N*(1<<20)
    arr_sum = arr[0] - high_number

    if arr_sum%2==0:
        final_answer = 0
    else:
        final_answer = 1

    for i in range(1,20):
        diff = (arr_sum - arr[i])//2**(20-i)
        times = (diff+N)//2
        if times%2!=0:
            final_answer += 2**(20-i)
    print(2,final_answer,flush=True)
    verdict = input()

for case in range(int(input())):
    N = int(input())
    arr = []
    for i in range(20,0,-1):
        print("1",1<<i,flush=True)
        answer = int(input())
        arr.append(answer)
    main(N,arr)




