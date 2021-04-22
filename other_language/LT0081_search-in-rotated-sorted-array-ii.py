
from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        l, r = 0, len(nums)
        while l < r:
            mid = nums[(l + r) // 2]
            if mid == target:
                return True;
            if mid < target:
                # if nums[l] < target:
                if nums[l] < mid:
                    l = mid + 1
                else:
                    # r = mid - 1
                    if nums[l] > target:
                        l = mid + 1
                    else:
                        r = mid - 1
            else:
                if nums[l] < mid:
                    if nums[l] > target:
                        l = mid + 1
                    else:
                        r = mid - 1
                else:
                    if nums[l] > target:
                        r = mid - 1
        return nums[l] == target


# D
        # while l < mid and nums[l] == nums[mid]: # tricky part
        #     l += 1
# 。。。。

            # //If we get here, that means nums[start] == nums[mid] == nums[end], then shifting out
            # //any of the two sides won't change the result but can help remove duplicate from
            # //consideration, here we just use end-- but left++ works too
            # } else {
            #     end--;
            # }
# 。。。。


# .. kan cuo l ... 这个是 另外一道题目的discuss。。。
# Discuss
# if ((nums[0] > target) ^ (nums[0] > nums[mid]) ^ (target > nums[mid]))
# 说明 对比 是可行的。
# 用的是 nums[0]
# 1 0 1 1 1     f^f^f 
# 1 1 1 0 1     f f f
#
# 二分找到min的下标，然后后续二分的时候 加上一个 位置偏移。



# 找到min，然后转成 升序数组，然后二分。。。O(n) + O(n) + O(lgn)
# 不唯一，所以 1 0 1 1 1 分不出左右。。 。。。 set(array).contain(target)

if __name__ == '__main__':
    sol = Solution();
    # arr = [2,5,6,0,0,1,2]
    # # tar = 0
    # tar = 3
    arr = [1,0,1,1,1]
    tar = 0
    print('ans: ' + str(sol.search(arr, tar)));

