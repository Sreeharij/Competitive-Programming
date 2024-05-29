def main(string):
    if ('010' in string) or ('101' in string):
        return ('Good')
    return ('Bad')

T = int(input())
for _ in range(T):
    string = input()
    print(main(string))
