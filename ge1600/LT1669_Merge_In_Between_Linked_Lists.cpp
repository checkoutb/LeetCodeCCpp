
#include "../header/myheader.h"

class LT1669
{
public:

// D D

//        ListNode *q = A, *p = NULL;
//        for (int i = 0; i < b; ++i) {
//            if (i == a - 1) p = q;
//            q = q->next;
//        }
//        p->next = B;
//        while (B->next) B = B->next;
//        B->next = q->next;
//        return A;



// 1 <= a <= b < list1.length - 1 ......   it won't delete the 0th node...
//Runtime: 448 ms, faster than 57.96% of C++ online submissions for Merge In Between Linked Lists.
//Memory Usage: 94.9 MB, less than 63.78% of C++ online submissions for Merge In Between Linked Lists.
    ListNode* lt1669a(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode* ans = a == 0 ? list2 : list1;
        ListNode* n1 = nullptr;     // list1 's prefix last node
        ListNode* n2 = nullptr;     // list1 's suffix first node
        ListNode* n3 = list2;     // list2 's last node
        while (a-- > 0)
            n1 = n1 == nullptr ? list1 : (n1->next);
        while (b-- >= -1)                         // .
            n2 = n2 == nullptr ? list1 : (n2->next);
        while (n3->next != nullptr)
            n3 = n3->next;
        if (n1 != nullptr)
            n1->next = list2;
        n3->next = n2;
        return ans;
    }

};

int main()
{
//    int arr1[] = {0,1,2,3,4,5};
//    int arr2[] = {1000000,1000001,1000002};
//    int a = 3;
//    int b = 4;

    int arr1[] = {0,1,2,3,4,5,6};
    int arr2[] = {1000000,1000001,1000002,1000003,1000004};
    int a = 2;
    int b = 5;

    ListNode* list1 = convertArray(arr1);
    ListNode* list2 = convertArray(arr2);
    LT1669 lt;

    ListNode* ans = lt.lt1669a(list1, a, b, list2);
    showListNode(ans);

    return 0;
}
