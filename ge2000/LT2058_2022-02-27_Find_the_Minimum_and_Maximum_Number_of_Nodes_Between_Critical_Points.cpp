
#include "../header/myheader.h"

class LT2058
{
public:

// D D

// one pass



//Runtime: 290 ms, faster than 62.93% of C++ online submissions for Find the Minimum and Maximum Number of Nodes Between Critical Points.
//Memory Usage: 117.4 MB, less than 30.70% of C++ online submissions for Find the Minimum and Maximum Number of Nodes Between Critical Points.
    vector<int> lt20588a(ListNode* head)
    {
        vector<int> vi;
        int a1 = head->val;
        head = head->next;
        int a2 = head->val;
        head = head->next;
        int a3 = -1;
        int i = 2;
        while (head != nullptr)
        {
            a3 = head->val;
            if (a1 < a2 && a2 > a3)
                vi.push_back(i);
            else if (a1 > a2 && a2 < a3)
                vi.push_back(i);
            i++;
            head = head->next;
            a1 = a2;
            a2 = a3;
        }
        #ifdef __test
        showVectorInt(vi);
        #endif // __test
        if (vi.size() < 2)
        {
            return {-1, -1};
        }
        vector<int> ans = {vi[vi.size() - 1] - vi[0], vi[vi.size() - 1] - vi[0]};
        for (int i = 1; i < vi.size(); i++)
        {
            ans[0] = min(ans[0], vi[i] - vi[i - 1]);
        }
        return ans;
    }

};

int main()
{

    LT2058 lt;

//    myvi v = {5,3,1,2,5,1,2};
    int v[] = {5,3,1,2,5,1,2};

    ListNode* r = convertArray(v);

    myvi v2 = lt.lt20588a(r);

    showVectorInt(v2);

    deleteListNode(r);

    return 0;
}
