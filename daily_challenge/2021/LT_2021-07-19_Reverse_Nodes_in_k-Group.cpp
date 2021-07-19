
#include "../../header/myheader.h"

class LT
{
public:

// D D

// stack, 不过速度慢很多。

// recursion






// AC
    ListNode* lta(ListNode* head, int k)
    {
        ListNode dummy(-1, head);            // int, ListNode*& ...  我真的没有写这个 构造器。。。
//        ListNode dummy(-1);
//        dummy.next = head;
//        head = &dummy;
        ListNode* lp = &dummy;

        while (lp->next != nullptr)
        {
            ListNode* rp = lp;          // ->next is real node.
            for (int i = 1; i < k && rp->next != nullptr; ++i)
            {
                rp = rp->next;
            }
            if (rp->next == nullptr)
            {
                break;
//                lp = rp;
//                continue;
            }
            // reverse
            ListNode* after_tail = lp->next;            // after reverse, sub listNode's tail.
            ListNode* tailHead = rp->next->next;
            ListNode* p = lp->next;
            ListNode* pprev = lp;
            while (p != tailHead)
            {
                ListNode* pnxt = p->next;
                p->next = pprev;
                pprev = p;
                p = pnxt;
            }
            lp->next = pprev;
            after_tail->next = tailHead;
            lp = after_tail;
            #ifdef __test
//            showListNode(dummy.next);
            #endif // __test
        }

        return dummy.next;
    }

};

int main()
{
//    int arr[] = {1,2,3,4,5};
//    int k = 1;

    int arr[] = {1};
    int k = 1;

    ListNode* r = convertArray(arr);

    showListNode(r);

    LT lt;

    r = lt.lta(r, k);

    showListNode(r);

    deleteListNode(r);

    return 0;
}
