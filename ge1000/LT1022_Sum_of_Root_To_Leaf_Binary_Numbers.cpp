
#include "../header/myheader.h"

class LT1022
{
public:


// D D

//    int sumRootToLeaf(TreeNode* root, int val = 0) {
//        if (!root) return 0;
//        val = (val * 2 + root->val);
//        return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val));
//    }

//val = val << 1 | root.val;

// ... vector<int>.....无意义。。


//Runtime: 8 ms, faster than 78.85% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
//Memory Usage: 17.3 MB, less than 5.36% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
    int lt1022a(TreeNode* root)
    {
        vector<int> v;
        int ans = dfsa1(root, v);
        return ans;
    }

    int dfsa1(TreeNode* node, vector<int>& v)
    {
        if (node == nullptr)
            return 0;
        if (node->left == nullptr && node->right == nullptr)
        {
            int t = 0;
            for (int i = 0; i < v.size(); i++)
            {
                t *= 2;
                t += v[i];
            }
            t *= 2;
            t += node->val;
            return t;
        }
        v.push_back(node->val);
        int ans = dfsa1(node->left, v);
        ans += dfsa1(node->right, v);
        v.pop_back();
        return ans;
    }

};

int main()
{

//    int arr[] = {1,0,1,0,1,0,1};
    int arr[] = {1,1};
    TreeNode* n = convert2TreeNode(arr);

    showTreeNode(n, 4);

    LT1022 lt;

    cout<<lt.lt1022a(n)<<endl;

    return 0;
}
