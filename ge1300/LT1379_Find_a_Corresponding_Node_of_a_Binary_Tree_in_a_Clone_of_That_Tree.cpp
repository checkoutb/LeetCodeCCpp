
#include "../header/myheader.h"

class LT1379
{
public:

// D D

//  return orig == nullptr ? nullptr :
//    orig == targ ? clone :
//      getTargetCopy(orig->left, clone->left, targ) ?: getTargetCopy(orig->right, clone->right, targ);

// 我这个没有实现follow up 的。 discuss里基本都实现了。


//Runtime: 712 ms, faster than 75.34% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
//Memory Usage: 166.1 MB, less than 48.80% of C++ online submissions for Find a Corresponding Node of a Binary Tree in a Clone of That Tree.
// target 是指向 original树的，
// 如果树中val 可以重复， 那么就应该 同时 遍历 original,cloned, 根据target 在 original 中找 == 的结点。
    TreeNode* lt1379a(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        return dfsa1(cloned, target->val);
    }

    TreeNode* dfsa1(TreeNode* cloned, int tar)
    {
        if (cloned == nullptr)
            return nullptr;
        if (cloned->val == tar)
            return cloned;
        TreeNode* l = dfsa1(cloned->left, tar);
        if (l)
            return l;
        TreeNode* r = dfsa1(cloned->right, tar);
        return r;
    }

};

int main()
{

    LT1379 lt;


    return 0;
}
