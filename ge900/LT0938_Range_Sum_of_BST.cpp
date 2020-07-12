
#include "../header/myheader.h"

class LT0938
{
public:


// 噗，bst。。。
//Runtime: 280 ms, faster than 15.28% of C++ online submissions for Range Sum of BST.
//Memory Usage: 64.8 MB, less than 61.85% of C++ online submissions for Range Sum of BST.
    int lt0938a(TreeNode* root, int L, int R)
    {
        int ans = 0;
        dfsa1(root, L, R, ans);
        return ans;
    }

    void dfsa1(TreeNode* n, int l, int r, int& ans)
    {
        if (n == nullptr)
            return;
        if (n->val >= l && n->val <= r)
        {
            ans += n->val;
        }
        dfsa1(n->left, l, r, ans);
        dfsa1(n->right, l, r, ans);
    }

};

int main()
{

    LT0938 lt;


    return 0;
}
