def lengthOfLongestSubstring(s):
    if len(s) ==0:
        return 0
    temp=[-1]*256
    maxCount = 1
    count=1
    temp[ord(s[0])]=0

    for i in range(1,len(s)):

        if temp[ord(s[i])] == -1 or temp[ord(s[i])]<i-count:
            count+=1
        else:
            if count>maxCount:
                maxCount=count
            count=i-temp[ord(s[i])]
        temp[ord(s[i])]=i
    return max(maxCount,count)

s = "abcabcbb"
print(lengthOfLongestSubstring(s))
