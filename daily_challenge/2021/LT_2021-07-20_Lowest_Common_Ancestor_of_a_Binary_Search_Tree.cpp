
#include "../../header/myheader.h"

class LT
{
public:

// D D

//return l ? r ? root : l : r;

// ... bst....

//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        if ((root -> val > p -> val) && (root -> val > q -> val)) {
//            return lowestCommonAncestor(root -> left, p, q);
//        }
//        if ((root -> val < p -> val) && (root -> val < q -> val)) {
//            return lowestCommonAncestor(root -> right, p, q);
//        }
//        return root;
//    }


//        TreeNode* cur = root;
//        while (true) {
//            if (p -> val < cur -> val && q -> val < cur -> val) {
//                cur = cur -> left;
//            } else if (p -> val > cur -> val && q -> val > cur -> val) {
//                cur = cur -> right;
//            } else {
//                break;
//            }
//        }
//        return cur;




// AC
// 应该最近做过。
    TreeNode* lta(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return dfsa1(root, p, q);
    }

    TreeNode* dfsa1(TreeNode* n, TreeNode* p, TreeNode* q)
    {
        if (n == nullptr)
            return n;
        TreeNode* l = dfsa1(n->left, p, q);
        TreeNode* r = dfsa1(n->right, p, q);
        if (l != nullptr && r != nullptr)
            return n;
        if (p == n || q == n)
            return n;
        return l == nullptr ? r : l;
    }

};

int main()
{
    int arr[] = {6,2,8,0,4,7,9};
    TreeNode* r = convert2TreeNode(arr);
    TreeNode* p = r->left;
    TreeNode* q = r->left->right;


    LT lt;

    TreeNode* a = lt.lta(r, q, p);
    cout<<a->val<<endl;

    deleteTreeNode(r);

    return 0;
}
