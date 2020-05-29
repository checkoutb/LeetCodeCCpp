
#include "../header/myheader.h"

class LT0817
{
public:


// D D
//if (setG.count(head->val) && (head->next == NULL || !setG.count(head->next->val))) res++;

// 指针可以默认转bool。。使用bool[10001].来标记是否存在这个值。 int来标记是否连续(bool数组中不存在是设置为1，存在时，{如果是1，ans++；； 设置为0。})


//Runtime: 68 ms, faster than 44.71% of C++ online submissions for Linked List Components.
//Memory Usage: 19.6 MB, less than 5.26% of C++ online submissions for Linked List Components.
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// G 直接转成 set
    int lt0817a(ListNode* head, vector<int>& G)
    {
        std::sort(G.begin(), G.end());
        int ans = 0;
        while (head != nullptr)
        {
            int val = head->val;
            vector<int>::iterator it2 = std::lower_bound(G.begin(), G.end(), val);
            if (it2 != G.end() && *it2 == val)
            {
                ans++;
                while (head->next != nullptr)
                {
                    head = head->next;
                    val = head->val;
                    it2 = std::lower_bound(G.begin(), G.end(), val);
                    if (it2 == G.end() || *it2 != val)
                    {
                        break;
                    }
                }
            }
            head = head->next;
        }
        return ans;
    }

};

int main()
{

//    int arr[] = {0,1,2,3};
//    vector<int> g = {0,1,3};

    int arr[] = {0,1,2,3,4};
    vector<int> g = {0,3,1,4};

    ListNode* root = convertArray(arr);

    LT0817 lt;

    cout<<lt.lt0817a(root, g)<<endl;

    return 0;
}
