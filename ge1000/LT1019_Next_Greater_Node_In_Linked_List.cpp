
#include "../header/myheader.h"

class LT1019
{
public:


// D D
//        vector<int> res, stack;
//        for (ListNode* node = head; node; node = node->next) {
//            while (stack.size() && res[stack.back()] < node->val) {
//                res[stack.back()] = node->val;
//                stack.pop_back();
//            }
//            stack.push_back(res.size());          // ? 这里是记录 值为0 的结点的 下标。
//            res.push_back(node->val);         // 为了上面的 res[stack.back()]
//        }
//        for (int i: stack) res[i] = 0;
//        return res;





//Runtime: 1424 ms, faster than 17.40% of C++ online submissions for Next Greater Node In Linked List.
//Memory Usage: 41.8 MB, less than 5.51% of C++ online submissions for Next Greater Node In Linked List.
// 反转，从后往前，  不，这和直接暴力没有什么区别啊。
// 升序的话，就直接是后面那个，降序的话，所有的。。。没办法。。
    vector<int> lt1019a(ListNode* head)
    {
        vector<int> ans;
        while (head != nullptr)
        {
            ListNode* node = head;
            int v = node->val;
            int gre = 0;
            while (node->next != nullptr)
            {
                node = node->next;
                if (node->val > v)
                {
                    gre = node->val;
                    break;
                }
            }
            ans.push_back(gre);
            head = head->next;
        }

        return ans;
    }

};

int main()
{
//    int arr[] = {2,1,5};
//    int arr[] = {2,7,4,3,5};
    int arr[] = {1,7,5,1,9,2,5,1};
    ListNode* node = convertArray(arr);

    LT1019 lt;

    vector<int> v = lt.lt1019a(node);

    for_each(begin(v), end(v), fun_cout);
    cout<<endl;

    return 0;
}
