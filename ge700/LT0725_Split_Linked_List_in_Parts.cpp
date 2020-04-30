
#include "../header/myheader.h"

class LT0725
{
public:


// discuss
//        for (int i = 0; node && i < k; i++, r--) {
//            parts[i] = node;
//            for (int j = 0; j < n + (r > 0); j++) {
//                prev = node;
//                node = node->next;
//            }
//            prev->next = nullptr;
//        }
//。。。


// ..刚开始觉得这题很简单。。结果一路掉坑里。。。。
//Runtime: 12 ms, faster than 75.09% of C++ online submissions for Split Linked List in Parts.
//Memory Usage: 7.8 MB, less than 100.00% of C++ online submissions for Split Linked List in Parts.
    vector<ListNode*> lt0725a(ListNode* root, int k)
    {
        int sz1 = 0;
        ListNode* node = root;
        while (node != NULL)
        {
            sz1++;
            node = node->next;
        }
        node = root;

        int a = sz1 / k;
        int b = sz1 % k;
        if (b != 0)
            a++;
        else
            b = INT_MAX;
        int i = 0;
        int m = 0;
        vector<ListNode*> ans;
        ans.push_back(node);
        while (node != NULL)
        {
            i++;
            ListNode* n2 = node->next;
            if (i % a == 0)
            {
                m++;
                node->next = NULL;
                if (n2 != NULL)
                    ans.push_back(n2);
            }
            if (m >= b)
            {
                m = INT_MIN;
                a--;
                i = 0;
            }
            node = n2;
        }
        while (ans.size() < k)
        {
            ans.push_back(NULL);
        }
        return ans;
    }

};

int main()
{

    LT0725 lt;

//    int arr[] = {1,2,3,4,5,6,7,8};
//    int k = 3;

//    int arr[] = {1,2,3};
//    int k = 5;

//    int arr[] = {1,2,3,4,5,6,7};
//    int k = 3;

    int arr[] = {0, 1};
    int k = 2;

    ListNode* r = convertArray(arr);

    showListNode(r);
    cout<<endl<<"---"<<endl;

    vector<ListNode*> ans = lt.lt0725a(r, k);


    cout<<ans.size()<<endl;
    for (ListNode* n : ans)
    {
        if (n == NULL)
            cout<<"null";

        while (n != NULL)
        {
            cout<<n->val<<", ";
            n = n->next;
        }
        cout<<endl;
    }

    return 0;
}
