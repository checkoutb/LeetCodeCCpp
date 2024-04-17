
#include "../../header/myheader.h"

class LT
{
public:




// Runtime
// 0ms
// Beats100.00%of users with C++
// Memory
// 19.49MB
// Beats87.55%of users with C++

    // [25,1,null,0,0,1,null,null,null,0] -> ababz,   not abz

    string smallestFromLeaf(TreeNode* root)
    {
        string ans = dfsa1(root, 0);
        return ans;
    }

    string dfsa1(TreeNode* node, int mx)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            return string(1, static_cast<char>('a' + node->val));
        }
        string ans;
        mx = std::max(mx, node->val);
        if (node->left != nullptr && node->right != nullptr)
        {
             // ans = std::min(dfsa1(node->left), dfsa1(node->right));
            string s1 = dfsa1(node->left, mx);
            string s2 = dfsa1(node->right, mx);
            s1.push_back(static_cast<char>('a' + mx));
            s2.push_back(static_cast<char>('a' + mx));
            ans = std::min(s1, s2);
            ans.back() = static_cast<char>('a' + node->val);
#ifdef __test
            std::cout<<s1<<" . "<<s2<<" = "<<ans<<std::endl;
#endif
        }
        else
        {
            ans = node->left != nullptr ? dfsa1(node->left, mx) : dfsa1(node->right, mx);
            ans.push_back(static_cast<char>('a' + node->val));
        }

        return ans;
    }
};

int main()
{

    LT lt;

    TreeNode root {4};
    root.left = new TreeNode(0);
    root.right = new TreeNode{1};
    root.left->right = new TreeNode(1);

    cout<<lt.smallestFromLeaf(&root)<<std::endl;

    return 0;
}
