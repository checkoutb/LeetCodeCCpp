
#include "../header/myheader.h"

class LT0515
{
public:

// d d
// 带深度的递归。


//Runtime: 24 ms, faster than 12.46% of C++ online submissions for Find Largest Value in Each Tree Row.
//Memory Usage: 21 MB, less than 100.00% of C++ online submissions for Find Largest Value in Each Tree Row.
// [8, 24] ms

    vector<int> lt0515a(TreeNode* root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> que2;
        que2.push(root);
        while (!que2.empty())
        {
            int m2 = que2.front()->val;
            for (int len2 = que2.size(); len2 > 0; len2--)
            {
                TreeNode* np = que2.front();
                que2.pop();
                m2 = std::max(np->val, m2);
                if (np->left != NULL)
                    que2.push(np->left);
                if (np->right != NULL)
                    que2.push(np->right);
            }
            ans.push_back(m2);
        }
        return ans;
    }

};

int main()
{
    int arr[] = {1,3,2,5,3,9};
    TreeNode* r = convert2TreeNode(arr);

//    showTreeNode(r, 4);

    LT0515 lt;
    vector<int> v = lt.lt0515a(r);
    for_each(v.begin(), v.end(), fun_cout);

    return 0;
}
