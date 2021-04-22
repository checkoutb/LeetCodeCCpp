
# from LT0002_add-two-numbers import *
# import LT0002_add-two-numbers             # 好像不能有  -  ?
from typing import List
# import mylistnode             # 这个得 mylistnode.ListNode, 不能直接ListNode。
from mylistnode import *            # ok
from heapq import *



        # heap = [(l.val, i, l) for i, l in enumerate(lists) if l]
        # heapq.heapify(heap)
        # while heap:
        #     _, i, node = heapq.heappop(heap)
        #     pre.next = node
        #     pre = node
        #     if node.next:
        #         heapq.heappush(heap, (node.next.val, i, node.next))

    # from heapq import heappush, heappop, heapreplace, heapify
    # dummy = node = ListNode(0)
    # h = [(n.val, n) for n in lists if n]
    # heapify(h)
    # while h:
    #     v, n = h[0]
    #     if n.next is None:
    #         heappop(h) #only change heap size when necessary
    #     else:
    #         heapreplace(h, (n.next.val, n.next))
    #     node.next = n
    #     node = node.next



# Runtime: 104 ms, faster than 65.32% of Python3 online submissions for Merge k Sorted Lists.
# Memory Usage: 17.8 MB, less than 65.48% of Python3 online submissions for Merge k Sorted Lists.

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        
        # (ordered_)map....
        # heap, priority_queue
        # pair ?

        hp = []
        for idx in range(0, len(lists)):
            node = lists[idx]
            if (node != None):
                heappush(hp, [node.val, idx])
                lists[idx] = node.next
        ans = p = ListNode(-1, None)
        
        while len(hp) > 0:          # empty(hq) ?
            mnarr = heappop(hp)
            node = ListNode(val = mnarr[0])
            # print("." + str(mnarr[0]))
            p.next = node
            p = p.next
            i3 = mnarr[1]
            if lists[i3]:       # != None
                heappush(hp, [lists[i3].val, i3])
                lists[i3] = lists[i3].next

        return ans.next



if __name__ == "__main__":
    # arr2 = [[1,4,5],[1,3,4],[2,6]]
    arr2 = []

    # lst = []
    # for
    lst = [convert(arr) for arr in arr2]                # ?can， yes
    for l in lst:
        show(l)
    
    # lst = []

    sol = Solution()
    ans = sol.mergeKLists(lst)
    show(ans)
    
