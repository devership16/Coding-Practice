def findMedianSortedArrays(nums1,nums2):
    n = len(nums1)
    m = len(nums2)
    total = n+m
    odd = False
    if (total)%2==0:
        beg, end = (total/2),(total/2)+1
    else:
        odd = True
        med = (total/2)

    for i in range(total):



nums1 = [1, 3]
nums2 = [2]
print(findMedianSortedArrays(nums1,nums2))
