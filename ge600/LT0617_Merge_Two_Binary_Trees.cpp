
#include "../header/myheader.h"

class LT0617
{
public:


// D D
//        if(!t1 && !t2)return NULL;
//        if(t1 && !t2)return t1;
//        if(!t1 && t2)return t2;
//................

//        if (t1 == nullptr) return t2;
//        if (t2 == nullptr) return t1;



//Runtime: 56 ms, faster than 50.15% of C++ online submissions for Merge Two Binary Trees.
//Memory Usage: 33.7 MB, less than 17.63% of C++ online submissions for Merge Two Binary Trees.
    TreeNode* lt0617a(TreeNode* t1, TreeNode* t2)
    {
        TreeNode* ans = recursiona1(t1, t2);
        return ans;
    }

    TreeNode* recursiona1(TreeNode* n1, TreeNode* n2)
    {
        TreeNode* res = n1 == nullptr ? n2 : n1;
        if (res == nullptr)
            return nullptr;

        res->val = (n1 == nullptr ? 0 : n1->val) + (n2 == nullptr ? 0 : n2->val);

        TreeNode* l = recursiona1(n1 == nullptr ? nullptr : n1->left, n2 == nullptr ? nullptr : n2->left);
        TreeNode* r = recursiona1(n1 == nullptr ? nullptr : n1->right, n2 == nullptr ? nullptr : n2->right);
        res->left = l;
        res->right = r;
        return res;
    }

};

int main()
{

    int arr1[] = {1,3,2,5};
    int arr2[] = {2,1,3,-1,4,-1,7};

    TreeNode* t1 = convert2TreeNode(arr1);
    TreeNode* t2 = convert2TreeNode(arr2);

    LT0617 lt;

    TreeNode* node = lt.lt0617a(t1, t2);

    showTreeNode(node, 3);

    // .. some treeNode has lost..
    deleteTreeNode(t1);
    deleteTreeNode(t2);
    deleteTreeNode(node);

    return 0;
}
