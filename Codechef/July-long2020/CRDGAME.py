def main(n):
    chef_points = 0
    morty_points = 0
    for i in range(n):
        chef,morty = input().split()
        chef_value = 0
        morty_value = 0
        for digit in chef:
            chef_value += int(digit)
        for digit in morty:
            morty_value += int(digit)
        if chef_value>morty_value:
            chef_points += 1
        elif morty_value>chef_value:
            morty_points += 1
        else:
            chef_points += 1
            morty_points += 1
    if chef_points > morty_points:
        print(0,chef_points)
    elif morty_points > chef_points:
        print(1,morty_points)
    else:
        print(2,chef_points)
for case in range(int(input())):
    n = int(input())
    main(n)

