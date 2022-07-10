
#include "../header/myheader.h"

class LT2331
{
public:

    // D D





//Runtime: 27 ms, faster than 100.00 % of C++ online submissions for Evaluate Boolean Binary Tree.
//Memory Usage : 15 MB, less than 100.00 % of C++ online submissions for Evaluate Boolean Binary Tree.
    bool lt2331a(TreeNode* root)
    {
        return dfsa1(root);
    }

    bool dfsa1(TreeNode* node)
    {

        return node->val < 2 ? (node->val == 1) : (node->val == 2 ? (dfsa1(node->left) || dfsa1(node->right)) : (dfsa1(node->left) && dfsa1(node->right)));         // or switch

        //if (node->left == nullptr)
        //    return node->value == 1;

        //if (node->value <= 1)

        //bool lft = dfsa1(node->left)
    }

};

int main()
{

    LT2331 lt;


    return 0;
}
