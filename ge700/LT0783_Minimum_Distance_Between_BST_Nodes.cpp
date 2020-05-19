
#include "../header/myheader.h"

class LT0783
{
    int diff = INT_MAX;

public:



//Runtime: 4 ms, faster than 60.23% of C++ online submissions for Minimum Distance Between BST Nodes.
//Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Minimum Distance Between BST Nodes.

// 遍历，vector，sort，遍历。
// BST，所以min diff 必然在 结点与其父结点，不是，，  但 中序遍历即可
    int lt0783a(TreeNode* root)
    {
        int val = -(root->val);
        inOrdera1(root, val);
        return diff;
    }

    void inOrdera1(TreeNode* node, int& val)
    {
        if (node == NULL)
            return;
        inOrdera1(node->left, val);
        diff = min(diff, node->val - val);
        val = node->val;
        inOrdera1(node->right, val);
    }

};

int main()
{

    int arr[] = {4,2,6,1,3,-1,-1};
    TreeNode* node = convert2TreeNode(arr);

    showTreeNode(node);

    LT0783 lt;

    cout<<lt.lt0783a(node)<<endl;

    return 0;
}
