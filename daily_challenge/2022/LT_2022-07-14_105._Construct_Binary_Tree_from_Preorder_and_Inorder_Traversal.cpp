
#include "../../header/myheader.h"

class LT
{
public:

    // D D


    //def buildTree(self, preorder, inorder) :
    //    def build(stop) :
    //        if inorder and inorder[-1] != stop :
    //            root = TreeNode(preorder.pop())
    //            root.left = build(root.val)
    //            inorder.pop()
    //            root.right = build(stop)
    //            return root
    //    preorder.reverse()
    //    inorder.reverse()
    //    return build(None)




//Runtime: 24 ms, faster than 76.46 % of C++ online submissions for Construct Binary Tree from Preorderand Inorder Traversal.
//Memory Usage : 26.4 MB, less than 47.35 % of C++ online submissions for Construct Binary Tree from Preorderand Inorder Traversal.
    // 先序的第一个 可以把 中序划分成2部分。
    // 而且 先序 也自带 左子树 在右子树之前
    TreeNode* lta(vector<int>& preorder, vector<int>& inorder)
    {
        int sz1 = inorder.size();
        unordered_map<int, int> map2;
        for (int i = 0; i < sz1; ++i)
        {
            map2[inorder[i]] = i;
        }

        int pi = 0;
        TreeNode* ans = dfsa1(preorder, inorder, map2, pi, 0, sz1 - 1);
        return ans;
    }

    TreeNode* dfsa1(vector<int>& pre, vector<int>& in, unordered_map<int, int>& map2, int& pi, int sti, int eni)
    {
        if (sti > eni)
            return nullptr;

        TreeNode* node = new TreeNode(pre[pi]);

        int idx = map2[pre[pi]];

        pi++;

        node->left = dfsa1(pre, in, map2, pi, sti, idx - 1);
        node->right = dfsa1(pre, in, map2, pi, idx + 1, eni);

        return node;
    }

};

int main()
{

    LT lt;

    myvi v = { 3,9,20,15,7 };
    myvi v2 = { 9,3,15,20,7 };

    TreeNode* n = lt.lta(v, v2);

    showTreeNode(n, 5);

    return 0;
}
