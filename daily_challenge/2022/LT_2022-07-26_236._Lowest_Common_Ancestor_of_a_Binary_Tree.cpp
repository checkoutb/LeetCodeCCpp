
#include "../../header/myheader.h"

class LT
{
public:

    // D D







    // °Ñ node==p || node==q ÒÆµ½ µİ¹éÇ°¡£
//Runtime: 29 ms, faster than 35.14 % of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
//Memory Usage : 14.3 MB, less than 25.30 % of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
//Runtime: 37 ms, faster than 15.33 % of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
//Memory Usage : 14 MB, less than 96.96 % of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
    TreeNode* lta(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return dfsa1(root, p, q);
    }

    TreeNode* dfsa1(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (node == nullptr)
            return nullptr;

        if (node == p || node == q)
            return node;

        TreeNode* n1 = dfsa1(node->left, p, q);
        TreeNode* n2 = dfsa1(node->right, p, q);

        if (n1 && n2)
            return node;

        return n1 ? n1 : n2;
    }

};

int main()
{

    LT lt;


    return 0;
}
