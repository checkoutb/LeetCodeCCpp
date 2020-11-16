
#include "../header/myheader.h"

class LT1302
{
public:


// D D


// dfs,  类属性：层级，sum.



//Runtime: 56 ms, faster than 65.67% of C++ online submissions for Deepest Leaves Sum.
//Memory Usage: 39.5 MB, less than 28.45% of C++ online submissions for Deepest Leaves Sum.
    int lt1302a(TreeNode* root)
    {
        queue<TreeNode*> que2;
        que2.push(root);
        int ans = 0;
        while (!que2.empty())
        {
            int sz2 = que2.size();
            int sm2 = 0;                    // ... 直接 ans = 0...
            while (sz2-- > 0)
            {
                TreeNode* n = que2.front();
                que2.pop();
                sm2 += n->val;
                if (n->left)
                    que2.push(n->left);
                if (n->right)
                    que2.push(n->right);
            }
            ans = sm2;
        }
        return ans;
    }

};

int main()
{

    LT1302 lt;


    return 0;
}
