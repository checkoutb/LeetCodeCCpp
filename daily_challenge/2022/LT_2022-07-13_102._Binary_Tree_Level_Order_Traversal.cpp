
#include "../../header/myheader.h"

class LT
{
public:

    // D D

    // bfs
    // dfs




//Runtime: 6 ms, faster than 58.92 % of C++ online submissions for Binary Tree Level Order Traversal.
//Memory Usage : 12.8 MB, less than 15.61 % of C++ online submissions for Binary Tree Level Order Traversal.
    vector<vector<int>> lta(TreeNode* root)
    {
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> que1;
        que1.push(root);

        while (!que1.empty())
        {
            int sz1 = que1.size();
            vector<int> vi;
            while (sz1-- > 0)
            {
                TreeNode* n = que1.front();
                que1.pop();
                vi.push_back(n->val);
                if (n->left != nullptr)
                    que1.push(n->left);
                if (n->right != nullptr)
                    que1.push(n->right);
            }
            ans.push_back(vi);
        }

        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
