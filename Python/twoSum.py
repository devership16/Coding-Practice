def twoSum(nums,target):
    temp={}
    for i, element in enumerate(nums):
        if element in temp.keys():
            return [temp[element],i]
        else:
            temp[target - element]=i
    print(temp)

nums = [2,7,11,15]
target = 9
print(twoSum(nums,target))
