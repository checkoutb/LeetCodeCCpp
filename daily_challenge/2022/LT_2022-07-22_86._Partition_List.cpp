
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // ListNode* l1 = new ListNode(10), * l2 = new ListNode(10), * t1 = l1, * t2 = l2;







//Runtime: 13 ms, faster than 23.02 % of C++ online submissions for Partition List.
//Memory Usage : 10.2 MB, less than 94.54 % of C++ online submissions for Partition List.
    ListNode* lta(ListNode* head, int x)
    {
        ListNode* lt = new ListNode(-1);
        ListNode* ge = new ListNode(-2);

        ListNode* ltt = lt;
        ListNode* gee = ge;

        while (head != nullptr)
        {
            if (head->val >= x)
            {
                gee->next = head;
                gee = gee->next;
                head = head->next;
                //
            }
            else
            {
                ltt->next = head;
                ltt = ltt->next;
                head = head->next;
            }
        }
        ltt->next = ge->next;
        gee->next = nullptr;

        return lt->next;
    }

};

int main()
{

    LT lt;


    return 0;
}
