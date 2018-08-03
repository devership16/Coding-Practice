def firstUniqChar1(s):
    temp = {}

    for i,c in enumerate(s):
        if c in temp.keys():
            temp[c]=float('inf')
        else:
            temp[c]=i
    res=-1
    for i in range(len(s)):
        if temp[s[i]]==float('inf'):
            continue
        else:
            res = i
            break
    return res

def firstUniqChar(s):
    n = len(s)
    if n == 0:
        return -1
    elif n==1:
        return 0

    res = n

    for i in range(ord('a'),ord('z')+1):
        temp = s.find(chr(i))
        if temp == -1:
            continue
        if temp == s.rfind(chr(i)):
            res = min(res,temp)
    return (res if res<n else -1)

s = "loveleetcode"
print(firstUniqChar(s))
