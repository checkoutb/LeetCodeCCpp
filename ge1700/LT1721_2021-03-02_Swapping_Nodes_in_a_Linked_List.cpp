
#include "../header/myheader.h"

class LT1721
{
public:

// D D

//        for(int i=1; i<k; ++i) {
//            fast = fast->next;
//        }
//        ListNode* n1 = fast, *n2 = head;
//        while(fast->next) {
//            fast = fast->next;
//            n2 = n2->next;
//        }


//    ListNode *n1 = nullptr, *n2 = nullptr;
//    for (auto p = head; p != nullptr; p = p->next) {
//        n2 = n2 == nullptr ? nullptr : n2->next;
//        if (--k == 0) {
//            n1 = p;
//            n2 = head;
//        }
//    }



//Runtime: 604 ms, faster than 70.72% of C++ online submissions for Swapping Nodes in a Linked List.
//Memory Usage: 180.1 MB, less than 75.96% of C++ online submissions for Swapping Nodes in a Linked List.
    ListNode* lt1721a(ListNode* head, int k)
    {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* n1p = dummy->next;       // node1 's parent
        int sz1 = 0;
        while (n1p != nullptr)
        {
            n1p = n1p->next;
            sz1++;
        }
        int k2 = sz1 - k + 1;
        n1p = dummy;
        for (int i = 1; i < k; ++i)
        {
            n1p = n1p->next;
        }
        ListNode* n2p = dummy;
        for (int i = 1; i < k2; ++i)
        {
            n2p = n2p->next;
        }
        if (n1p != n2p)
        {
            if (n1p->next == n2p)
            {
                n2p = n2p->next;
                n1p->next->next = n2p->next;
                n2p->next = n1p->next;
                n1p->next = n2p;
            }
            else if (n2p->next == n1p)
            {
//                cout<<" . . ."<<endl;
                n1p = n1p->next;
                n2p->next->next = n1p->next;
                n1p->next = n2p->next;
                n2p->next = n1p;
            }
            else
            {
                ListNode* nt = n1p->next;
                ListNode* nt2 = n2p->next->next;
                n1p->next = n2p->next;
                n1p->next->next = nt->next;
                n2p->next = nt;
                nt->next = nt2;
            }

        }

        #ifdef __test
        cout<<n1p->val<<", "<<n2p->val<<endl;
        ListNode* asd = dummy;
        int n = 20;
        while (asd != nullptr)
        {
            if (n-- < 0)
                return nullptr;
            cout<<asd->val<<", ";
//            getchar();
            asd = asd->next;
        }
        #endif // __test

//        showListNode(dummy);

        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }

};

int main()
{
//    int arr[] = {1,2,3,4,5,6};
//    int k = 1;

//    int arr[] = {1,2};
//    int k = 1;

    int arr[] = {100,90};
    int k = 2;

    ListNode* ln = convertArray(arr);

    LT1721 lt;

    ListNode* ans = lt.lt1721a(ln, k);

    showListNode(ans);

    while (ans != nullptr)
    {
        ln = ans->next;
        delete ans;
        ans = ln;
    }

    return 0;
}
