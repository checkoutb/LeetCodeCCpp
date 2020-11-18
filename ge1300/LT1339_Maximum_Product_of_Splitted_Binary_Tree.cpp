
#include "../header/myheader.h"

class LT1339
{
public:

// D D

//unordered_set<int> sums;
//int dfs(TreeNode* n) {
//    return n == nullptr ? 0 :
//        *sums.insert(dfs(n->left) + dfs(n->right) + n->val).first;
//}
//int maxProduct(TreeNode* root) {
//    long long t = dfs(root), res = 0;
//    for (auto n : sums)
//        res = max(res, (t - n) * n);
//    return res % 1000000007;
//}


//    long res = 0, total = 0, sub;
//    int maxProduct(TreeNode* root) {
//        total = s(root), s(root);
//        return res % (int)(1e9 + 7);
//    }
//
//    int s(TreeNode* root) {
//        if (!root) return 0;
//        sub = root->val + s(root->left) + s(root->right);
//        res = max(res, sub * (total - sub));
//        return sub;
//    }





//Runtime: 176 ms, faster than 77.26% of C++ online submissions for Maximum Product of Splitted Binary Tree.
//Memory Usage: 80.9 MB, less than 89.49% of C++ online submissions for Maximum Product of Splitted Binary Tree.
// a == b
    int lt1339a(TreeNode* root)
    {
        dfsa1(root);
        int sum2 = root->val;
        dfsa2(root, sum2);
        return (int) (ans % ((int) (1E9 + 7)));
    }
    long ans = 0;

    // val = sum of subTree
    int dfsa1(TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        node->val = node->val + dfsa1(node->left) + dfsa1(node->right);
        return node->val;
    }

    void dfsa2(TreeNode* node, int sum2)
    {
        if (node == nullptr)
            return;
        ans = max(ans, ((long) node->val) * (sum2 - node->val));
        if (node->val < (sum2 / 2))
            return;
        dfsa2(node->left, sum2);
        dfsa2(node->right, sum2);
    }

};

int main()
{

//    int arr[] = {1,2,3,4,5,6};
//    int arr[] = {2,3,9,10,7,8,6,5,4,11,1};
    int arr[] = {1,1};

    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 3);

    LT1339 lt;

    cout<<lt.lt1339a(r);
//    cout<<endl<<endl;
//    showTreeNode(r, 3);

    return 0;
}
