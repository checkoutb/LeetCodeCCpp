
#include "../header/myheader.h"

class LT2074
{
public:

// D D

//ListNode* reverseList(ListNode* cur, int n) {
//    ListNode *start = cur, *prev = nullptr;
//    while (--n >= 0) {
//        swap(cur->next, prev);
//        if (--n >= 0)
//            swap(prev->next, cur);
//    }
//    start->next = cur;
//    return prev;
//}


// stack


//Runtime: 980 ms, faster than 86.07% of C++ online submissions for Reverse Nodes in Even Length Groups.
//Memory Usage: 329.7 MB, less than 65.10% of C++ online submissions for Reverse Nodes in Even Length Groups.
    ListNode* lt2074a(ListNode* head)
    {
        int cnt = 2;
        ListNode* p2 = head;        // head   both pre
        ListNode* p3 = head;        // tail
        while (p2->next != nullptr)
        {
            int l2 = 0;
            for (int i = 0; i < cnt && p3->next != nullptr; ++i)
            {
                l2++;
                p3 = p3->next;
            }
            #ifdef __test
//            getchar();
//            showListNode(head);
            #endif // __test
            if (l2 % 2 == 0 && l2 > 0)
            {
//                ListNode* pa = p2;
                ListNode* pt2 = p2->next;
                ListNode* pt3 = p2->next->next;
                pt2->next = p3->next;
                while (--l2 > 0)
                {
                    ListNode* pt33 = pt3->next;
                    pt3->next = p2->next;
                    p2->next = pt3;
                    pt3 = pt33;

//                    pt3 = p2->next->next->next;
//                    pt2 = p2->next;
//                    p2->next = p2->next->next;
//                    pt3 = p2->next->next->next;
//                    pt2 = p2->next;
//                    pa->next = pa->next->next;
//                    pa->next = pt2;
//                    pt2->next =
                }
                p2 = p3 = pt2;
            } else {
                p2 = p3;
            }
            cnt++;
//            cout<<cnt<<endl;
        }
        return head;
    }

};

int main()
{

    LT2074 lt;

//    int arr[] = {5,2,6,3,9,1,7,3,8,4};
//    int arr[] = {1,0,1,6};
    int arr[] = {1,0,1,5,6};
    ListNode* r = convertArray(arr);

    r = lt.lt2074a(r);

    showListNode(r);
    deleteListNode(r);

    return 0;
}
