

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next



# python的  from  import  .. 就是 .h怎么写。 如何把  ListNode 及convert show 打包。


    # dummy = cur = ListNode(0)
    # carry = 0
    # while l1 or l2 or carry:
    #     if l1:
    #         carry += l1.val
    #         l1 = l1.next
    #     if l2:
    #         carry += l2.val
    #         l2 = l2.next
    #     cur.next = ListNode(carry%10)
    #     cur = cur.next
    #     carry //= 10
    # return dummy.next


# StefanPochmann
    # def addTwoNumbers(self, l1, l2):
    #     def toint(node):
    #         return node.val + 10 * toint(node.next) if node else 0
    #     def tolist(n):
    #         node = ListNode(n % 10)
    #         if n > 9:
    #             node.next = tolist(n / 10)
    #         return node
    #     return tolist(toint(l1) + toint(l2))
    # 
    # 
    # def addTwoNumbers(self, l1, l2):
    #     def toint(node):
    #         return node.val + 10 * toint(node.next) if node else 0
    #     n = toint(l1) + toint(l2)
    #     first = last = ListNode(n % 10)
    #     while n > 9:
    #         n /= 10
    #         last.next = last = ListNode(n % 10)
    #     return first
    # 
    # 
    # def addTwoNumbers(self, l1, l2):
    #     addends = l1, l2
    #     dummy = end = ListNode(0)
    #     carry = 0
    #     while addends or carry:
    #         carry += sum(a.val for a in addends)
    #         addends = [a.next for a in addends if a.next]
    #         end.next = end = ListNode(carry % 10)
    #         carry /= 10
    #     return dummy.next

# Runtime: 68 ms, faster than 71.89% of Python3 online submissions for Add Two Numbers.
# Memory Usage: 14.3 MB, less than 72.45% of Python3 online submissions for Add Two Numbers.
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        ans = l1
        prev1 = None
        while l1 and l2:
            l1.val = l1.val + l2.val + carry
            carry = l1.val // 10
            l1.val %= 10
            prev1 = l1
            l1 = l1.next
            l2 = l2.next
        
        if l2:
            prev1.next = l2         # prev2.next = None.
            l1 = l2
        
        while l1:
            l1.val = l1.val + carry
            carry = l1.val // 10
            l1.val %= 10
            prev1 = l1
            l1 = l1.next
        
        if carry > 0:
            n = ListNode(carry, None)
            prev1.next = n          # 之前这里写了  nexxxxt, 竟然没有报错。。 估计是个map..  还以为出了方法，对象就被析构了。 

        return ans



def convert(arr) -> ListNode:
    dummy = ListNode(-1, None)
    pointer = dummy
    for val in arr:
        node = ListNode(val, None)
        pointer.next = node
        pointer = pointer.next
    return dummy.next

def show(node):
    p = node
    while p:
        print(p.val, end = ", ")
        p = p.next
    # print()
    print("            ListNode end.")

if __name__ == "__main__":
    sol = Solution()
    # arr1 = [2,4,3]
    # arr2 = [5,6,4]

    # arr1 = [0]
    # arr2 = [0]

    arr1 = [9,9,9,9,9,9,9]
    arr2 = [9,9,9,9]

    n1 = convert(arr1)
    n2 = convert(arr2)
    show(n1)
    show(n2)

    node = sol.addTwoNumbers(n1, n2)

    show(node)
