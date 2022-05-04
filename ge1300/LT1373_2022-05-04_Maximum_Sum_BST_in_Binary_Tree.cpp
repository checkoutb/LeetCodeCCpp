
#include "../header/myheader.h"

class LT1373
{
public:

// D D


//    int max_sum = 0;
//    array<int, 3> dfs(TreeNode* n) {
//        auto l = n->left ? dfs(n->left) : array<int, 3>{0, n->val, n->val - 1};
//        auto r = n->right ? dfs(n->right) : array<int, 3>{0, n->val + 1, n->val};
//        if (l[2] < n->val && n->val < r[1]) {
//            max_sum = max(max_sum, n->val + l[0] + r[0]);
//            return {n->val + l[0] + r[0], l[1], r[2]};
//        }
//        return {0, INT_MIN, INT_MAX};
//    }

//    struct BSTNode{
//        int mn;
//        int mx;
//        int sum;
//        bool isBST;
//    };
//    BSTNode findBST(TreeNode* root,int &res){
//        if(!root){
//            return {INT_MAX,INT_MIN,0,true};
//        }



//Runtime: 242 ms, faster than 47.81% of C++ online submissions for Maximum Sum BST in Binary Tree.
//Memory Usage: 124 MB, less than 30.82% of C++ online submissions for Maximum Sum BST in Binary Tree.
// 看起来，好像不难。。。不过不懂 Example 3：全负数为什么 说是 empty BST
    int lt1373a(TreeNode* root)
    {
        int ans = 0;
        dfsa1(root, ans);
        return ans;
    }

    // <isBST, min, max, sum>
    std::tuple<bool, int, int, int> dfsa1(TreeNode* node, int& ans)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            ans = std::max(ans, node->val);
            return std::make_tuple(true, node->val, node->val, node->val);
        }
        if (node->left == nullptr)
        {
            tuple<bool, int, int, int> t2 = dfsa1(node->right, ans);
            bool b2 = std::get<bool>(t2);
            int mn = std::get<1>(t2);
            int mx = std::get<2>(t2);
            int sum2 = std::get<3>(t2);
            if (b2 && (mn > node->val))
            {
                sum2 += node->val;
                ans = max(ans, sum2);
                return std::make_tuple(true, node->val, mx, sum2);
            }
            else
            {
                return std::make_tuple(false, -1, -1, -1);
            }
        }
        if (node->right == nullptr)
        {
            bool b2;
            int mn;
            int mx;
            int sum2;
            std::tie(b2, mn, mx, sum2) = dfsa1(node->left, ans);
            if (b2 && (mx < node->val))
            {
                sum2 += node->val;
                ans = max(ans, sum2);
                return make_tuple(true, mn, node->val, sum2);
            }
            else
            {
                return make_tuple(false, -1, -1, -1);
            }
        }
        tuple<bool, int, int, int> t2 = dfsa1(node->left, ans);
        tuple<bool, int, int, int> t3 = dfsa1(node->right, ans);

        bool b2 = std::get<0>(t2);
        bool b3 = std::get<bool>(t3);
        if (b2 && b3)
        {
            int mxl = std::get<2>(t2);
            int mnr = std::get<1>(t3);
            if ((mxl < node->val) && (node->val < mnr))
            {
                int sum3 = node->val + std::get<3>(t2) + std::get<3>(t3);
                ans = max(ans, sum3);
                return std::make_tuple(true, std::get<1>(t2), std::get<2>(t3), sum3);
            }
        }
        return make_tuple(false, -1, -1, -1);
    }

};

int main()
{

    LT1373 lt;

//    int arr[] = {1,4,3,2,4,2,5,-1,-1,-1,-1,-1,-1,4,6};
//    int arr[]{4,3,-1,1,2};
    int arr[]{-4,-2,-5};

    TreeNode* r = convert2TreeNode(arr);
    showTreeNode(r, 5);

    cout<<lt.lt1373a(r)<<endl;

    deleteTreeNode(r);

    return 0;
}
