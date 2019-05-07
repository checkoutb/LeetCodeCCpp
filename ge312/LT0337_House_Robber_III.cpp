
#include "../header/myheader.h"

class LT0337
{
public:

    // dp, 保存node。..递归从底往上。

//    Runtime: 32 ms, faster than 48.48% of C++ online submissions for House Robber III.
//Memory Usage: 26.4 MB, less than 19.88% of C++ online submissions for House Robber III.

// 这个没炸，写TreeNode倒是爆炸了。。

// discuss
//    public int rob(TreeNode root) {
//        if (root == null) return 0;
//        return Math.max(robInclude(root), robExclude(root));
//    }
//    public int robInclude(TreeNode node) {
//        if(node == null) return 0;
//        return robExclude(node.left) + robExclude(node.right) + node.val;
//    }
//    public int robExclude(TreeNode node) {
//        if(node == null) return 0;
//        return rob(node.left) + rob(node.right);          // rob。
//    }



// 一步步，后续 + map<TreeNode, int> 作为参数..再后来就一样了。
//    int val = 0;
//    if (root.left != null) {
//        val += rob(root.left.left) + rob(root.left.right);
//    }
//    if (root.right != null) {
//        val += rob(root.right.left) + rob(root.right.right);
//    }
//    return Math.max(val + root.val, rob(root.left) + rob(root.right));



    int lt0337a(TreeNode* root)
    {
        if (root == null)
        {
            return 0;
        }
        int* arr = recursiona1(root);
        return max(arr[0], arr[1]);
    }

    int* recursiona1(TreeNode* node)
    {
//        int result[2] = {};     // 0: rob this node, 1:not rob.
        int* result = NULL;
        int* arrl = new int[2]{0,0};
        int* arrr = new int[2]{0,0};
        if (node->left == nullptr && node->right == nullptr)
        {
            result = new int[2] {node->val, 0};
        }
        else
        {
            if (node->left != NULL)         // 这个null可以放在递归最开始判断。。。
            {
                arrl = recursiona1(node->left);
            }
            if (node->right != NULL)
            {
                arrr = recursiona1(node->right);
            }
            result = new int[2] {arrl[1] + arrr[1] + node->val, max(arrl[0], arrl[1]) + max(arrr[0], arrr[1])};
        }
        #ifdef __test
        cout<<result[0]<<", "<<result[1]<<"....."<<node->val<<endl;
        #endif // __test

        return result;
    }

};

int main()
{
//    int arr[] = {3,2,3,-1,3,-1,1};
    int arr[] = {3,4,5,1,3,-1,1};
    TreeNode* root = convert2TreeNode(arr);
    cout<<endl<<"..............."<<endl;
//    cout<<(int) root<<endl;
//    cout<<root->val<<endl;
//    while (root->left != NULL)
//    {
//        cout<<root->val<<".."<<root->left->val<<"/////"<<root->right->val<<endl;;
//        root = root->left;
//    }
    showTreeNode(root, 3);

//    TreeNode root(3);
//    root.left = new struct TreeNode(1);     // struct.必须的...
//    showTreeNode(&root);

    LT0337 lt;
    cout<<endl<<lt.lt0337a(root);
    return 0;
}
