
#include "../header/myheader.h"

class LT2130
{
public:

// D D


//ListNode* reverseList(ListNode* cur, ListNode* prev = nullptr) {
//    while (cur != nullptr) {
//        swap(cur->next, prev);
//        swap(prev != nullptr ? prev->next : prev, cur);
//    }
//    return prev;
//}

// middle. reverse
    int lt2130a(ListNode* head)
    {
        ListNode* f = head;
        ListNode* s = head;
        while (f != nullptr)
        {
            f = f->next->next;
            s = s->next;
        }
        ListNode* snxt = s->next;
        s->next = nullptr;
        while (snxt != nullptr)
        {
            ListNode* t2 = snxt->next;
            snxt->next = s;
            s = snxt;
            snxt = t2;
        }
        int ans = 0;
        f = head;
        while (s != nullptr)
        {
            ans = max(ans, s->val + f->val);
            s = s->next;
            f = f->next;
        }
        return ans;
    }

};

int main()
{

    LT2130 lt;


    return 0;
}
