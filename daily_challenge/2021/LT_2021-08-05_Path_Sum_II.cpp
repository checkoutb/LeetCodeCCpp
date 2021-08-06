
#include "../../header/myheader.h"

class LT
{
public:

// D D

//Recursively, BFS+queue, DFS+stack




// AC
    vector<vector<int>> lta(TreeNode* root, int targetSum)
    {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        vector<int> path;
        dfsa1(ans, root, targetSum, 0, path);
        return ans;
    }

    void dfsa1(vector<vector<int>>& ans, TreeNode* node, int target, int sum2, vector<int>& path)
    {
        sum2 += node->val;
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            #ifdef __test
            cout<<target<<", "<<sum2<<endl;
            #endif // __test
            if (target == sum2)
            {
                ans.push_back(path);
            }
            path.pop_back();
            return;
        }
        if (node->left != nullptr)
            dfsa1(ans, node->left, target, sum2, path);
        if (node->right != nullptr)
            dfsa1(ans, node->right, target, sum2, path);

        path.pop_back();

//        if (node == nullptr)
//        {
//            if (sum2 == target)
//            {
//                ans.push_back(path);
//            }
//            return;
//        }
//        dfsa1()
    }

};

int main()
{

//    myvi v = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1};
    int v[] = {5,4,8,11,-1,13,4,7,2,-1,-1,-1,-1,5,1};
    int tar = 22;

    LT lt;

    TreeNode* r = convert2TreeNode(v);
    showTreeNode(r, 5);

    myvvi vv = lt.lta(r, tar);

    cout<<vv.size()<<endl;
    for (myvi& vi : vv)
    {
        showVectorInt(vi);
    }

    deleteTreeNode(r);

    return 0;
}
