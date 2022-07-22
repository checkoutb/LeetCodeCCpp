
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //ListNode** a = &head, ** b;
    //for (; m--; n--)
    //    a = &(*(b = a))->next;
    //for (; n--; swap(*b, *a))
    //    swap(*b, (*a)->next);
    //return head;



//Runtime: 0 ms, faster than 100.00 % of C++ online submissions for Reverse Linked List II.
//Memory Usage : 7.6 MB, less than 17.76 % of C++ online submissions for Reverse Linked List II.
    ListNode* lta(ListNode* head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode* dum = new ListNode(-1, head);
        ListNode* t2 = dum;
        while (left-- > 1)
        {
            t2 = t2->next;          // previous of node-left
            right--;
        }
        ListNode* t3 = t2->next->next;
        ListNode* t4 = t2->next;
        ListNode* ppre = t2->next;
        while (right-- > 1)
        {
            t4->next = t3->next;
            t3->next = ppre;
            ppre = t3;
            t3 = t4->next;
        }
        t2->next = ppre;

        return dum->next;
    }

};

int main()
{

    LT lt;


    return 0;
}
