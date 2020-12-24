
#include "../header/myheader.h"

class LT0148
{
public:



// D

// merge sort



// tle.
    ListNode* lt0148a(ListNode* head)
    {
        if (head == nullptr)
            return head;
        ListNode* ans = new ListNode(INT_MIN);
        ans->next = head;
        ListNode* np = head->next;
        head->next = nullptr;
        while (np != nullptr)
        {
            ListNode* prev = ans;
            ListNode* node = ans->next;
            while (node != nullptr && node->val < np->val)
            {
                prev = node;
                node = node->next;
            }
            ListNode* temp = np->next;
            prev->next = np;
            np->next = node;
            np = temp;
        }
        ListNode* ans2 = ans->next;
        delete ans;
        return ans2;
    }

};

int main()
{
//    int arr[] = {4,2,1,3};
    int arr[] = {-1,5,3,4,0};

    ListNode* r = convertArray(arr);
    LT0148 lt;

    ListNode* ans = lt.lt0148a(r);

    showListNode(ans);

    while (ans != nullptr)
    {
        ListNode* t = ans;
        ans = ans->next;
        delete t;
    }

    return 0;
}
