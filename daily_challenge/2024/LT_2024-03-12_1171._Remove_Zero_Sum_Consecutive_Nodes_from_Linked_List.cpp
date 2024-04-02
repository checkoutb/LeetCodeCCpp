
#include "../../header/myheader.h"

class LT
{
public:





// Runtime
// 6ms
// Beats76.90%of users with C++
// Memory
// 14.56MB
// Beats53.24%of users with C++
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        std::vector<ListNode*> vp;
        while (head != nullptr)
        {
            vp.push_back(head);
            head = head->next;
        }
        map<int, int> map2;
        vector<int> vi(vp.size(), 0);   // sum of <=
        int sum2 = 0;
        for (int i = 0; i < vi.size(); ++i)
        {
            sum2 += vp[i]->val;
            if (!map2.contains(sum2))
                map2[sum2] = i;
            vi[i] = sum2;
        }
        ListNode* ans = vp[0];
        for (int i = vi.size() - 1; i >= 0; --i)
        {
            if (vi[i] == 0)
            {
                ans = vp[i]->next;
                break;
            }
            if (map2.contains(vi[i]) && map2[vi[i]] < i)
            {
                int t2 = map2[vi[i]];
                vp[t2]->next = vp[i]->next;
                i = t2 + 1;
            }
        }
        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
