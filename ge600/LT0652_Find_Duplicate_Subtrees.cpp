
#include "../header/myheader.h"

class LT0652
{
public:


// D D chabuduo.


//Runtime: 72 ms, faster than 35.19% of C++ online submissions for Find Duplicate Subtrees.
//Memory Usage: 77 MB, less than 6.68% of C++ online submissions for Find Duplicate Subtrees.
    vector<TreeNode*> lt0652b(TreeNode* root)
    {
        unordered_map<string, vector<TreeNode*>> map2;
        vector<TreeNode*> ans;
        dfsb1(root, map2);
        for (auto p : map2)
        {
            if (p.second.size() > 1)
                ans.push_back(p.second[0]);
        }
        return ans;
    }

    string dfsb1(TreeNode* node, unordered_map<string, vector<TreeNode*>>& map2)
    {
        if (node == nullptr)
            return ",";
        string l = dfsb1(node->left, map2);
        string r = dfsb1(node->right, map2);
        string ans = "|" + to_string(node->val) + l + r + "|";
        map2[ans].push_back(node);
        return ans;
    }


    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
    {
        unordered_map<int, vector<TreeNode*>> map2;
        stack<TreeNode*> stk1({root});
        while (!stk1.empty())
        {
            TreeNode* node = stk1.top();
            stk1.pop();
            map2[node->val].push_back(node);
            if (node->left != nullptr)
                stk1.push(node->left);
            if (node->right != nullptr)
                stk1.push(node->right);
        }
        unordered_map<TreeNode*, string> map3;
        for (unordered_map<int, vector<TreeNode*>>::iterator it = map2.begin(); it != map2.end(); it++)
        {
            vector<TreeNode*> vtp = it->second;
            for (int i = 0; i < vtp.size(); i++)
            {
                for (int j = i + 1; j < vtp.size(); j++)
                {
                    // ... 如果有3个相同呢。。

                }
            }
        }
        return {};
    }

    bool isEquala1(TreeNode* n1, TreeNode* n2)
    {
        return false;
    }

};

int main()
{
//    int arr[] = {2,1,1};
    int arr[] = {2,2,2,3,-1,3,-1};

    TreeNode* node = convert2TreeNode(arr);

    LT0652 lt;

    vector<TreeNode*> vt = lt.lt0652b(node);

    cout<<vt.size()<<endl;
    for (TreeNode*& np : vt)
    {
        cout<<np->val<<endl;
    }

    deleteTreeNode(node);
    return 0;
}
