
#include "../header/myheader.h"

class LT0894
{
public:


// D D
//    unordered_map<int, vector<TreeNode*>> dp;
// memo...
// 先把1 到 N-2的可能全部计算出来。


//Runtime: 112 ms, faster than 33.15% of C++ online submissions for All Possible Full Binary Trees.
//Memory Usage: 27.5 MB, less than 36.43% of C++ online submissions for All Possible Full Binary Trees.
    vector<TreeNode*> lt0894a(int N)
    {
        vector<TreeNode*> ans;
        if (N % 2 == 0)
            return ans;
        ans = dfsa2(N);
        return ans;
    }

    vector<TreeNode*> dfsa2(int n)
    {
        vector<TreeNode*> ans;
        n--;
        int add = 2;
        for (int i = 1; i < n; i += 2)
        {
            vector<TreeNode*> left = dfsa2(i);
            vector<TreeNode*> right = dfsa2(n - i);
            for (TreeNode* l : left)
            {
                for (TreeNode* r : right)
                {
                    TreeNode* n = new TreeNode(0);
                    n->left = l;
                    n->right = r;
                    ans.push_back(n);
                }
            }
        }
        if (n == 0)     // after n--;
            ans.push_back(new TreeNode(0));
        return ans;
    }

    // 自顶向下不行，return的信息的不够。
//    int dfsa1(TreeNode* node, int remain, vector<TreeNode>& ans)
//    {
//        if (remain == 0)
//        {
//            ans.push_back(copya1(ans[0]));
//            return -1;
//        }
//
//
//    }
//
//    TreeNode* copya1(TreeNode* node)
//    {
//
//    }
};

int main()
{

    int n = 7;

    LT0894 lt;

    vector<TreeNode*> ans = lt.lt0894a(n);


    for(TreeNode* p : ans)
    {
        showTreeNode(p, 3);
        cout<<"=============================="<<endl;
    }
    cout<<"sz: "<<ans.size()<<endl;

    return 0;
}
