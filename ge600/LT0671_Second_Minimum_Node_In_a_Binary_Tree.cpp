
#include "../header/myheader.h"

class LT0671
{
public:



//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Second Minimum Node In a Binary Tree.
//Memory Usage: 7.2 MB, less than 25.12% of C++ online submissions for Second Minimum Node In a Binary Tree.
    int lt0671a(TreeNode* root)
    {
        TreeNode* np = dfsa1(root, root->val);
        return np == nullptr ? -1 : np->val;
    }

    TreeNode* dfsa1(TreeNode* node, int mn)
    {
        if (node == nullptr)
            return nullptr;
        if (node->val > mn)
            return node;
        TreeNode* l = dfsa1(node->left, mn);
        TreeNode* r = dfsa1(node->right, mn);
        if (l == nullptr)
            return r;
        if (r == nullptr)
            return l;
        return (l->val < r->val ? l : r);
    }

};

int main()
{

//    int arr[] = {2,2,5,-1,-1,5,7};
    int arr[] = {2,2,2};

    TreeNode* r = convert2TreeNode(arr);
    LT0671 lt;

    cout<<lt.lt0671a(r)<<endl;
    deleteTreeNode(r);
    return 0;
}
