
#include "../header/myheader.h"

class LT0572
{
public:

// D D
//    public boolean isSubtree(TreeNode s, TreeNode t) {
//        if (s == null) return false;
//        if (isSame(s, t)) return true;
//        return isSubtree(s.left, t) || isSubtree(s.right, t);
//    }
//
//    private boolean isSame(TreeNode s, TreeNode t) {
//        if (s == null && t == null) return true;
//        if (s == null || t == null) return false;
//
//        if (s.val != t.val) return false;
//
//        return isSame(s.left, t.left) && isSame(s.right, t.right);
//    }



//Runtime: 60 ms, faster than 19.04% of C++ online submissions for Subtree of Another Tree.
//Memory Usage: 72.1 MB, less than 5.01% of C++ online submissions for Subtree of Another Tree.
// in-order => string,  find
    bool lt0572a(TreeNode* s, TreeNode* t)
    {
        string s1 = convert2string(s);
        string t1 = convert2string(t);
        #ifdef __test
        cout<<s1<<endl<<t1<<endl;
        #endif // __test
        return s1.find(t1) != std::string::npos;
    }

    string convert2string(TreeNode* s)
    {
        if (s == nullptr)
            return ".";
        string left = convert2string(s->left);
        string val = to_string(s->val);
        string right = convert2string(s->right);
        return "|" + left + val + right + "|";      // 避免，subtree的最左结点再来一个左结点。还有  12-3-4 和 2-31-4，这2个中序是一样的。
    }

};

//void deleteTreeNode(TreeNode* n)
//{
//    if (n == nullptr)
//        return;
//    deleteTreeNode(n->left);
//    deleteTreeNode(n->right);
//    delete n;
//    return;
//}

int main()
{

    int arr[] = {3,4,5,1,2,-1,-1,-1,-1,0};
    int arr2[] = {4,1,2};

    TreeNode* s = convert2TreeNode(arr);
    TreeNode* t = convert2TreeNode(arr2);

    LT0572 lt;

    cout<<lt.lt0572a(s, t)<<endl;

    cout<<" ====== "<<endl;

//    delete s;
//    delete t;

    deleteTreeNode(s);
    deleteTreeNode(t);

    cout<<" - - -"<<endl;

    return 0;
}
