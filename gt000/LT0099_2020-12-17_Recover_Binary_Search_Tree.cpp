
#include "../header/myheader.h"

class LT0099
{
public:




// 回溯，
// lt0099a + 如果左侧 和 右侧 都有不满足的，就 互换 左侧，右侧的 2个结点。
    void lt0099b(TreeNode* root)
    {

    }


// error
// 第二个结点dfs 就可以了， 但是第一个结点。。 不 第二个结点也难。
//
    void lt0099a(TreeNode* root)
    {
        rt = root;
        TreeNode* mnn = root;
        TreeNode* mxn = root;
        while (mnn->left != nullptr)
            mnn = mnn->left;
        while (mxn->right != nullptr)
            mxn = mxn->right;
        dfsa1(root, mnn, mxn);
    }
    TreeNode* rt = nullptr;
    bool isBST(TreeNode* node, int mn, int mx)
    {
        if (node == nullptr)
            return true;
        if (node->val > mx || node->val < mn)
            return false;
        return isBST(node->left, mn, node->val) && isBST(node->right, node->val, mx);
    }
    void dfsa1(TreeNode* node, TreeNode* mnn, TreeNode* mxn)
    {
        if (node == nullptr)
            return;
        if (node->val > mxn->val)
        {
            int t2 = mxn->val;
            mxn->val = node->val;
            node->val = t2;
            if (isBST(rt, INT_MIN, INT_MAX))
                return;
            t2 = mxn->val;
            mxn->val = node->val;
            node->val = t2;
        }
        if (node->val < mnn->val)
        {
            int t2 = mnn->val;
            mnn->val = node->val;
            node->val = t2;
            if (isBST(rt, INT_MIN, INT_MAX))
                return;
            t2 = mnn->val;
            mxn->val = node->val;
            node->val = t2;
        }
        dfsa1(node->left, mnn, node);
        dfsa1(node->right, node, mxn);
    }

};

int main()
{
//    int arr[] = {1,3,-1,-1,2};
//    int arr[] = {3,1,4,-1,-1,2};
    int arr[] = {2,3,1};            // ... 跨子树，而不是 上下。。  知道了。。 树结构不变，结点值唯一(?是否需要)， 只有一种子树，
                            // 那就是， 遍历一遍，知道自己的左侧有多少，右侧有多少。 然后遍历的时候 就知道了。 但是 应该要值唯一才行。 题目没有明说，不知道是不是。
                            // 当有一个点的 左侧，右侧， 不满足要求时， 找到 一个  值 适合这个位值的点。
                            // bu ,2,3,1 符合 左侧.size() == 右侧.size()

    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 3);

    LT0099 lt;

    lt.lt0099a(r);

    showTreeNode(r, 3);

    return 0;
}
