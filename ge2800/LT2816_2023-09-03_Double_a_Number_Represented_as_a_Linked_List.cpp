
#include "../header/myheader.h"

class LT2816
{
public:


    // D D
//        while(cur!=NULL){
//            int doub=cur->val*2;
//            cur->val=doub%10;
//            prev->val+=doub/10;
//            prev=cur;
//            cur=cur->next;
//        }
//
// double， 所以必然<= 8, 而进位 最多进1。


//    h = h->val > 4 ? new ListNode(0, h) : h;
//    for (auto p = h; p != nullptr; p = p->next)
//        p->val = (p->val * 2) % 10 + (p->next && p->next->val > 4);
//    return h;




//Runtime246 ms
//Beats
//55.75%
//Memory127.9 MB
//Beats
//45.33%

    ListNode* doubleIt(ListNode* head)
    {
        vector<ListNode*> vp;
        while (head != nullptr)
        {
            vp.push_back(head);
            head = head->next;
        }
        int car = 0;
        for (int i = vp.size() - 1; i >= 0; --i)
        {
            car = vp[i]->val * 2 + car;
            vp[i]->val = car % 10;
            car /= 10;
        }
        head = vp[0];
        if (car > 0)
        {
            head = new ListNode(car, head);
        }
        return head;

//        vector<int> vi;
//        ListNode* ptr = head;
//        while (ptr != nullptr)
//        {
//            vi.push_back(ptr->val);
//            ptr = ptr.next;
//        }

    }

};

int main()
{

    LT2816 lt;


    return 0;
}
