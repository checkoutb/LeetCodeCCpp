
#include "../../header/myheader.h"

class LT
{
public:

    // D D




//Runtime: 5 ms, faster than 54.12 % of C++ online submissions for Binary Tree Right Side View.
//Memory Usage : 12.1 MB, less than 19.97 % of C++ online submissions for Binary Tree Right Side View.
    vector<int> lta(TreeNode* root)
    {
        vector<int> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> que1;
        que1.push(root);

        while (!que1.empty())
        {
            int sz1 = que1.size();
            for (int i = 0; i < sz1; ++i)
            {
                TreeNode* node = que1.front();
                que1.pop();

                if (i == 0)
                {
                    ans.push_back(node->val);
                }
                if (node->right != nullptr)
                    que1.push(node->right);
                if (node->left != nullptr)
                    que1.push(node->left);
            }
        }

        return ans;
    }

};

int main()
{

    LT lt;


    return 0;
}
