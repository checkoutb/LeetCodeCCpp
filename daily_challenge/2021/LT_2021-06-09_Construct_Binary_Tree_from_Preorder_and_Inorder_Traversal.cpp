
#include "../../header/myheader.h"

class LT
{
public:

// D D

// stacks



// AC
// 先序的第一个是根， 中序中根节点把左右子树正好分开
// 不知道用个map保存 <value, index in inorder> 会不会更快
    TreeNode* lta(vector<int>& preorder, vector<int>& inorder)
    {
        unordered_map<int, int> inmap2;
        for (int i = 0; i < inorder.size(); ++i)
        {
            inmap2[inorder[i]] = i;
        }
        TreeNode* ans = dfsa1(preorder, inorder, inmap2, 0, 0, inorder.size() - 1);
        return ans;
    }

    TreeNode* dfsa1(vector<int>& pre, vector<int>& in, unordered_map<int, int>& map2, int pidx, int stin, int enin)
    {
        if (stin > enin)
            return nullptr;
        if (pidx >= pre.size())     // not necessary
            return nullptr;
        int inidx = map2[pre[pidx]];
        int t2 = inidx - stin;
        TreeNode* node = new TreeNode(pre[pidx]);
        node->left = dfsa1(pre, in, map2, pidx + 1, stin, inidx - 1);
        node->right = dfsa1(pre, in, map2, pidx + 1 + t2, inidx + 1, enin);
        return node;
    }

};

int main()
{
//    myvi pre = {3,9,20,15,7};
//    myvi in = {9,3,15,20,7};

    myvi pre = {-1};
    myvi in = {-1};

    LT lt;

    TreeNode* r = lt.lta(pre, in);

    showTreeNode(r, 5);

    deleteTreeNode(r);      // -1,-1 这个用例 不加delete 会报错， 但是 第一个用例 不加delete不会报错。。

    return 0;
}
