
from array import *
from bisect import *
from typing import *

# 想的是，有一个 始终有序的数组， 这样就只需要比较  前后2个 就可以了。 但是好像没有合适的数据结构。。multi_set, map，或许可以。 但是py呢？好像只能手动维护 有序数组。sort太耗时了。
# py 有 lower_bound 吗？  
# bisect --- 数组二分查找算法
# array --- 高效的数值数组
# https://docs.python.org/zh-cn/3.7/library/datatypes.html
# bisect 好像只支持 list ？ array放进去 是自动转为list？ 还是报错？

# array i 是2字节， l 4字节  q:signed long long, 8字节。


class Solution:


# Discuss
# 重复不可能发生，因为插入一个重复值的时候，必然导致 return True....
# 已经有序了，所以只需要 比较 新插入的这个值 和 它前后的 关系。。  
# 代码上，是 lower_bound( newVal - t),看这个范围。这个好像只判断了一半 啊。 bu ,lower_bound(newVal - t)， 得到的 可能小于newVal  也可能大于 newVal.

    # set<int> window; // set is ordered automatically 
    # for (int i = 0; i < nums.size(); i++) {
    #     if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
    #     // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
    #     auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
    #     // x - nums[i] <= t ==> |x - nums[i]| <= t    
    #     if (pos != window.end() && *pos - nums[i] <= t) return true;
    #     window.insert(nums[i]);
    # }



# tle....
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if (len(nums) < 2):
            return False
        # arr = array('q', nums[0 : min(k + 1, len(nums))])
        # print(arr)
        arr = array('q', nums[0 : k + 1])       # 不会越界
        print(arr)
        arr = sorted(arr)
        for idx in range(0, min(k, len(nums) - 1)):
            if arr[idx] + t >= arr[idx + 1]:
                return True

        for idx in range(k + 1, len(nums)):
            t2 = nums[idx - k - 1]
            # print(arr)
            idx2 = self.index(arr, t2)
            arr.pop(idx2)
            t2 = nums[idx]
            idx2 = bisect_left(arr, t2)
            arr.insert(idx2, t2)
            for ii in range(0, k):
                if arr[ii] + t >= arr[ii + 1]:
                    return True
        
        return False

    # copy.
    def index(self, a, x):
        'Locate the leftmost value exactly equal to x'
        i = bisect_left(a, x)
        if i != len(a) and a[i] == x:
            return i
        raise ValueError

if __name__ == "__main__":
    # lst = [1,2,3,1]
    # k = 3
    # t = 0

    # lst = [1,0,1,1]
    # k = 1
    # t = 2

    # lst = [1,5,9,1,5,9]
    # k = 2
    # t = 3

    # lst = [2147483647,-1,2147483647]
    # k = 1
    # t = 2147483647

    lst = [-3,3]
    k = 2
    t = 4


    sol = Solution()
    print("ans: " + str(sol.containsNearbyAlmostDuplicate(lst, k, t)))
