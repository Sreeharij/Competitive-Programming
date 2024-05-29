arr1 = [0,1,0,1,0,1,0,1]
arr2 = [1,0,1,0,1,0,1,0]
array = []
for i in range(4):
    array.append(arr1)
    array.append(arr2)

letter,number = input().split()
number = int(number)

row = 8 - number
dictionary = {'a':0,
              'b':1,
              'c':2,
              'd':3,
              'e':4,
              'f':5,
              'g':6,
              'h':7,}
column = dictionary[letter]

counter = 0

if (row-2)>=0 and (column+1)<=7:
    if array[row-2][column+1]==1:
        counter += 1

if (row-2)>=0 and (column-1)>=0:
    if array[row-2][column-1]==1:
        counter += 1

if (row+2)<=7 and (column+1)<=7:
    if array[row+2][column+1]==1:
        counter += 1

if (row+2)<=7 and (column-1)>=0:
    if array[row+2][column-1]==1:
        counter += 1

if (column+2)<=7 and (row+1)<=7:
    if array[column+2][row+1]==1:
        counter += 1

if (column+2)<=7 and (row-1)>=0:
    if array[column+2][row-1]==1:
        counter += 1

if (column-2)>=0 and (row+1)<=7:
    if array[column-2][row+1]==1:
        counter += 1

if (column-2)>=0 and (row-1)>=0:
    if array[column-2][row-1]==1:
        counter += 1
print(counter)