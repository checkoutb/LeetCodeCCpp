
#include "../header/myheader.h"

class LT0669
{
public:




//Runtime: 56 ms, faster than 6.39% of C++ online submissions for Trim a Binary Search Tree.
//Memory Usage: 24.4 MB, less than 5.18% of C++ online submissions for Trim a Binary Search Tree.
    TreeNode* lt0669a(TreeNode* root, int low, int high)
    {
        return dfsa1(root, low, high);
    }

    TreeNode* dfsa1(TreeNode* node, int l, int h)
    {
        if (node == nullptr)
            return nullptr;

        if (node->val < l)
        {
            return dfsa1(node->right, l, h);
        }

        if (node->val > h)
        {
            return dfsa1(node->left, l, h);
        }
        node->left = dfsa1(node->left, l, h);
        node->right = dfsa1(node->right, l, h);
        return node;
    }

};

int main()
{

    int arr[] = {1,0,2};
    int l{1}, h{2};

    TreeNode* node = convert2TreeNode(arr);
    LT0669 lt;

    TreeNode* n = lt.lt0669a(node, l, h);
    showTreeNode(n, 3);

    return 0;
}
