
#include "../header/myheader.h"

class LT2265
{
public:

// D D


//    int func(TreeNode *root,int &ans,int &nums)
//    {
//        if(root == NULL) return 0;
//        int numNodes = 1,sum = root->val;
//        sum += func(root->left,ans, numNodes);
//        sum += func(root->right,ans,numNodes);
//        nums+=numNodes;
//        if(root->val == (sum/numNodes)) ans++;
//        //cout<<numNodes<<" "<<sum<<
//        return sum;
//    }


//    pair<int, int> count(TreeNode *node, int *result) {
//        if (!node) return {0, 0};
//
//        auto [lsum, lcount] = count(node->left, result);
//        auto [rsum, rcount] = count(node->right, result);
//        int sum = lsum + rsum + node->val;
//        int count = lcount + rcount + 1;
//        if (sum / count == node->val) {
//            ++(*result);
//        }
//        return {sum, count};



//    array<int, 3> dfs(TreeNode* n) {
//        if (n == nullptr)
//            return {0, 0, 0};
//        auto p1 = dfs(n->left), p2 = dfs(n->right);
//        int sum = p1[0] + p2[0] + n->val, count = 1 + p1[1] + p2[1];
//        return {sum, count, p1[2] + p2[2] + (n->val == sum / count)};
//    }
//    int averageOfSubtree(TreeNode* root) {
//        return dfs(root)[2];
//    }
// haha.




//Runtime: 14 ms, faster than 49.23% of C++ online submissions for Count Nodes Equal to Average of Subtree.
//Memory Usage: 12 MB, less than 43.64% of C++ online submissions for Count Nodes Equal to Average of Subtree.
    int lt2265a(TreeNode* root)
    {
        return std::get<2>(dfsa1(root));
    }

    // sum, node count, ans
    tuple<int, int, int> dfsa1(TreeNode* node)
    {
        if (node == nullptr)
            return std::make_tuple(0, 0, 0);

        tuple<int, int, int> t2 = dfsa1(node->left);
        tuple<int, int, int> t3 = dfsa1(node->right);

        int sum2 = std::get<0>(t2) + std::get<0>(t3) + node->val;
        int cnt = std::get<1>(t2) + std::get<1>(t3) + 1;
        int ans = std::get<2>(t2) + std::get<2>(t3) + ((sum2 / cnt) == node->val);

        return std::tuple<int, int, int>{sum2, cnt, ans};
    }

};

int main()
{

    LT2265 lt;

    int arr[] = {4,8,5,0,1,6};

    TreeNode* r = convert2TreeNode(arr);

    showTreeNode(r, 4);

    cout<<lt.lt2265a(r)<<endl;

    deleteTreeNode(r);

    return 0;
}
