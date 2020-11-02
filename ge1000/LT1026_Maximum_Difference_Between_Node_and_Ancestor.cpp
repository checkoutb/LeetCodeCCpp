
#include "../header/myheader.h"

class LT1026
{
public:



//Runtime: 8 ms, faster than 67.02% of C++ online submissions for Maximum Difference Between Node and Ancestor.
//Memory Usage: 11.8 MB, less than 5.64% of C++ online submissions for Maximum Difference Between Node and Ancestor.
    int lt1026a(TreeNode* root)
    {
        int ans = dfsa1(root, root->val, root->val);
        return ans;
    }

    int dfsa1(TreeNode* node, int mx, int mn)
    {
        if (node == nullptr)
            return -1;
        int val = std::max(std::abs(node->val - mx), std::abs(node->val - mn));
        val = max(max(val, dfsa1(node->left, max(mx, node->val), min(mn, node->val))), dfsa1(node->right, max(mx, node->val), min(mn, node->val)));
        return val;
    }

};

int main()
{

    int v[] = {8,3,10,1,6,-1,14,-1,-1,4,7,-1,-1,13};
    TreeNode* node = convert2TreeNode(v);

    showTreeNode(node, 5);
    cout<<endl<<endl;

    LT1026 lt;

    cout<<lt.lt1026a(node)<<endl;

    return 0;
}
