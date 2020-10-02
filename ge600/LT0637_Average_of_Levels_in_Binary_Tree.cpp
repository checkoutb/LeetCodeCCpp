
#include "../header/myheader.h"

class LT0637
{
public:


// D D

//        while(!q.empty()) {
//            long temp=0;
//            int s=q.size();
//            for(int i=0;i<s;i++) {
//                TreeNode* t=q.front();

// bfs, level-order.



//Runtime: 32 ms, faster than 22.48% of C++ online submissions for Average of Levels in Binary Tree.
//Memory Usage: 22.9 MB, less than 20.75% of C++ online submissions for Average of Levels in Binary Tree.
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double> ans;
        vector<int> cnt;
        dfsa1(root, 0, cnt, ans);
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] /= cnt[i];
        }
        return ans;
    }

    void dfsa1(TreeNode* node, int lv, vector<int>& cnt, vector<double>& ans)
    {
        if (node == nullptr)
            return;
        if (ans.size() <= lv)
        {
            ans.push_back(0);
            cnt.push_back(0);
        }
        ans[lv] += node->val;
        cnt[lv]++;
        dfsa1(node->left, lv + 1, cnt, ans);
        dfsa1(node->right, lv + 1, cnt, ans);
    }

};

int main()
{

    int arr[] = {3,9,20,-1,-1,15,7};

    TreeNode* n = convert2TreeNode(arr);

    LT0637 lt;

    vector<double> v = lt.averageOfLevels(n);

    deleteTreeNode(n);

    for (double d : v)
    {
        cout<<d<<", ";
    }
    cout<<endl;

    return 0;
}
