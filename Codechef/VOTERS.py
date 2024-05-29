mapper = {}
first,second,third = map(int,input().split())
for i in range(first+second+third):
    number = int(input())
    if number in mapper.keys():
        mapper[number] += 1
    else:
        mapper[number] = 1
new = []
for element in mapper:
    if mapper[element]>1:
        new.append(element)
print(len(new))
for element in sorted(new):
    print(element)
