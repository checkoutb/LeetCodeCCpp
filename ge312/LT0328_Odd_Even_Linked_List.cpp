
#include "../header/myheader.h"

class LT0328
{
public:


//Runtime: 16 ms, faster than 99.93% of C++ online submissions for Odd Even Linked List.
//Memory Usage: 9.8 MB, less than 97.45% of C++ online submissions for Odd Even Linked List.

    // 最好的成绩16ms，最差的是24ms，比20%的快。不过一共就3个区间，16，20，24.
    // 代码都差不多，都是分成2组，然后相连。

    ListNode* lt0328a(ListNode* head)
    {
        ListNode h1(-1);        // 1,3,5
        h1.next = head;
        ListNode h2(-2);        // 2,4,6
        ListNode* p1 = &h1;
        ListNode* p2 = &h2;
        bool flag = true;
        while(p1->next != NULL)
        {
            flag = !flag;
            if (flag)       // second
            {
                p2->next = p1->next;
                p1->next = p1->next->next;
                p2 = p2->next;
                p2->next = NULL;            // ..
            }
            else        // first
            {
                p1 = p1->next;
            }
        }

        #ifdef __test
        showListNode(h1.next);
        showListNode(h2.next);
        #endif // __test

        p1->next = h2.next;
        return h1.next;
    }
};

int main()
{
    LT0328 lt;

//    int arr[] = {1,2,3,4,5};
    int arr[] = {2,1,3,5,6,4,7};
    ListNode* p = convertArray(arr);
    showListNode(p);

    p = lt.lt0328a(p);

    cout<<endl<<endl;
    showListNode(p);

    return 0;
}
