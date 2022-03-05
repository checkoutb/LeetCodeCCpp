
#include "../header/myheader.h"

class LT2096
{
public:




// g

// hint。。。  LCA -> st 的路径 全换成 U 就可以了。。

// 。。。


// LCA lowest common ancestor
    string lt2096a(TreeNode* root, int startValue, int destValue)
    {

    }

    // 1st 2en 3both
    int dfsa2(TreeNode* node, int st, int en, bool isleft)
    {
        if (node == nullptr)
            return 0;

        int tl = dfsa2(node->left, st, en, true);
        int tr = dfsa2(node->right, st, en, false);


//        if (node->val == st)
//        {
//
//        }
//        else if (node->val == en)
//        {
//
//        }
//        else
//        {
//
//        }
    }

//    // pair.first / tag : 1 find start  2 find end  3 find all
//    pair<int, string> dfsa1(TreeNode* node, int st, int en, int tag)
//    {
//        if (node == nullptr)
//            return {0, ""};
//
//        if (node->val == st)
//        {
//
//        }
//        else if (node->val == en)
//        {
//
//        }
//        else
//        {
//
//        }
//    }

};

int main()
{

    LT2096 lt;

//    string s = nullptr;     // not valid
//    cout<<s<<endl;

    return 0;
}
