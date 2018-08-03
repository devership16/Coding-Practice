def removeDuplicate(nums):
    return list(set(nums))

def removeDuplicate1(nums):
    res = []
    for item in nums:
        if item in res:
            continue
        res.append(item)
    return res

if __name__=='__main__':
    nums = [2, 4, 10, 20, 5, 2, 20, 4]
    result = removeDuplicate1(nums)
    print result
