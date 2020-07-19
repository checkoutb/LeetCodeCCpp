
#include "../header/myheader.h"

class LT0897
{
public:

// D D
//    TreeNode* increasingBST(TreeNode* root, TreeNode* tail = NULL) {
//        if (!root) return tail;
//        TreeNode* res = increasingBST(root->left, root);
//        root->left = NULL;
//        root->right = increasingBST(root->right, tail);
//        return res;
//    }


//Runtime: 4 ms
//Memory Usage: 7.5 MB
    TreeNode* lt0897a(TreeNode* root)
    {
        TreeNode* ans = dfsa1(root);
        return ans;
    }

    TreeNode* dfsa1(TreeNode* node)
    {
        TreeNode* leftChild = node->left;
        TreeNode* rightChild = node->right;
        TreeNode* leftRoot = nullptr;
        TreeNode* rightRoot = nullptr;
        if (leftChild != nullptr && leftChild->val != -1)
        {
            leftRoot = dfsa1(leftChild);
        }
        if (rightChild != nullptr && rightChild->val != -1)
        {
            rightRoot = dfsa1(rightChild);
        }
        if (leftRoot != nullptr)
        {
            TreeNode* t2 = leftRoot;
            while (t2->right != nullptr)
                t2 = t2->right;
            t2->right = node;
        }
        node->left = nullptr;
        node->right = rightRoot;

        return leftRoot == nullptr ? node : leftRoot;
    }

};

int main()
{

    int arr[] = {5,3,6,2,4,-1,8,1,-1,-1,-1,-1,-1,7,9};

    TreeNode* root = convert2TreeNode(arr);
    showTreeNode(root, 4);

    LT0897 lt;

    TreeNode* ans = lt.lt0897a(root);

    showTreeNode(ans);

    return 0;
}
