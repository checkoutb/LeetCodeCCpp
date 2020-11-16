
#include "../header/myheader.h"

class LT1305
{
public:


// D D

//merge(e1.begin(), e1.end(), e2.begin(), e2.end(), back_inserter(res));

//    while (!s1.empty() || !s2.empty()) {
//        stack<TreeNode*> &s = s1.empty() ? s2 : s2.empty() ? s1 :
//            s1.top()->val < s2.top()->val ? s1 : s2;
//        auto n = s.top(); s.pop();
//        res.push_back(n->val);
//        pushLeft(s, n->right);
//    }


//Runtime: 208 ms, faster than 61.19% of C++ online submissions for All Elements in Two Binary Search Trees.
//Memory Usage: 85.7 MB, less than 70.58% of C++ online submissions for All Elements in Two Binary Search Trees.
// 各自遍历，然后双指针
// 怎么在中序遍历的时候直接生成有序
// stack!
    vector<int> lt1305a(TreeNode* root1, TreeNode* root2)
    {
        stack<TreeNode*> stk1;
        stack<TreeNode*> stk2;
        vector<int> ans;
        while (root1)
        {
            stk1.push(root1);
            root1 = root1->left;
        }
        while (root2)
        {
            stk2.push(root2);
            root2 = root2->left;
        }
        while (!stk1.empty() || !stk2.empty())
        {
            int t1 = stk1.empty() ? 1E9 : stk1.top()->val;
            int t2 = stk2.empty() ? 1E9 : stk2.top()->val;
            if (t1 < t2)
            {
                ans.push_back(t1);
                TreeNode* n = stk1.top();
                stk1.pop();
                n = n->right;
                while (n)
                {
                    stk1.push(n);
                    n = n->left;
                }
            }
            else
            {
                ans.push_back(t2);
                TreeNode* n = stk2.top();
                stk2.pop();
                n = n->right;
                while (n)
                {
                    stk2.push(n);
                    n = n->left;
                }
            }
        }
        return ans;
    }

};

int main()
{

    int arr1[] = {2,1,4};
    int arr2[] = {1,0,3};

    TreeNode* n1 = convert2TreeNode(arr1);
    TreeNode* n2 = convert2TreeNode(arr2);

    LT1305 lt;

    vector<int> v = lt.lt1305a(n1, n2);

    showVectorInt(v);

    return 0;
}
