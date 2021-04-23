
from heapq import *





        # if len(self.bottom) == len(self.top):
        #     # add to bottom and move larger to top
        #     heapq.heappush(self.top, -heapq.heappushpop(self.bottom, -num))
        # else:
        #     heapq.heappush(self.bottom, -heapq.heappushpop(self.top, num))



# Runtime: 196 ms, faster than 59.88% of Python3 online submissions for Find Median from Data Stream.
# Memory Usage: 25.5 MB, less than 67.99% of Python3 online submissions for Find Median from Data Stream.

# week 236 的一道题目(中间K个值的 sum/avg)， 那道是 3个 multi_set 或者 3个heap 。 分成3个部分
# 这道 需要分成 2个部分。 中间的就1/2个值 ... 不需要中间的部分， 直接2个heap， 如果heap的size相等， 就 各自拿一个，如果不想等，就数量多的拿一个。

class MedianFinder:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.mxhp = []      # small    priority     ... 只有 min-heap....  this is max-heap
        self.mnhp = []      # big       min-heap

    # self........或许应该作为 类的静态属性
# pq 不分。。。

    def addNum(self, num: int) -> None:
        if len(self.mxhp) == len(self.mnhp):
            heappush(self.mxhp, -num)
        else:
            heappush(self.mnhp, num)
        # while # ... 失策了，，不如 有序数组，直接切。。这里平衡，，估计耗时挺多的。。 不不不不，想错了。 只需要调整一个元素。
        if len(self.mxhp) > 0 and len(self.mnhp) > 0:
            while -self.mxhp[0] > self.mnhp[0]:
                t2 = -heappop(self.mxhp)
                t3 = heappop(self.mnhp)
                heappush(self.mxhp, -t3)
                heappush(self.mnhp, t2)

    def findMedian(self) -> float:
# Output Limit Exceeded ... 第一次知道还有这个错。。哈哈，print太猛了。。
        # print(self.mxhp)
        # print(self.mnhp)
        if len(self.mxhp) == len(self.mnhp):
            return (-self.mxhp[0] + self.mnhp[0]) / 2
        else:
            return -self.mxhp[0]
            
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

if __name__ == "__main__":
    sol = MedianFinder()
    sol.addNum(1)
    sol.addNum(2)
    print(sol.findMedian())
    sol.addNum(3)
    print(sol.findMedian())