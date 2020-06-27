
#include "../header/myheader.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class LT0979
{
public:


// D D

//        int res = 0;
//        if (root->left) {
//            res += distributeCoins(root->left);
//            root->val += root->left->val - 1;
//            res += abs(root->left->val - 1);
//        }
//        if (root->right) {
//            res += distributeCoins(root->right);
//            root->val += root->right->val - 1;
//            res += abs(root->right->val - 1);
//        }
//        return res;

//    int distributeCoins(TreeNode* root, TreeNode* pre = NULL) {
//        if (!root) return 0;
//        int res = distributeCoins(root->left, root) + distributeCoins(root->right, root);
//        if (pre) pre->val += root->val - 1;
//        return res + abs(root->val - 1);
//    }




// 本天成。
//Runtime: 12 ms, faster than 30.18% of C++ online submissions for Distribute Coins in Binary Tree.
//Memory Usage: 14 MB, less than 68.98% of C++ online submissions for Distribute Coins in Binary Tree.
    int ans = 0;
    int lt0979a(TreeNode* root)
    {
        dfsa1(root);
        return ans;
    }

    int dfsa1(TreeNode* node)
    {
        if (node == nullptr)
            return 0;

        int l = dfsa1(node->left);
        int r = dfsa1(node->right);
        ans += (std::abs(l) + std::abs(r));

        return l + r + node->val - 1;
    }

};

int main()
{

    int arr[] = {1,0,2};

    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 3);

    LT0979 lt;

    cout<<endl<<lt.lt0979a(r)<<endl;

    return 0;
}
