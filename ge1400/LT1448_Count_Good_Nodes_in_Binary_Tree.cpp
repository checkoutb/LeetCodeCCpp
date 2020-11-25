
#include "../header/myheader.h"

class LT1448
{
public:

// D D




//Runtime: 180 ms, faster than 27.84% of C++ online submissions for Count Good Nodes in Binary Tree.
//Memory Usage: 87.9 MB, less than 8.81% of C++ online submissions for Count Good Nodes in Binary Tree.
    int lt1448a(TreeNode* root)
    {
        return dfsa1(root, root->val);
    }

    int dfsa1(TreeNode* node, int mx)
    {
        if (node == nullptr)
            return 0;
        int mx2 = max(mx, node->val);
        return (node->val >= mx) + dfsa1(node->left, mx2) + dfsa1(node->right, mx2);
    }

};

int main()
{

    int arr[] = {3,1,4,3,-1,1,5};

    TreeNode* r = convert2TreeNode(arr);
    LT1448 lt;

    cout<<lt.lt1448a(r);

    return 0;
}
