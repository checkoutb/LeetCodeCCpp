
#include "../header/myheader.h"

class LT0889
{
public:

// D D
//    int preIndex = 0, posIndex = 0;
//    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
//        TreeNode* root = new TreeNode(pre[preIndex++]);
//        if (root->val != post[posIndex])
//            root->left = constructFromPrePost(pre, post);
//        if (root->val != post[posIndex])
//            root->right = constructFromPrePost(pre, post);
//        posIndex++;
//        return root;
//    }


//Runtime: 16 ms, faster than 65.10% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
//Memory Usage: 24.7 MB, less than 8.33% of C++ online submissions for Construct Binary Tree from Preorder and Postorder Traversal.
    TreeNode* lt0889a(vector<int>& pre, vector<int>& post)
    {
        TreeNode* ans = new TreeNode(pre[0]);
        TreeNode* node = ans;

        ans = dfsa1(pre, post, 0, pre.size() - 1);

        return ans;
    }

    TreeNode* dfsa1(vector<int>& pre, vector<int>& post, int l, int r)
    {
        if (l > r)
            return nullptr;

        TreeNode* node = new TreeNode(pre[l]);
        if (l == r)
            return node;

        int t2 = pre[l + 1];
        int t3 = -1;
        int i3 = -1;
        for (int i = 0; i < post.size(); i++)
        {
            if (post[i] == pre[l])
            {
                t3 = post[i - 1];
                i3 = i;
                break;
            }
        }
        if (t3 == pre[l + 1])
        {
            // left == null;
            node->right = dfsa1(pre, post, l + 1, r);
        }
        else
        {
            int t4 = post[i3 - 1];
            for (int i = 0; i < pre.size(); i++)
            {
                if (pre[i] == t4)
                {
                    i3 = i;
                    break;
                }
            }
            node->left = dfsa1(pre, post, l + 1, i3 - 1);
            node->right = dfsa1(pre, post, i3, r);
        }

        return node;
    }

};

int main()
{
    vector<int> pre = {1,2,4,5,3,6,7};
    vector<int> post = {4,5,2,6,7,3,1};

    LT0889 lt;

    TreeNode* n = lt.lt0889a(pre, post);

    showTreeNode(n, 3);

    return 0;
}
