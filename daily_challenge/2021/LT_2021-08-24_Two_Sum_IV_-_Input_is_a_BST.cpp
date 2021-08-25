
#include "../../header/myheader.h"

class LT
{
public:

// D D

//        while (n != nullptr) {
//            if (n->val == target) {
//                return n != node;
//            } else if (n->val > target) {
//                n = n->left;
//            } else {
//                n = n->right;
//            }
//        }
// bs 不需要dfs。。


// inorder 转成 vector
//        while(i<j){
//            int sum = ans[i] + ans[j];
//            if(sum == k)
//                return true;
//            else if(sum < k)
//                i++;
//            else
//                j--;
//        }




// AC   28ms
    bool ltb(TreeNode* root, int k)
    {
        return dfsb1(root, root, k);
    }

    bool dfsb1(TreeNode* root, TreeNode* node, int tar)
    {
        if (node == nullptr)
            return false;
        int t2 = tar - node->val;
        if (bs1(root, t2, node))
        {
            return true;
        }
        if (dfsb1(root, node->left, tar))
            return true;
        return dfsb1(root, node->right, tar);
    }

    bool bs1(TreeNode* node, int tar, TreeNode* skip)
    {
        if (node == nullptr)
            return false;
        if (node != skip && node->val == tar)
            return true;
        if (node->val > tar)
        {
            return bs1(node->left, tar, skip);
        }
        return bs1(node->right, tar, skip);
    }


// AC   44ms
// bst 是dfs 快，还是  二分快。
    bool lta(TreeNode* root, int k)
    {
        unordered_set<int> set2;
        return dfsa1(root, k, set2);
    }

    bool dfsa1(TreeNode* node, int tar, unordered_set<int>& set2)
    {
        if (node == nullptr)
            return false;
        int t2 = tar - node->val;
        if (set2.find(t2) != set2.end())
        {
            return true;
        }
        set2.insert(node->val);
        if (dfsa1(node->left, tar, set2))
            return true;
        return dfsa1(node->right, tar, set2);
    }

};

int main()
{

    LT lt;


    return 0;
}
