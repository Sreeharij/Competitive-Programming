for _ in range(int(input())):
    n = int(input())
    arr = input()
    count = 1
    repeat_flag = True
    for i in range(1,len(arr)):
        if(arr[i] == arr[i-1]):
            if repeat_flag == False:
                count += 1 
                repeat_flag = True
            else:
                repeat_flag = False
        else:
            repeat_flag = True
            count += 1

    print(count)