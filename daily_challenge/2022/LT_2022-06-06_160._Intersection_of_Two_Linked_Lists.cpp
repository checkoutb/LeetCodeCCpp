
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //if (headA == null || headB == null) return null;
    //
    //ListNode a = headA;
    //ListNode b = headB;
    //
    ////if a & b have different len, then we will stop the loop after second iteration
    //while (a != b) {
    //    //for the end of first iteration, we just reset the pointer to the head of another linkedlist
    //    a = a == null ? headB : a.next;
    //    b = b == null ? headA : b.next;
    //}
    //
    // listA: qwerasdf
    // listB: zxcasdf
    // listA + listB : qwerasdfzxcasdf
    // listB + listA : zxcasdfqwerasdf
    // the last four chars are same.


//Runtime: 59 ms, faster than 57.46 % of C++ online submissions for Intersection of Two Linked Lists.
//Memory Usage : 14.5 MB, less than 88.39 % of C++ online submissions for Intersection of Two Linked Lists.
    ListNode* lta(ListNode* headA, ListNode* headB)
    {
        if (headA == headB)
            return headA;

        ListNode* n = headA;
        while (n->next != nullptr)
        {
            n = n->next;
        }
        n->next = headB;
        ListNode* f = headA->next->next;        // fast
        ListNode* s = headA->next;        // slow

        while (f != nullptr && f->next != nullptr)
        {
            f = f->next->next;
            s = s->next;
            if (f == s)
                break;
        }
        if (f != s)
        {
            n->next = nullptr;
            return nullptr;
        }

        f = headA;
        while (f != s)
        {
            f = f->next;
            s = s->next;
        }

        n->next = nullptr;
        return f;
    }

};

int main()
{

    LT lt;


    return 0;
}
