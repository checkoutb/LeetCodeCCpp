
#include "../header/myheader.h"

class LT2095
{
public:

// D D



//    auto slow = head, fast = head->next->next;
//    while (fast != nullptr && fast->next != nullptr) {
//        fast = fast->next->next;
//        slow = slow->next;
//    }
//    slow->next = slow->next->next;



// 不科学，怎么这么慢。。
//Runtime: 1766 ms, faster than 14.19% of C++ online submissions for Delete the Middle Node of a Linked List.
//Memory Usage: 294.7 MB, less than 91.96% of C++ online submissions for Delete the Middle Node of a Linked List.
    ListNode* lt2095a(ListNode* head)
    {
        if (head->next == nullptr)
            return nullptr;

        ListNode* f = head;
        ListNode* s = head;
        ListNode* t = nullptr;
        int sz1 = 0;
        int si = 0;
        while (f->next != nullptr && f->next->next != nullptr)
        {
            f = f->next->next;
            t = s;
            s = s->next;
        }
        if (f->next != nullptr)
        {
            // s
            s->next = s->next->next;
        }
        else
        {
            // t
            t->next = t->next->next;
        }
        return head;
    }

};

int main()
{

    LT2095 lt;

//    int arr[] = {1,3,4,7,1,2,6};
//    int arr[] = {1,2,3,4};
    int arr[] = {1,2};

    ListNode* r = convertArray(arr);

    ListNode* rr = lt.lt2095a(r);

    showListNode(rr);

    deleteListNode(rr);     // 被删除的结点没有被释放。

    return 0;
}
