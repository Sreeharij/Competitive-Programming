def main(n):
    x_map = {}
    y_map = {}
    for i in range((4*n)-1):
        x,y = map(int,input().split())
        if x in x_map.keys():
            x_map[x] += 1
        else:
            x_map[x] = 1
        if y in y_map.keys():
            y_map[y] += 1
        else:
            y_map[y] = 1
    for key in x_map.keys():
        if x_map[key] %2!= 0:
            x_coord = key
            break
    for key in y_map.keys():
        if y_map[key] %2!= 0:
            y_coord = key
            break
    print(x_coord,y_coord)

for case in range(int(input())):
    n = int(input())
    main(n)
