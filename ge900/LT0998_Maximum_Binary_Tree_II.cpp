
#include "../header/myheader.h"

class LT0998
{
public:


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Binary Tree II.
//Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Maximum Binary Tree II.
// append在最后，所以val结点必然是其父结点的右子结点，且原先的结点必然是val结点的左子结点
    TreeNode* lt0998b(TreeNode* root, int val)
    {
        if (val > root->val)
        {
            TreeNode* node = new TreeNode(val, root, nullptr);
            return node;
        }
        TreeNode* ans = root;
        while (root->right != nullptr && root->right->val > val)
        {
            root = root->right;
        }
        TreeNode* node = new TreeNode(val, root->right, nullptr);
        root->right = node;
        return ans;
    }




// error
// 。。是真的append。。
// Example 3, 5-4-2-1  5-3  这种可以吗？
// 搜索的时候可以任意选择左还是右吧？
    TreeNode* lt0998a(TreeNode* root, int val)
    {
        if (val > root->val)
        {
            TreeNode* node = new TreeNode(val, root, nullptr);
            return node;
        }
        TreeNode* ans = root;
        while (root->left != nullptr || root->right != nullptr)
        {
            int vl = root->left == nullptr ? val - 1 : root->left->val;
            int vr = root->right == nullptr ? val - 1 : root->right->val;
            int vmx = std::max(vl, vr);
            if (val > vmx)
                break;
            root = vl < vr ? root->right : root->left;
        }
        TreeNode* node = new TreeNode(val, root->left, root->right);
        root->right = nullptr;
        root->left = node;
        return ans;
    }

};

int main()
{

    int arr[] = {5,2,4,-1,1,-1,-1};
    int val = 3;

    TreeNode* root = convert2TreeNode(arr);
    showTreeNode(root, 3);
    cout<<"================="<<endl;

    LT0998 lt;

    TreeNode* ans = lt.lt0998b(root, val);

    showTreeNode(ans, 3);

    return 0;
}
