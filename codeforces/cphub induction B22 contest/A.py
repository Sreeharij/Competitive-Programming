list2 = ['A','M','T','U','V','W','Y','H','I','O','X']
list1 = ['B','C','D','E','H','I','K','O','X']
def horizontal(word):
    arr = [(letter in list1) for letter in word]
    if False not in arr:
        return True
    return False
        

def func(word):
    if len(word) == 1:
        if ((word[0] not in list1) and (word[0] not in list2)):
            return "NO"
    for i in word:
        if i not in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            return "NO"
    if horizontal(word):
       return "YES"
    mid = len(word)//2
    vertical = True
    for i in range(mid):
        if(word[i] != word[len(word)-i-1]):
            vertical = False
        if word[i] not in list2:
            vertical = False
    if len(word)%2!=0:
        if word[mid] not in list2:
            vertical = False
    if vertical:
        return "YES"
    else:
        return "NO"
    
word = input()
print(func(word))
