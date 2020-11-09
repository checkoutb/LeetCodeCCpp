
#include "../header/myheader.h"

class LT1171
{
public:


// D D

//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        ListNode* cur = dummy;
//        while(cur) {
//            int sum = 0;
//            while(head) {
//                sum += head->val;
//                if(sum == 0) {
//                    cur->next = head->next;
//                }
//                head = head->next;
//            }
//            cur = cur->next;
//            if(cur) head = cur->next;
//        }
//
//        return dummy->next;


//        ListNode* dummy = new ListNode(0);
//        dummy->next = head;
//        int prefix = 0;
//        unordered_map<int, ListNode*> seen;
//        for (ListNode* i = dummy; i; i = i->next) {
//            seen[prefix += i->val] = i;
//        }
//        prefix = 0;
//        for (ListNode* i = dummy; i; i = i->next) {
//            i->next = seen[prefix += i->val]->next;
//        }
//        return dummy->next;
// 保存最后一个看到 和 的 下标。
// 根据 目前的 sum，找到最后一次 和为sum的 点，然后 跳过中间的结点。



// cout没删。。。
//Runtime: 20 ms, faster than 58.34% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
//Memory Usage: 11.7 MB, less than 6.78% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
// vector is stack.
// 应该用stack。
// 1,5,-2,-4.
// 1,2,-4,1
// 转vector 再转ListNode...
    ListNode* lt1171a(ListNode* head)
    {
        vector<pair<int, ListNode*>> vp;        // sum - node
        ListNode* node = new ListNode(10000000);
        node->next = head;
//        head = node;
        unordered_map<int, int> map2;           // sum - vp.index
        int sum2 = 0;
//        ListNode* last = node;
        vp.push_back({0, node});
        map2[0] = 0;
        while (head != nullptr)
        {
            sum2 += head->val;
            if (map2.find(sum2) != map2.end())
            {
                int idx = map2[sum2];
//                cout<<"    "<<idx<<endl;
                while (vp.size() > idx + 1)
                {
                    map2.erase(vp.back().first);            // delete
                    vp.pop_back();
                }
//                cout<<" . . . "<<head->val<<endl;
//                cout<<"   .   "<<vp.back().first<<endl;
                vp.back().second->next = head->next;
                sum2 = vp.back().first;
            }
            else
            {
                map2[sum2] = vp.size();     // havn't push_back
                vp.push_back({sum2, head});     // last
            }
//            last = head;
//            last = vp.back().second->next;

            #ifdef __test
            for (int i = 0; i < vp.size(); i++)
            {
                cout<<i<<", "<<vp[i].first<<", "<<(vp[i].second == nullptr ? -1 : vp[i].second->val)<<endl;
            }
            cout<<" = = = = == = "<<endl;
            #endif // __test
            head = head->next;
        }
        return vp.empty() ? nullptr : vp[0].second->next;
    }

};

int main()
{

//    int arr[] = {1,2,-3,3,5};
//    int arr[] = {1,2,3,-3,4};
//    int arr[] = {1,2,3,-3,-2};
    int arr[] = {1,2,-1,-2};

    ListNode* head = convertArray(arr);
    showListNode(head);
    cout<<endl;

    LT1171 lt;

    ListNode* node = lt.lt1171a(head);

    showListNode(node);

    return 0;
}
