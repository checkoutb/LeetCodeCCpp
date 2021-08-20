
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        sub = root.val + s(root.left) + s(root.right);
//        res = Math.max(res, sub * (total - sub));
// 把自己作为 子树的根。  而不是 自己的子结点作为子树的根。



// AC
    int lta(TreeNode* root)
    {
        int sum2 = dfs_sum(root);
        dfs_prod(root, sum2);
        return ans % (int)(1E9 + 7);
    }
    long long ans = 0;
    int dfs_sum(TreeNode* node)
    {
        return node == nullptr ? 0 : (node->val + dfs_sum(node->left) + dfs_sum(node->right));
    }
    int dfs_prod(TreeNode* node, int sum2)
    {
        if (node == nullptr)
            return 0;
        int tl = dfs_prod(node->left, sum2);
        int tr = dfs_prod(node->right, sum2);
//        long long t2 = max(1L * (tl + node->val) * tr, 1L * (tr + node->val) * tl);
        long long t2 = max(1L * (sum2 - tl) * tl, 1L * (sum2 - tr) * tr);
        ans = max(1L * ans, t2);
        return tl + tr + node->val;
    }

};

int main()
{
//    int arr[] = {2,3,9,10,7,8,6,5,4,11,1};
//    int arr[] = {1,1};
    int arr[] = {1,2,3,4,5,6};

    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 5);

    LT lt;

    cout<<lt.lta(r)<<endl;

    deleteTreeNode(r);

    return 0;
}
