import sys,numpy as np
def main(c,l,u):
    if c == 0:
        arr[l:u+1] = ~arr[l:u+1]
    else:
        sys.stdout.write(str(np.count_nonzero(arr[l:u+1]))+'\n')

N,Q = map(int,sys.stdin.readline().split())
arr = np.zeros(N,dtype=bool)

for i in range(Q):
    c,l,u = map(int,sys.stdin.readline().split())
    main(c,l,u)
