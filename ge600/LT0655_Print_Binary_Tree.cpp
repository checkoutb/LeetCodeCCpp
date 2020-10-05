
#include "../header/myheader.h"

class LT0655
{
public:


// D D

//    int dfs(TreeNode* root) {
//        if(root == NULL) return 0;
//        return 1+max(dfs(root->left), dfs(root->right));
//    }


//int rows = height, columns = (int) (Math.pow(2, height) - 1);




//Runtime: 8 ms, faster than 6.48% of C++ online submissions for Print Binary Tree.
//Memory Usage: 8.6 MB, less than 51.29% of C++ online submissions for Print Binary Tree.
    vector<vector<string>> lt0655a(TreeNode* root)
    {
        int depth = dfsa1(root, 0);
        int cols = 1;
        for (int i = 0; i < depth - 1; i++)
        {
            cols += (1 << i) * 2;
        }
        vector<vector<string>> ans(depth, vector<string>(cols, ""));
        dfsinita1(root, ans, 0, 0, cols - 1);
        return ans;
    }

    int dfsa1(TreeNode* node, int depth)
    {
        if (node == nullptr)
            return depth;
        return max(dfsa1(node->left, depth + 1), dfsa1(node->right, depth + 1));
    }

    // [st, en]
    void dfsinita1(TreeNode* node, vector<vector<string>>& ans, int row, int st, int en)
    {
        if (node == nullptr)
            return;
        int mid = (st + en) / 2;
        ans[row][mid] = to_string(node->val);
        dfsinita1(node->left, ans, row + 1, st, mid - 1);
        dfsinita1(node->right, ans, row + 1, mid + 1, en);
    }

};

int main()
{

    int arr[] = {1,2,3,-1,4};

    TreeNode* n = convert2TreeNode(arr);
    LT0655 lt;

    vector<vector<string>> vv = lt.lt0655a(n);
    for_each(begin(vv), end(vv), [](vector<string>& vs){ for_each(begin(vs), end(vs), [](string& s) {cout<<s<<",";}); cout<<endl; });

    deleteTreeNode(n);
    return 0;
}
