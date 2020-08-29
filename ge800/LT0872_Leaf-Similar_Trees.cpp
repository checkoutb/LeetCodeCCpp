
#include "../header/myheader.h"

class LT0872
{
public:


// D D
//if(root->left==NULL&&root->right==NULL) s+=to_string(root->val)+"#";

//    int dfs(stack<TreeNode*>& s) {
//        while (true) {
//            TreeNode* node = s.top(); s.pop();
//            if (node->right) s.push(node->right);
//            if (node->left) s.push(node->left);
//            if (!node->left && !node->right) return node->val;
//        }
//    }
// 用stack封装，每次返回下一个叶子的值。


//Runtime: 4 ms, faster than 84.72% of C++ online submissions for Leaf-Similar Trees.
//Memory Usage: 12.9 MB, less than 59.10% of C++ online submissions for Leaf-Similar Trees.
    bool lt0872a(TreeNode* root1, TreeNode* root2)
    {
        vector<int> v1;
        getLeavesa1(root1, v1);
        vector<int> v2;
        getLeavesa1(root2, v2);

        if (v1.size() != v2.size())
            return false;

        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
                return false;
        }
        return true;
    }

    void getLeavesa1(TreeNode* n, vector<int>& v)
    {
        if (n->left == nullptr && n->right == nullptr)
        {
            v.push_back(n->val);
        }
        if (n->left != nullptr)
        {
            getLeavesa1(n->left, v);
        }
        if (n->right != nullptr)
        {
            getLeavesa1(n->right, v);
        }
    }
};

int main()
{

    LT0872 lt;


    return 0;
}
