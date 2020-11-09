
#include "../header/myheader.h"

class LT1161
{
public:

// D D

//  while (!q.empty()) {
//      vector<TreeNode*> q1;
//      int sum = 0;
//      ++lvl;
//      for (auto n : q) {
//          sum += n->val;
//          if (n->left != nullptr)
//              q1.push_back(n->left);
//          if (n->right != nullptr)
//              q1.push_back(n->right);
//      }
//      msum_lvl = sum < msum ? msum_lvl : lvl;
//      msum = max(sum, msum);
//      swap(q, q1);
//  }
// 好像这种快？ queue的实现不清楚，不知道是Array 还是 Linked。


//vector<int> sums;
//void dfs(TreeNode* r, size_t lvl) {
//  if (r != nullptr) {
//    sums.resize(max(sums.size(), lvl));
//    sums[lvl - 1] += r->val;
//    dfs(r->left, lvl + 1);
//    dfs(r->right, lvl + 1);
//  }
//}


//Runtime: 236 ms, faster than 91.58% of C++ online submissions for Maximum Level Sum of a Binary Tree.
//Memory Usage: 108.8 MB, less than 8.54% of C++ online submissions for Maximum Level Sum of a Binary Tree.
    int lt1161a(TreeNode* root)
    {
        queue<TreeNode*> que2;
        que2.push(root);
        int lv = 1;
        int mxsum = INT_MIN;
        int ans = 1;
        while (!que2.empty())
        {
            int sz1 = que2.size();
            int sm = 0;
            while (sz1-- > 0)
            {
                TreeNode* n = que2.front();
                que2.pop();
                sm += n->val;
                if (n->left)
                    que2.push(n->left);
                if (n->right)
                    que2.push(n->right);
            }
            if (sm > mxsum)
            {
                mxsum = sm;
                ans = lv;
            }
            lv++;
        }
        return ans;
    }

};

int main()
{

    int arr[] = {1,7,0,7,-8};
    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 3);

    LT1161 lt;

    cout<<lt.lt1161a(r)<<endl;

    return 0;
}
