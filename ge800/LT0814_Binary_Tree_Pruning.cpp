
#include "../header/myheader.h"

class LT0814
{
public:


// D D
// if (!sum)
// sumOfTree(root) == 0; return NULL;

// 为0，return null，否则 return 结点，这样就不需要int的转换了。能直接设置left=null这种。




//Runtime: 4 ms, faster than 60.78% of C++ online submissions for Binary Tree Pruning.
//Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Binary Tree Pruning.
// 感觉是说，子树中不包含0，就修剪掉。 后序
    TreeNode* lt0814a(TreeNode* root)
    {
        dfsa1(root);
        return root;
    }

    int dfsa1(TreeNode* node)
    {
        if (node == NULL)
            return 0;

        int sum = dfsa1(node->left);
        if (sum == 0)
            node->left = nullptr;
        int sum2 = dfsa1(node->right);
        if (sum2 == 0)
            node->right = nullptr;

        return sum + node->val + sum2;
    }

};

int main()
{

//    int arr[] = {1,-1,0,-1,-1,0,1};
    int arr[] = {1,0,1,0,0,0,1};
    TreeNode* root = convert2TreeNode(arr);

    showTreeNode(root, 3);

    LT0814 lt;

    cout<<"================"<<endl;
    root = lt.lt0814a(root);

    showTreeNode(root, 3);

    return 0;
}
