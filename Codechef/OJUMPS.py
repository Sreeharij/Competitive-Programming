a = int(input())
remaining = a%6
if remaining in (0,1,3,6):
    print("yes")
else:
    print("no")
