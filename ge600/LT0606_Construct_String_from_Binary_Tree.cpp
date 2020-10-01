
#include "../header/myheader.h"

class LT0606
{
public:


// D D

//        return !t ? "" : to_string(t->val) + (t->left ? "(" + tree2str(t->left) + ")" : t->right ? "()" : "")
//                                           + (t->right ? "(" + tree2str(t->right) + ")" : "");




// ... 2个例子过了后，一次性就过了。。 看来是要省略的。  本来还想先算出深度，然后低于这个深度的全补()，只有最后一行的最后的空结点不需要补()。
//Runtime: 28 ms, faster than 84.26% of C++ online submissions for Construct String from Binary Tree.
//Memory Usage: 54.8 MB, less than 50.49% of C++ online submissions for Construct String from Binary Tree.
// 最下面一层的最后的空结点不需要输出的。。。问题是 如果例子中的4 是3的子结点，那么 2结点下面的2个()()要不要省略。
    string lt0606a(TreeNode* t)
    {
        string ans = recursiona1(t, 0);
        return ans;
    }

    int mxlv = 0;

    string recursiona1(TreeNode* t, int lv)
    {
        if (t == nullptr)
            return "";
        string l = recursiona1(t->left, lv + 1);
        string r = recursiona1(t->right, lv + 1);
        if (r == "" && l == "")
            return to_string(t->val);
        if (r == "" && l != "")
            return to_string(t->val) + "(" + l + ")";
        return to_string(t->val) + "(" + l + ")"+ "(" + r + ")";
    }

};

int main()
{

    int arr[] = {1,2,3,-1,4};
    TreeNode* n = convert2TreeNode(arr);
    showTreeNode(n, 4);

    LT0606 lt;

    cout<<lt.lt0606a(n)<<endl;

    deleteTreeNode(n);

    return 0;
}
