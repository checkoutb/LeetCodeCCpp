

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

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