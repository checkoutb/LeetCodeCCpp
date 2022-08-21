
#include "../header/myheader.h"

class LT1372
{
public:

    // D D

    //int ret;
    //int dfs(TreeNode* root, bool leftB) {
    //    if (!root) return -1;
    //    if (!root->left && !root->right) return 0;
    //    int leftV = dfs(root->left, true);
    //    int rightV = dfs(root->right, false);
    //    ret = max(ret, 1 + max(leftV, rightV));
    //    if (leftB) return 1 + rightV;
    //    return 1 + leftV;
    //}



    //void recurse(int& ans, TreeNode* root, int curlen, int prev)
    //{
    //    if (root == NULL) return;
    //    ans = max(ans, curlen);
    //    recurse(ans, root->left, (prev == -1 ? 1 : curlen + 1), -1);
    //    recurse(ans, root->right, (prev == 1 ? 1 : curlen + 1), 1);
    //}
    //int longestZigZag(TreeNode* root)
    //{
    //    int ans = 0;
    //    recurse(ans, root, 0, 0);
    //    return ans;
    //}


    //int longestZigZag(TreeNode* root) {
    //    return dfs(root)[2];
    //}

    //vector<int> dfs(TreeNode* root) {
    //    if (!root) return { -1, -1, -1 };
    //    vector<int> left = dfs(root->left), right = dfs(root->right);
    //    int res = max(max(left[1], right[0]) + 1, max(left[2], right[2]));
    //    return { left[1] + 1, right[0] + 1, res };
    //}



    //int dfs(TreeNode* n, bool left, int depth) {
    //    return n == nullptr ? depth :
    //        max(dfs(left ? n->left : n->right, !left, depth + 1),
    //            dfs(left ? n->right : n->left, left, 0));
    //}
    //int longestZigZag(TreeNode* root) {
    //    return max(dfs(root, true, -1), dfs(root, false, -1));
    //}


//Runtime: 234 ms, faster than 65.45 % of C++ online submissions for Longest ZigZag Path in a Binary Tree.
//Memory Usage : 94.9 MB, less than 46.24 % of C++ online submissions for Longest ZigZag Path in a Binary Tree.
    int lt1372a(TreeNode* root)
    {
        int ans = 0;
        int t2 = dfsa1(root->left, ans, true);
        int t3 = dfsa1(root->right, ans, false);
        ans = max(ans, max(t2, t3));
        return ans;
    }

    // <>
    //pair<int, int>
    int dfsa1(TreeNode* node, int& ans, bool lft)
    {
        if (node == nullptr)
            return 0;

        int t2 = dfsa1(node->left, ans, true);
        int t3 = dfsa1(node->right, ans, false);

        ans = max(ans, max(t2, t3));

        return lft ? t3 + 1 : t2 + 1;
    }

};

int main()
{

    LT1372 lt;


    return 0;
}
