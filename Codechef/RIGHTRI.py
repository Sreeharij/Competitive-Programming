def right(x1,x2,y1,y2):
    squared_length = ((x1-x2)**2+(y1-y2)**2)
    return squared_length
N = int(input())
count = 0
for i in range(N):
    x1,y1,x2,y2,x3,y3 = map(int,input().split())
    a_square = right(x1,x2,y1,y2)
    b_square = right(x1,x3,y1,y3)
    c_square = right(x2,x3,y2,y3)
    if (a_square+b_square==c_square) or (a_square+c_square==b_square) or (b_square+c_square==a_square):
        count += 1
print(count)
