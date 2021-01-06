
#include "../header/myheader.h"

class LT1038
{
public:

// D D

//    int pre = 0;
//    TreeNode* bstToGst(TreeNode* root) {
//        if (root->right) bstToGst(root->right);
//        pre = root->val = pre + root->val;
//        if (root->left) bstToGst(root->left);
//        return root;
//    }


// stack



//Runtime: 4 ms, faster than 55.49% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
//Memory Usage: 8.7 MB, less than 44.51% of C++ online submissions for Binary Search Tree to Greater Sum Tree.
    TreeNode* lt1038a(TreeNode* root)
    {
        dfsa1(root);
        return root;
    }
    int sum2 = 0;
    void dfsa1(TreeNode* node)
    {
        if (node == nullptr)
            return;
        dfsa1(node->right);
        sum2 += node->val;
        node->val = sum2;
        dfsa1(node->left);
    }

};

int main()
{
    int arr[] = {4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};

    TreeNode* r = convert2TreeNode(arr);

    LT1038 lt;

    TreeNode* n = lt.lt1038a(r);

    showTreeNode(n, 5);

    return 0;
}
