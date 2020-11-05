
#include "../header/myheader.h"

class LT1110
{
public:


// D D

// dfs 直接返回 结点/nullptr。




//Runtime: 28 ms, faster than 92.59% of C++ online submissions for Delete Nodes And Return Forest.
//Memory Usage: 26.7 MB, less than 5.02% of C++ online submissions for Delete Nodes And Return Forest.
    vector<TreeNode*> lt1110a(TreeNode* root, vector<int>& to_delete)
    {
        vector<TreeNode*> ans;
        unordered_set<int> delset(begin(to_delete), end(to_delete));
        if (!dfsa1(root, delset, ans))
        {
            ans.push_back(root);
        }
        return ans;
    }

    // true : delete
    bool dfsa1(TreeNode* node, unordered_set<int>& delset, vector<TreeNode*>& ans)
    {
        if (node == nullptr)
            return false;
        bool ansb = false;
        if (delset.find(node->val) != delset.end())
        {
            ansb = true;
        }
        bool l = dfsa1(node->left, delset, ans);
        bool r = dfsa1(node->right, delset, ans);
        if (l)
            node->left = nullptr;
        if (r)
            node->right = nullptr;
        if (ansb)
        {
            if (node->left != nullptr)
                ans.push_back(node->left);
            if (node->right != nullptr)
                ans.push_back(node->right);
        }
        return ansb;
    }

};

int main()
{

    int arr[] = {1,2,3,4,5,6,7};
    vector<int> del = {3,5};
    TreeNode* r = convert2TreeNode(arr);

    LT1110 lt;

    vector<TreeNode*> ans = lt.lt1110a(r, del);

    for (TreeNode* n : ans)
    {
        showTreeNode(n, 3);
        cout<<endl<<" - - - -- - "<<endl;
    }

    return 0;
}
