
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        while(left > 1){
//            prev = curr;
//            curr = curr->next;
//            left--;
//            right--;
//        }
//
//        ListNode* conn = prev;
//        ListNode* tail = curr;
//
//        while(right > 0){
//            ListNode* temp = curr->next;
//            curr->next = prev;
//            prev = curr;
//            curr = temp;
//            right--;
//        }
// 2根指针都跑到left前面，然后开始反转。最后把尾巴连接上。
// 跑一根指针到left前，然后复制下。


// recursion




// AC
    ListNode* lta(ListNode* head, int left, int right)
    {
        if (left == right)
            return head;

        ListNode root(-1);
        root.next = head;
        int t2 = right - left;
        ListNode* rp = &root;
        ListNode* lp = &root;
        for (int i = 0; i < t2; ++i)
        {
            rp = rp->next;
        }
        for (int i = 1; i < left; ++i)
        {
            rp = rp->next;
            lp = lp->next;      // lp.next is the left
        }
        ListNode* p = lp;       // left's prev
        ListNode* rnnp = rp->next->next;        // right's next;
        p = p->next;
        ListNode* noder = p;            // after reverse, noder is the rightest
        ListNode* nodel = rp->next;     // leftest
        ListNode* tmp = p;      // left
        ListNode* tmp2 = nullptr;
        p = p->next;
        while (p != rnnp)
        {
            tmp2 = p->next;
            p->next = tmp;
            tmp = p;
            p = tmp2;
        }
        lp->next = nodel;
        noder->next = rnnp;

        return root.next;
    }

};

int main()
{
    int arr[] = {1,2,3,4,5};
    int l = 2;
    int r = 4;

    ListNode* r2 = convertArray(arr);
    showListNode(r2);

    LT lt;

    ListNode* rr = lt.lta(r2, l, r);

    showListNode(rr);

    deleteListNode(rr);

    return 0;
}
