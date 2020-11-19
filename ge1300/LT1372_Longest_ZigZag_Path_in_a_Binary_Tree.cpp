
#include "../header/myheader.h"

class LT1372
{
public:

// D

//    int longestZigZag(TreeNode* root) {
//        return dfs(root)[2];
//    }
//
//    vector<int> dfs(TreeNode* root) {
//        if (!root) return { -1, -1, -1};
//        vector<int> left = dfs(root->left), right = dfs(root->right);
//        int res = max(max(left[1], right[0]) + 1, max(left[2], right[2]));
//        return {left[1] + 1, right[0] + 1, res};
//    }
// huisu...


// tle.
    int lt1372a(TreeNode* root)
    {
        queue<TreeNode*> que1;
        que1.push(root);
        while (!que1.empty())
        {
            TreeNode* node = que1.front();
            que1.pop();
            if (node->left)
                que1.push(node->left);
            if (node->right)
                que1.push(node->right);
            dfsa1(node, true, -1);
            dfsa1(node, false, -1);
        }
        return ans;
    }
    int ans = 0;

    void dfsa1(TreeNode* node, bool shouldLeft, int len)
    {
        if (node == nullptr)
        {
            ans = max(len, ans);
            return;
        }
        if (shouldLeft)
            dfsa1(node->left, !shouldLeft, len + 1);
        else
            dfsa1(node->right, !shouldLeft, len + 1);
    }

};

int main()
{

    int arr[] = {1,1,1,-1,1,-1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,1};

    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 5);
    LT1372 lt;

    cout<<lt.lt1372a(r);

    return 0;
}
