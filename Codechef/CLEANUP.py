def main(arr,n):
    total_job = [str(i) for i in range(1,n+1)]
    if arr[0]!='':
        for job in arr:
            total_job.remove(job)
    chef = []
    assistant = []
    for i in range(1,len(total_job)+1):
        if i%2!=0:
            chef.append(total_job[i-1]) 
        else:
            assistant.append(total_job[i-1])
    return (chef,assistant)
    
try:
    T = int(input())
    for i in range(T):
        n,m = input().split(' ')
        n,m = int(n),int(m)
        arr = input().split(' ')
        for item in (main(arr,n)):
            if len(item)==0:
                print()
            else:
                for j in range(len(item)):
                    if j!=len(item)-1:
                        print(item[j],end=" ")
                    else:
                        print(item[j],end="\n")
except:
    pass
