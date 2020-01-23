
#include "../header/myheader.h"

class LT0700
{
public:


// discuss
//    while (root != nullptr && root->val != val) {
//      root = (root->val > val) ? root->left : root->right;
//    }
//    return root;




// 怎么比 穷举更慢了。。2次都是64ms。。。难道是直接return的原因？。。似乎是的。现在这种，第一次48ms,第二次56ms。。
// 但是 明显 被注释掉的更好吧，完全可以尾递归优化的。。。
//Runtime: 64 ms, faster than 6.62% of C++ online submissions for Search in a Binary Search Tree.
//Memory Usage: 30.4 MB, less than 9.76% of C++ online submissions for Search in a Binary Search Tree.

    TreeNode* lt0700b(TreeNode* root, int val)
    {
        return dfsb1(root, val);
    }

    TreeNode* dfsb1(TreeNode* node, int val)
    {
        if (node == NULL)
            return NULL;
        if (node->val == val)
            return node;
//        if (node->val > val)
//            return dfsb1(node->left, val);
//        return dfsb1(node->right, val);

        TreeNode* ans = (node->val > val) ? dfsb1(node->left, val) : dfsb1(node->right, val);
        return ans;
    }


// 看了details 才想起来BST ......
//Runtime: 52 ms, faster than 71.56% of C++ online submissions for Search in a Binary Search Tree.
//Memory Usage: 30.3 MB, less than 9.76% of C++ online submissions for Search in a Binary Search Tree.

    TreeNode* lt0700a(TreeNode* root, int val)
    {
        return dfsa1(root, val);
    }

    TreeNode* dfsa1(TreeNode* node, int val)
    {
        if (node == NULL)
            return NULL;
        if (node->val == val)
            return node;

        TreeNode* ans = dfsa1(node->left, val);
        if (ans != NULL)
            return ans;
        ans = dfsa1(node->right, val);
//        if (ans != null)
//            return ans;
        return ans;
    }
};

int main()
{
    int arr[] = {4,2,7,1,3};
    int val = 2;

    TreeNode* r = convert2TreeNode(arr);
    LT0700 lt;

    TreeNode* ans = lt.lt0700b(r, val);
    showTreeNode(ans);

    return 0;
}
