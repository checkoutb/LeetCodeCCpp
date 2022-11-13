
#include "../header/myheader.h"

class LT2458
{
public:

    // D D


    //Pre - order dfs the tree(node, left, right),
    //update res[i] to the max height before node i in preorder,
    //can cover all nodes on the left of node i in the tree.

    //Post - order dfs the tree(node, right, left),
    //update res[i] to the max height before node i in postorder,
    //can cover all nodes on the right of node i in the tree.

    //int preh[100001], posth[100001], maxh;
    //vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    //    maxh = 0; pre(root, 0);
    //    maxh = 0; post(root, 0);
    //    vector<int> res;
    //    for (int q : queries)
    //        res.push_back(max(preh[q], posth[q]));
    //    return res;
    //}
    //
    //void pre(TreeNode* root, int h) {
    //    if (!root) return;
    //    preh[root->val] = maxh;
    //    maxh = max(maxh, h);
    //    pre(root->left, h + 1);
    //    pre(root->right, h + 1);
    //}
    //
    //void post(TreeNode* root, int h) {
    //    if (!root) return;
    //    posth[root->val] = maxh;
    //    maxh = max(maxh, h);
    //    post(root->right, h + 1);
    //    post(root->left, h + 1);
    //}


    //int seen[100001], maxh;
    //vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    //    maxh = 0; dfs(root, 0);
    //    maxh = 0; dfs(root, 0);
    //    vector<int> res;
    //    for (int q : queries)
    //        res.push_back(seen[q]);
    //    return res;
    //}
    //
    //void dfs(TreeNode* root, int h) {
    //    if (!root) return;
    //    seen[root->val] = max(seen[root->val], maxh);
    //    maxh = max(maxh, h);
    //    dfs(root->left, h + 1);
    //    dfs(root->right, h + 1);
    //    swap(root->right, root->left);
    //}



//Runtime549 ms
//Beats
//84.87 %
//Memory153.9 MB
//Beats
//79.20 %

    // 每层的 最深的2种。  节点。
    int arr[100005] = { 0 };
    int arr2[100005] = { 0 };
    vector<int> lt2458a(TreeNode* root, vector<int>& queries)
    {
        vector<pair<int, int>> vp;
        
        int totaldep = dfsa1(root, vp, 0);

        int sz1 = queries.size();

        vector<int> vi(sz1, totaldep - 1);

        for (int i = 0; i < sz1; ++i)
        {
            int t2 = arr[queries[i]];   // level
            int t3 = arr2[queries[i]];  // depth of subtree

            if (t3 == vp[t2].first)
            {
                vi[i] -= (t3 - vp[t2].second);
            }
        }

        return vi;
    }

    int dfsa1(TreeNode* node, vector<pair<int, int>>& vp, int dep)
    {
        if (node == nullptr)
            return 0;

        if (dep >= vp.size())
            vp.push_back(make_pair(0, 0));

        int ans = 0;

        ans = dfsa1(node->left, vp, dep + 1);

        ans = max(ans, dfsa1(node->right, vp, dep + 1));

        ans += 1;

        arr[node->val] = dep;
        arr2[node->val] = ans;

        if (ans >= vp[dep].first)
        {
            vp[dep].second = vp[dep].first;

            vp[dep].first = ans;
        }
        else if (ans > vp[dep].second)
        {
            vp[dep].second = ans;
        }

        return ans;
    }


};

int main()
{

    LT2458 lt;

    int arr[] = { 5,8,9,2,1,3,7,4,6 };
    myvi v = { 3,2,4,8 };


    TreeNode* r = convert2TreeNode(arr);

    myvi v2 = lt.lt2458a(r, v);

    showVectorInt(v2);

    return 0;
}
