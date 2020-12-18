
#include "../header/myheader.h"

class LT0142
{
public:

// D D


//    while (fast->next && fast->next->next) {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast) {                      // there is a cycle
//            while(slow != entry) {               // found the entry location
//                slow  = slow->next;
//                entry = entry->next;
//            }
//            return entry;
//        }
//    }
//    return NULL;                                 // there has no cycle



//Runtime: 4 ms, faster than 98.78% of C++ online submissions for Linked List Cycle II.
//Memory Usage: 8 MB, less than 76.75% of C++ online submissions for Linked List Cycle II.
// 还差一步。。baidu了。。 快慢指针只能找环， 起点还需要 一步 相同速度指针(起点+第一次碰到的点) 来寻找。
// 返回 tail to connect。。
// 好像第一次碰到 * 后置的格式。。
    ListNode *lt0142a(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        fast = fast->next;
        fast = fast == nullptr ? nullptr : fast->next;
        slow = slow->next;
        while (fast != nullptr && fast != slow)
        {
//        cout<<"1, "<<fast->val<<" , "<<slow->val<<endl;
            fast = fast->next;
            fast = fast == nullptr ? nullptr : fast->next;
            slow = slow->next;
        }
//        return fast;
//        cout<<fast->val<<endl;
//        return fast == nullptr ? nullptr : fast->next;
        if (fast == nullptr)
            return nullptr;
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }

};

int main()
{
    LT0142 lt;
    int arr[] = {3,2,0,-4};

    ListNode* r = convertArray(arr);
    ListNode* lst = r;
    while (lst->next != nullptr)
        lst = lst->next;
    lst->next = r->next;
    lst = r;
    for (int i = 0; i < 8; ++i)
    {
        cout<<lst->val<<", ";
        lst = lst->next;
    }
    cout<<endl;
    ListNode* n = lt.lt0142a(r);

//    ListNode* n1 = new ListNode(1);
//    ListNode* n2 = new ListNode(2);
//    n1->next = n2;
//    n2->next = n1;
//    ListNode* n = lt.lt0142a(n1);
    cout<<(n == nullptr ? -1 : n->val);

    return 0;
}
