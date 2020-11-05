
#include "../header/myheader.h"

class LT1123
{
public:


// D D

//    pair<TreeNode*, int> helper(TreeNode* root) {
//        if (!root) return {NULL, 0};
//        auto left = helper(root->left);
//        auto right = helper(root->right);
//        if (left.second > right.second)
//            return {left.first, left.second + 1};
//        if (left.second < right.second)
//            return {right.first, right.second + 1};
//        return {root, left.second + 1};
//    }




//Runtime: 16 ms, faster than 89.15% of C++ online submissions for Lowest Common Ancestor of Deepest Leaves.
//Memory Usage: 21.7 MB, less than 8.58% of C++ online submissions for Lowest Common Ancestor of Deepest Leaves.
    TreeNode* lt1123a(TreeNode* root)
    {
        dfsa1(root, 0);
        return ans;
    }

    int mxdepth = 0;
    TreeNode* ans;

    int dfsa1(TreeNode* node, int depth)
    {
        if (node == nullptr)
        {
            return 0;
        }

        depth++;
        if (depth > mxdepth)
        {
            ans = node;
            mxdepth = depth;
        }

        int dl = dfsa1(node->left, depth);
        int dr = dfsa1(node->right, depth);

        if (dl == dr && dr == mxdepth)
        {
            ans = node;
        }
        return max(depth, max(dl, dr));
    }

};

int main()
{

//    int arr[] = {0,1,3,-1,2};
    int arr[] = {3,5,1,6,2,0,8,13,-1,7,4,};
    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 3);

    LT1123 lt;

    TreeNode* n = lt.lt1123a(r);

    showTreeNode(n, 3);

    return 0;
}
