
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    //public static ListNode mergeKLists(ListNode[] lists) {
    //    return partion(lists, 0, lists.length - 1);
    //}

    //public static ListNode partion(ListNode[] lists, int s, int e) {
    //    if (s == e)  return lists[s];
    //    if (s < e) {
    //        int q = (s + e) / 2;
    //        ListNode l1 = partion(lists, s, q);
    //        ListNode l2 = partion(lists, q + 1, e);
    //        return merge(l1, l2);
    //    }
    //    else
    //        return null;
    //}

    // µÝ¹émerge£¬ ·ÖÖÎ¡£



    //Runtime23 ms
    //    Beats
    //    79.97 %
    //    Memory13.1 MB
    //    Beats
    //    81.27 %
    ListNode* lta(vector<ListNode*>& lists)
    {
        //priority_queue < ListNode*, vector<ListNode*>, []() {} >

        auto mycomp = [](const ListNode* n1, const ListNode* n2) {
            return n1->val >= n2->val;
        };

        lists.erase(std::remove_if(begin(lists), end(lists), [](const ListNode* np) { return np == nullptr; }), end(lists));

        std::priority_queue<ListNode*, vector<ListNode*>, decltype(mycomp)> priq{ mycomp, lists };
        //std::priority_queue<ListNode*, vector<ListNode*>, decltype(mycomp)> priq{ mycomp };
        //for (ListNode* n : lists)
        //    if (n != nullptr)
        //        priq.push

        ListNode* np = nullptr;
        ListNode* ans = nullptr;
        ListNode* lst = nullptr;
        while (!priq.empty())
        {
            np = priq.top();
            priq.pop();

            if (ans == nullptr)
            {
                ans = np;
                lst = np;
            }
            else
            {
                lst->next = np;
                lst = lst->next;
            }
            
            if (np->next != nullptr)
                priq.push(np->next);
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
