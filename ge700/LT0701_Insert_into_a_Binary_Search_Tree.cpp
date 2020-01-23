
#include "../header/myheader.h"

class LT0701
{
public:



// discuss 有 非递归的版本，靠while 遍历。毕竟dfs。只有一条路。




// .. bukexue....。。。好像改测试案例了？ details中 84ms的代码，也要700ms。。。。。
// 84ms 的代码:
//        if(root == NULL){
//            root = new TreeNode(val);
//            return root;
//        }
//        if(val < root->val){
//            root->left = insertIntoBST(root->left,val);
//        }else{
//            root->right = insertIntoBST(root->right,val);
//        }
//        return root;

//Runtime: 700 ms, faster than 5.44% of C++ online submissions for Insert into a Binary Search Tree.
//Memory Usage: 234.1 MB, less than 6.25% of C++ online submissions for Insert into a Binary Search Tree.

    TreeNode* lt0701b(TreeNode* root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        dfsb1(root, val);
        return root;
    }

    TreeNode* dfsb1(TreeNode* node, int val)
    {
        if (node == NULL)
            return new TreeNode(val);
        if (node->val > val)
            node->left = dfsb1(node->left, val);
        else
            node->right = dfsb1(node->right, val);
        return node;
    }



// ....... 慢得超乎想象
//Runtime: 700 ms, faster than 5.44% of C++ online submissions for Insert into a Binary Search Tree.
//Memory Usage: 233.9 MB, less than 6.25% of C++ online submissions for Insert into a Binary Search Tree.

// 例子中，第一种是只插入，不改变树原有形状。第二种是直接把新节点放在根的位置，然后对树做变形，来让它满足bst。

    TreeNode* lt0701a(TreeNode* root, int val)
    {
        if (root == NULL)
        {
            return new TreeNode(val);
        }
        dfsa1(NULL, root, val, true);
        return root;
    }

    void dfsa1(TreeNode* parent, TreeNode* node, int val, bool isLeft)
    {
        if (node == NULL)
        {
            TreeNode* n = new TreeNode(val);
            if (isLeft)
                parent->left = n;
            else
                parent->right = n;
            return;
        }
        if (node->val > val)
            dfsa1(node, node->left, val, true);
        else
            dfsa1(node, node->right, val, false);
    }

};

int main()
{
    int arr[] = {4,2,7,1,3};
    int val = 5;

    TreeNode* root = convert2TreeNode(arr);
    LT0701 lt;

    TreeNode* ans = lt.lt0701a(root, val);

    showTreeNode(ans);

    return 0;
}
