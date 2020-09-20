
#include "../header/myheader.h"

class LT0563
{
public:


// D D
//pair<int, int> find(TreeNode* root) {
//    // pair <sum, tilt>
//    if (root==NULL) return {0,0};
//    pair<int,int> L=find(root->left);
//    pair<int,int> R=find(root->right);
//    int sum=L.first+R.first+root->val;
//    int tiltSum=L.second+R.second+abs(L.first-R.first);
//    return {sum, tiltSum};
//}



//Runtime: 20 ms, faster than 96.79% of C++ online submissions for Binary Tree Tilt.
//Memory Usage: 23.9 MB, less than 43.26% of C++ online submissions for Binary Tree Tilt.
    int lt0563a(TreeNode* root)
    {
        int ans{0};
        dfsa1(ans, root);
        return ans;
    }

    int dfsa1(int& ans, TreeNode* node)
    {
        if (node == nullptr)
            return 0;
        int sl = dfsa1(ans, node->left);
        int sr = dfsa1(ans, node->right);
        ans += std::abs(sl - sr);
        return sl + sr + node->val;
    }

};

int main()
{

    LT0563 lt;


    return 0;
}
