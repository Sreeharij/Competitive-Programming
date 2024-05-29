def main(chef,rick):
    if chef%9==0:
        chef_digit = chef//9
    else:
        chef_digit = chef//9 + 1
    if rick%9==0:
        rick_digit = rick//9
    else:
        rick_digit = rick//9 + 1
    if rick_digit<=chef_digit:
        print(1,rick_digit)
    else:
        print(0,chef_digit)

for case in range(int(input())):
    chef,rick = map(int,input().split())
    main(chef,rick)
