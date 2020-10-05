
#include "../header/myheader.h"

class LT0687
{
public:

// D D

// chabuduo. 就是dfs的 else if， 可以 if (l==val){} if (r==val){}  ans=max(ans,ll+rl),return max(ll,rl)


//Runtime: 192 ms, faster than 61.58% of C++ online submissions for Longest Univalue Path.
//Memory Usage: 73 MB, less than 5.09% of C++ online submissions for Longest Univalue Path.
    int lt0687a(TreeNode* root)
    {
        int ans = 0;
        ans = max(ans, dfsa1(root, ans).second);
        return ans - 1;
    }

    // val, node.size
    pair<int, int> dfsa1(TreeNode* node, int& ans)
    {
        if (node == nullptr)
            return {INT_MIN, 1};        // 1 for root==nullptr
        pair<int, int> l = dfsa1(node->left, ans);
        pair<int, int> r = dfsa1(node->right, ans);
        if (l.first == node->val && r.first == node->val)
        {
            ans = max(ans, l.second + r.second + 1);
            return {l.first, max(l.second + 1, r.second + 1)};
        }
        else if (l.first == node->val)
        {
            ans = max(ans, l.second + 1);
            return {l.first, l.second + 1};
        }
        else if (r.first == node->val)
        {
            ans = max(ans, r.second + 1);
            return {r.first, r.second + 1};
        }
        return {node->val, 1};
    }

};

int main()
{

//    int arr[] = {5,4,5,1,1,-1,5};
//    int arr[] = {1,4,5,4,4,-1,5};
    int arr[] = {1};

    TreeNode* r = convert2TreeNode(arr);
    LT0687 lt;

    cout<<lt.lt0687a(r)<<endl;
    deleteTreeNode(r);
    return 0;
}
