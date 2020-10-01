
#include "../header/myheader.h"

class LT0623
{
public:



//Runtime: 24 ms, faster than 56.10% of C++ online submissions for Add One Row to Tree.
//Memory Usage: 24.8 MB, less than 41.64% of C++ online submissions for Add One Row to Tree.
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        TreeNode* n = recursiona1(root, v, d, 1, true);
        return n;
    }

    TreeNode* recursiona1(TreeNode* node, int v, int d, int nowD, bool isLeft)
    {
        if (node == nullptr)
        {
            if (nowD == d)
            {
                return new TreeNode(v);
            }
            return nullptr;
        }
        if (nowD == d - 1)
        {
            node->left = recursiona1(node->left, v, d, nowD + 1, true);
            node->right = recursiona1(node->right, v, d, nowD + 1, false);
        }
        else if (nowD == d)
        {
            TreeNode* ans = new TreeNode(v);
            if (isLeft)
            {
                ans->left = node;
            }
            else
            {
                ans->right = node;
            }
            return ans;
        }
        else
        {
            recursiona1(node->left, v, d, nowD + 1, true);
            recursiona1(node->right, v, d, nowD + 1, false);
        }
        return node;
    }

};

int main()
{

    int arr[] = {4,2,6,3,1,5};
    int v{1}, d{2};

    TreeNode* n = convert2TreeNode(arr);

    LT0623 lt;

    TreeNode* ans = lt.addOneRow(n,v,d);

    showTreeNode(ans, 5);

    deleteTreeNode(ans);

    return 0;
}
