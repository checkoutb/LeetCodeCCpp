
#include "../header/myheader.h"

class LT0538
{
public:

// int* sum   int& sum    类变量保存sum。


//Runtime: 36 ms, faster than 72.25% of C++ online submissions for Convert BST to Greater Tree.
//Memory Usage: 23.5 MB, less than 100.00% of C++ online submissions for Convert BST to Greater Tree.
// 反向中序遍历。
    TreeNode* lt0538a(TreeNode* root)
    {
        dfsa1(root, 0);
        return root;
    }

    int dfsa1(TreeNode* node, int value)
    {
        if (node == NULL)
        {
            return value;
        }
        int v2 = dfsa1(node->right, value) + node->val;
        node->val = v2;
        v2 = dfsa1(node->left, v2);
        return v2;
    }

};

int main()
{
    int arr[] = {5,2,13};
    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r);

    LT0538 lt;
    lt.lt0538a(r);
    cout<<endl<<"--------------------------"<<endl;
    showTreeNode(r);

    return 0;
}
