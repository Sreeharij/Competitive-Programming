def main(arr,N):
    cases = [0 for i in range(N)]
    for i in range(0,N):
        temp_arr = [False for i in range(N)]
        temp_arr[i] = True
        for j in range(0,i):
            if arr[j] > arr[i]:
                temp_arr[j] = True
                for k in range(i+1,N):
                    if arr[k] < arr[j]:
                        temp_arr[k] = True

        for j in range(i+1,N):
            if arr[j] < arr[i]:
                temp_arr[j] = True
                for k in range(0,i):
                    if arr[k] > arr[j]:
                        temp_arr[k] = True
        infected = temp_arr.count(True)
        cases[i] = infected

    best_case = min(cases)
    worst_case = max(cases)

    print(best_case,worst_case)

for case in range(int(input())):
    N = int(input())
    arr = list(map(int,input().split()))
    main(arr,N)

