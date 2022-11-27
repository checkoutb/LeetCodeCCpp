
#include "../header/myheader.h"

class LT2487
{
public:

    // D D

    //ListNode* preHead = new ListNode(-1, head);
    //bool update = true;
    //while (update) {
    //    update = false;
    //    ListNode* prev = preHead;
    //    for (ListNode* node = preHead->next; node->next != NULL; node = node->next) {
    //        if (node->next->val > node->val) {
    //            prev->next = node->next;
    //            update = true;
    //        }
    //        else {
    //            prev = node;
    //        }
    //    }
    //}
    //return preHead->next;

//public:
//    ListNode* removeNodes(ListNode* head) {
//        ListNode pre(0, head);
//        remove(head, &pre);
//        return pre.next;
//    }
//
//private:
//    int remove(ListNode* node, ListNode* pre) {
//        if (node == nullptr)  return 0;
//        int max_next = remove(node->next, node);
//        int res = max(max_next, node->val);
//        if (node->val < max_next)
//            pre->next = node->next;
//        return res;
//    }
    // dfs ¾¹È»Ã»ÓÐstackoverflow



    //Runtime1070 ms
    //    Beats
    //    12.50 %
    //    Memory166.8 MB
    //    Beats
    //    12.50 %
    // mono
    ListNode* lt2487a(ListNode* head)
    {
        //ListNode* dummy = new ListNode(-1, head);

        //head = head->next;
        
        //ListNode* dummy = new ListNode();

        vector<ListNode*> vp;

        while (head != nullptr)
        {
            while (!vp.empty() && vp[vp.size() - 1]->val < head->val)
            {
                vp.pop_back();
            }
            vp.push_back(head);
            head = head->next;
        }

        for (int i = 0; i < vp.size() - 1; ++i)
        {
            vp[i]->next = vp[i + 1];
        }
        vp.back()->next = nullptr;

        return vp[0];

        //return dummy->next;
    }

};

int main()
{

    LT2487 lt;


    return 0;
}
