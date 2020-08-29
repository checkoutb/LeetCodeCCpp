
#include "../header/myheader.h"

class LT0863
{
public:

// D D
// ... 都很长。。。



//Runtime: 4 ms, faster than 94.46% of C++ online submissions for All Nodes Distance K in Binary Tree.
//Memory Usage: 12.7 MB, less than 72.29% of C++ online submissions for All Nodes Distance K in Binary Tree.
    vector<int> ans;
    vector<int> lt0863a(TreeNode* root, TreeNode* target, int K)
    {
        dfsa1(root, target->val, K, -1);

        return ans;
    }

    int dfsa1(TreeNode* n, int val, int k, int dis)
    {
        if (n == nullptr)
            return dis;
        int oriDis = dis;
        if (n->val == val)
        {
            oriDis = 0;
            dis = 0;
        }
        bool come4Left = false;
        if (dis == -1)
        {
            dis = dfsa1(n->left, val, k, dis);
            come4Left = true;
        }
        if (dis == -1)
        {
            dis = dfsa1(n->right, val, k, dis);
            come4Left = false;
        }
        if (dis == -1)
            return -1;

        if (oriDis == -1)
        {
            if (come4Left)
            {
                dfsa1(n->right, val, k, dis + 1);
            }
            else
            {
                dfsa1(n->left, val, k , dis + 1);
            }
        }
        else
        {
            dfsa1(n->left, val, k, dis + 1);
            dfsa1(n->right, val, k, dis + 1);
        }
        #ifdef __test
        cout<<dis<<", "<<k<<", "<<n->val<<endl;
        #endif // __test
        if (dis == k)
            ans.push_back(n->val);
        return dis + 1;
    }

};

int main()
{

    int arr[] = {3,5,1,6,2,0,8,-1,-1,7,4};
    int t = 1;
    int k = 3;

    TreeNode* r = convert2TreeNode(arr);
    TreeNode* tar = new TreeNode(t);
    showTreeNode(r, 4);
    cout<<"\n========\n";

    LT0863 lt;

    vector<int> v = lt.lt0863a(r, tar, k);

    for_each(v.begin(), v.end(), fun_cout);
    cout<<endl;

    destory(r);
    destory(tar);

    return 0;
}
