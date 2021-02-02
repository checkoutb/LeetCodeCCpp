
#include "../header/myheader.h"

class LT0148
{
public:

// D D

// fast-slow pointer to get half of ListNode


//    if (head == null || head.next == null)
//      return head;
//    // step 1. cut the list to two halves
//    ListNode prev = null, slow = head, fast = head;
//    while (fast != null && fast.next != null) {
//      prev = slow;
//      slow = slow.next;
//      fast = fast.next.next;
//    }
//    prev.next = null;
//    // step 2. sort each half
//    ListNode l1 = sortList(head);
//    ListNode l2 = sortList(slow);
//    // step 3. merge l1 and l2
//    return merge(l1, l2);
//
//    ListNode l = new ListNode(0), p = l;
//    while (l1 != null && l2 != null) {
//      if (l1.val < l2.val) {
//        p.next = l1;
//        l1 = l1.next;
//      } else {
//        p.next = l2;
//        l2 = l2.next;
//      }
//      p = p.next;
//    }
//    if (l1 != null)
//      p.next = l1;
//    if (l2 != null)
//      p.next = l2;
//    return l.next;




//Runtime: 104 ms, faster than 79.77% of C++ online submissions for Sort List.
//Memory Usage: 48.6 MB, less than 25.22% of C++ online submissions for Sort List.
// merge
    ListNode* lt0148a(ListNode* head)
    {
        int sz1 = 0;
        ListNode* h2 = head;
        while (h2 != nullptr)
        {
            sz1++;
            h2 = h2->next;
        }
        ListNode* ans = dfsa1(head, sz1);
        return ans;
    }

    ListNode* dfsa1(ListNode* node, int sz1)
    {
        if (node == nullptr || node->next == nullptr)
            return node;
        int t2 = sz1 / 2;
        ListNode* n2 = node;
        while (t2-- > 1)            // >0 ==> >1 , n2->next, n2 is null, NullPointerException
        {
            n2 = n2->next;
        }
        ListNode* n3 = n2->next;
        n2->next = nullptr;
        ListNode* l1 = dfsa1(node, sz1 / 2);        // never nullptr
        ListNode* l2 = dfsa1(n3, sz1 - sz1 / 2);
        ListNode* ans = new ListNode(-1);           // space not O(1).      i can set it as a class's variable. not function's
        ListNode* ans2 = ans;
        while (l1 != nullptr && l2 != nullptr)
        {
            int v1 = l1->val;
            int v2 = l2->val;
            if (v1 > v2)
            {
                ans2->next = l2;
                l2 = l2->next;
            }
            else
            {
                ans2->next = l1;
                l1 = l1->next;
            }
            ans2 = ans2->next;
        }
        if (l1 != nullptr)
        {
            ans2->next = l1;
        }
        else
        {
            ans2->next = l2;
        }
        return ans->next;
    }

};

int main()
{
//    int arr[] = {4,2,1,3};
    int arr[] = {-1,5,3,4,0};

    ListNode* h = convertArray(arr);

    LT0148 lt;

    h = lt.lt0148a(h);

    showListNode(h);

    return 0;
}
